import * as http from 'http';
import * as url from 'url';
import * as fs from 'fs';
import * as path from 'path';
import * as socketio from 'socket.io';

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
		uri = "/html/connections.html"

	const fname = path.join(process.cwd(), uri);

	fs.exists(fname, (exists) =>
	{
		if (exists)
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
		else
		{
			console.log("Petición inválida: " + uri);
			response.writeHead(200, {"Content-Type": "text/plain"});
			response.write("404 Not Found\n");
			response.end();
		}
	});
});

httpServer.listen(8080);

const io = new socketio.Server().listen(httpServer);
const allClients = new Array();

io.sockets.on('connection', (client) =>
{
	allClients.push({
		address: client.request.connection.remoteAddress,
		port:    client.request.connection.remotePort,
	});

	console.log(
		"New connection from " + client.request.connection.remoteAddress +
		":" + client.request.connection.remotePort
	);

	io.sockets.emit('all-connections', allClients);

	client.on('output-evt', (data) =>
	{
		client.emit('output-evt', "¡Hola, Cliente!");
	});

	client.on('disconnect', () =>
	{
		const index = allClients.indexOf(client.request.connection.remoteAddress);

		if (index != -1)
		{
			allClients.splice(index, 1);
			io.sockets.emit('all-connections', allClients);
		}

		console.log(
			"El usuario " + client.request.connection.remoteAddress +
			" se ha desconectado."
		);
	});
});

console.log("Servicio Socket.io iniciado");
