import * as http from 'http';
import * as fs from 'fs';
import * as path from 'path';

const mime_types = {
	'css':  "text/css",
	'html': "text/html",
	'jpeg': "image/jpeg",
	'jpg':  "image/jpg",
	'js':   "text/javascript",
	'png':  "image/png",
	'swf':  "application/x-shockwave-flash",
};

function Calcular (operacion: string, val1: number, val2: number): number | string
{
	if (operacion === "sumar")
		return val1 + val2;
	else if (operacion === "restar")
		return val1 - val2;
	else if (operacion === "multiplicar")
		return val1 * val2;
	else if (operacion === "dividir")
		return val1 / val2;
	else
		return "Error: Par&aacute;metros no v&aacute;lidos";
}

const httpServer = http.createServer((request, response) =>
{
	let uri = request.url;

	if (uri === "/")
		uri = "/html/calculadora-web.html";

	const fname = path.join(process.cwd(), uri);

	fs.stat(fname, (error) =>
	{
		if (error)
		{
			while(uri.indexOf('/') == 0)
				uri = uri.slice(1);

			const params = uri.split("/");

			if (params.length >= 3)
			{
				console.log("Petición REST: " + uri);

				const val1 = parseFloat(params[1]);
				const val2 = parseFloat(params[2]);
				const result = Calcular(params[0], val1, val2);

				response.writeHead(200, {"Content-Type": "text/html"});
				response.write(result.toString());
				response.end();
			}
			else
			{
				response.writeHead(200, {"Content-Type": "text/plain"});
				response.write("404 Not Found\n");
				response.end();
			}
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

httpServer.listen(8080);
console.log("Servicio HTTP iniciado");
