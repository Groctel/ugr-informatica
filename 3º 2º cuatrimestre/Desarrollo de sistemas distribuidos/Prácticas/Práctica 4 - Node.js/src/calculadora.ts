import * as http from 'http';

function Calcular (operacion: String, val1: number, val2: number): number | String
{
	if (operacion == "sumar")
		return val1 + val2;
	else if (operacion == "restar")
		return val1 - val2;
	else if (operacion == "multiplicar")
		return val1 * val2;
	else if (operacion == "dividir")
		return val1 / val2;
	else
		return "Error: Par&aacute;metros no v&aacute;lidos";
}

const httpServer = http.createServer((request, response) =>
{
	let uri = request.url;
	let output = "";

	while(uri.indexOf('/') == 0)
		uri = uri.slice(1);

	const params = uri.split("/");

	if (params.length >= 3)
	{
		const val1 = parseFloat(params[1]);
		const val2 = parseFloat(params[2]);
		const result = Calcular(params[0], val1, val2);

		output = result.toString();
	}
	else
	{
		output = "Error: El n&uacute;mero de par&aacute;metros no es v&aacute;lido";

		response.writeHead(200, {"Content-Type": "text/html"});
		response.write(output);
		response.end();
	}
});

httpServer.listen(8080);
console.log("Servicio HTTP iniciado");
