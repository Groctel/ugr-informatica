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

	if (uri === "/")
		uri = "/html/mongo-test.html";

	const fname = path.join(process.cwd(), uri);

	fs.stat(fname, (error) =>
	{
		if (error)
		{
			console.log("Petición inválida: " + uri);
			response.writeHead(200, {"Content-Type": "text/plain"});
			response.write("404 Not Found\n");
			response.end();
		}
		else
		{
			fs.readFile(fname, (err, data) =>
			{
				if (!err)
				{
					const extension = path.extname(fname).split(".")[1];
					const mime_type = mime_types[extension];
					response.writeHead(200, mime_type);
					response.write(data);
					response.end();
				}
				else
				{
					response.writeHead(200, {"Content-Type": "text/plain"});
					response.write("Error de lectura en el fichero " + uri);
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
	const coll_name = "mycoll";

	db.collections((_err, colls) =>
	{
		if (colls.find((item) => { return item.collectionName === coll_name; }))
			db.dropCollection(coll_name);

		db.createCollection(coll_name, (_err, collection) =>
		{
			io.on('connection', (client) =>
			{
				client.emit('my-address', {
					host: client.request.socket.remoteAddress,
					port: client.request.socket.remotePort
				});

				client.on('put', (addr) =>
				{
					collection.insertOne(addr, {});
				});

				client.on('get', (addr) =>
				{
					collection.find({host: addr.host}).toArray((_err, results) =>
					{
						client.emit('get', results);
					});
				});
			});
		});
	});
});

console.log("Servicio MongoDB iniciado.");
