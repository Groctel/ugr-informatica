// https://bulbapedia.bulbagarden.net/wiki/List_of_censored_words_in_Generation_V
const tacos = [
	"bollera",    "culo",       "mamón",      "pollon",
	"cabron",     "follar",     "mamona",     "pollón",
	"cabrón",     "follen",     "marica",     "polvo",
	"cabrona",    "furcia",     "maricon",    "potorro",
	"cabronazo",  "gilipollas", "maricón",    "puta",
	"capulla",    "hijaputa",   "maricona",   "puto",
	"capullo",    "hijo",       "mariconazo", "puton",
	"chichi",     "hijoputa",   "nazi",       "putón",
	"chocho",     "hostia",     "ojete",      "tortillera",
	"cojon",      "joder",      "ostia",      "zorron",
	"cojón",      "jodete",     "pajillero",  "zorrón",
	"cojones",    "jódete",     "pendon",
	"comepollas", "joputa",     "pendón",
	"cono",       "mamada",     "picha",
	"coño",       "mamon",      "polla"
];

let json_comentarios = null;

function AlturaComentarios (comentarios)
{
	const cajas = comentarios.getElementsByTagName('div');
	let altura  = 0;

	for (let i = 0; i < cajas.length; i++)
	{
		if (cajas[i].id === "caja-comentario")
			altura += cajas[i].offsetHeight + 20;
	}

	altura += document.getElementById('form-comentario').offsetHeight + 10;

	return altura;
}

function CargarJSON (ruta)
{
	const xmlhttp = new XMLHttpRequest();
	let json      = null;

	xmlhttp.open("GET", ruta, false);
	xmlhttp.send();

	if (xmlhttp.status == 200)
		json = xmlhttp.responseText;

	return json;
}

function ConstruirComentario (json, indice, contenedor)
{
	let autor           = document.createElement('div');
	let caja_comentario = document.createElement('div');
	let cuerpo          = document.createElement('div');
	let email           = document.createElement('span');
	let fecha           = document.createElement('span');
	let nombre          = document.createElement('span');

	autor.id           = "autor";
	caja_comentario.id = "caja-comentario";
	cuerpo.id          = "cuerpo";
	email.id           = "email";
	fecha.id           = "email";
	nombre.id          = "nombre";

	cuerpo.innerHTML = json[indice].cuerpo;
	nombre.innerHTML = json[indice].nombre;
	email.innerHTML  = json[indice].email;
	fecha.innerHTML  = json[indice].fecha;

	autor.appendChild(nombre);
	autor.appendChild(email);
	autor.appendChild(fecha);

	caja_comentario.appendChild(autor);
	caja_comentario.appendChild(cuerpo);

	contenedor.appendChild(caja_comentario);
}

function CargarComentarios ()
{
	const cajas       = document.getElementById('cajas');
	const comentarios = JSON.parse(json_comentarios);

	cajas.innerHTML = "";

	for (i in comentarios.contenido)
	{
		ConstruirComentario(comentarios.contenido, i, cajas);
	}
}

function AbrirCajaComentarios (comentarios, boton)
{
	if (json_comentarios == null)
		json_comentarios = CargarJSON('/json/comentarios.json');

	CargarComentarios();

	const altura_caja = Math.min(AlturaComentarios(comentarios), 750);

	comentarios.style.height   = altura_caja+"px";
	comentarios.style.overflow = "auto";
	boton.innerHTML            = "Ocultar comentarios";
}

function CerrarCajaComentarios (comentarios, boton)
{
	comentarios.style.height   = "0";
	comentarios.style.overflow = "hidden";
	boton.innerHTML            = "Mostrar comentarios";
}

function BotonComentarios ()
{
	const boton       = document.getElementById('boton-comentarios');
	const comentarios = document.getElementById('comentarios');

	if (boton.innerHTML === "Mostrar comentarios")
		AbrirCajaComentarios(comentarios, boton)
	else
		CerrarCajaComentarios(comentarios, boton);
}

function EmailValido (email)
{
	return (/^.+@.+\..+/.test(email));
}

function IntroducirComentario (nombre, email, cuerpo)
{
	const div_comentarios    = document.getElementById('comentarios');
	const cajas              = document.getElementById('cajas');
	const comentarios        = JSON.parse(json_comentarios);
	const fecha              = new Date();

	let entrada = {
		"nombre": nombre,
		"email": email,
		"fecha": fecha.toLocaleDateString() + " " + fecha.toLocaleTimeString(),
		"cuerpo": cuerpo
	}

	comentarios.contenido.push(entrada);
	json_comentarios = JSON.stringify(comentarios);

	ConstruirComentario(comentarios.contenido, comentarios.contenido.length-1, cajas);

	const altura_comentarios = Math.min(AlturaComentarios(div_comentarios), 750);
	div_comentarios.style.height = altura_comentarios+"px";
}

function AniadirComentario ()
{
	const formulario = document.getElementById('form-comentario');

	const cuerpo = formulario.cuerpo.value;
	const email  = formulario.email.value;
	const nombre = formulario.nombre.value;

	if (!EmailValido(email))
		alert("Introduzca una dirección de correo válida.");
	else
		IntroducirComentario(nombre, email, cuerpo);
}

function OcultarTacosEnDirecto ()
{
	const grawlixes      = "$%#@¡!¿?*+^~"
	const texto          = document.getElementById('form-cuerpo');
	const ultima_palabra = texto.value.split(" ").pop()

	let encontrada = false;

	for (let i = 0; i < tacos.length && !encontrada; i++)
		encontrada = (ultima_palabra === tacos[i]);

	if (encontrada)
	{
		let reemplazo = "";

		for (let i = 0; i < 5; i++)
			reemplazo += grawlixes.charAt(
				Math.floor(Math.random() * grawlixes.length)
			);

		texto.value = texto.value.replace(ultima_palabra, reemplazo);
	}
}

const boton_comentarios = document.getElementById('boton-comentarios');
const form_cuerpo       = document.getElementById('form-cuerpo');

boton_comentarios.addEventListener('click', BotonComentarios);
form_cuerpo.addEventListener('keyup', OcultarTacosEnDirecto);
