import * as http from 'http';
import * as fs from 'fs';
import * as path from 'path';
import * as socketio from 'socket.io';
import * as mongodb from 'mongodb';

const MongoClient = mongodb.MongoClient;

const mime_types = {
	'css':  "text/css",
	'html': "text/html",
	'jpeg': "image/jpeg",
	'jpg':  "image/jpg",
	'js':   "text/javascript",
	'png':  "image/png",
	'swf':  "application/x-shockwave-flash",
};

const httpServer = http.createServer((request, response) =>
{
	let uri = request.url;

	if (uri === "/agnt")
		uri = "/html/domotica-agnt.html";
	else if (uri === "/env")
		uri = "/html/domotica-env.html";
	else if (uri === "/clnt")
		uri = "/html/domotica-clnt.html";

	const fname = path.join(process.cwd(), uri);

	fs.stat(fname, (error) =>
	{
		if (!error)
		{
			fs.readFile(fname, (err, data) =>
			{
				if (err)
				{
					response.writeHead(200, {"Content-Type": "text/plain"});
					response.write("Error de lectura en el fichero " + uri);
					response.end();
				}
				else
				{
					const extension = path.extname(fname).split(".")[1];
					const mime_type = mime_types[extension];
					response.writeHead(200, {'Content-Type' : mime_type});
					response.write(data);
					response.end();
				}
			});
		}
	});
});

MongoClient.connect("mongodb://localhost:27017/", { useUnifiedTopology: true }, (_err, client) =>
{
	httpServer.listen(8080);
	const io = new socketio.Server().listen(httpServer);
	const db = client.db("mydb");
	const coll_name = "history";

	db.collections((_err, colls) =>
	{
		if (colls.find((item) => { return item.collectionName === coll_name; }))
			db.dropCollection(coll_name);

		db.createCollection(coll_name, (_err, collection) =>
		{
			io.on('connection', (client) =>
			{
				const referer = client.handshake.headers.referer;
				const type    = referer.substring(referer.lastIndexOf("/")+1, referer.length);

				client.on('connection-status', (type) =>
				{
					console.log("Node connected: " + type);
				});

				if (type === 'agnt')
				{
					client.on('agent-alert', (content) =>
					{
						io.sockets.emit('get-alert', content);
					});
				}

				client.on('sensor-status', (sensor) =>
				{
					collection.insertOne({name: sensor.name, value: sensor.value, date: new Date()});
					collection.find().limit(1).sort({$natural:-1}).toArray((_err, results) =>
					{
						io.sockets.emit('update-sensors', results[0]);
					});
				});

				client.on('system-status', (system) =>
				{
					collection.insertOne({name: system.name, value: system.value, date: new Date()});
					collection.find().limit(1).sort({$natural:-1}).toArray((_err, results) =>
					{
						io.sockets.emit('update-systems', results[0]);
					});
				});
			});
		});
	});
});

console.log("HTTP service is up!");
