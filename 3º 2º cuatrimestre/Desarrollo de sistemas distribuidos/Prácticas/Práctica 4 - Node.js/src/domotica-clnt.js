// import * as $ from '/node_modules/jquery/dist/jquery.min.js';
// import * as io from '/socket.io/socket.io.js';
import '/node_modules/jquery/dist/jquery.min.js';
import '/socket.io/socket.io.js';

const serviceURL = document.URL.substring(0, document.URL.lastIndexOf("/"));
const socket     = io.connect(serviceURL);

function updateHistory (event)
{
	const history = $('#historial');

	history
		.append(
			event.name  + ": " +
			event.value + " (" +
			event.date  + ")<br>"
		)
		.scrollTop(history.prop('scrollHeight'));
}

function initAC ()
{
	const btn = $('#air_btn');

	btn.on('click', () =>
	{
		if (btn.text() === "Encender")
			socket.emit('system-status', {name: 'AC', value: 'on'});
		else
			socket.emit('system-status', {name: 'AC', value: 'off'});
	});
}

function initBlinds ()
{
	const btn = $('#per_btn');

	btn.on('click', () =>
	{
		if (btn.text() === "Cerrar")
			socket.emit('system-status', {name: 'Blinds', value: 'closed'});
		else
			socket.emit('system-status', {name: 'Blinds', value: 'open'});
	});
}

function initSocket ()
{
	socket.on('connect', () =>
	{
		socket.emit('connection-status', 'clnt');
	});

	socket.on('update-sensors', (event) =>
	{
		if (event.name === "Luminosity")
			$('#lum_num').html(event.value);
		else if (event.name === "Temperature")
			$('#temp_num').html(event.value);

		updateHistory(event);
	});

	socket.on('get-alert', (content) =>
	{
		if (content.name === 'AC')
			alert("Encendido el aire acondicionado al detectar " + content.trigger + "ºC.");
		else if (content.name === 'Blinds')
			alert("Cerradas las persinas al detectar " + content.trigger + "% de luz.");
	});

	socket.on('update-systems', (event) =>
	{
		if (event.name === "AC")
		{
			const btn    = $('#air_btn');
			const status = $('#aire');

			if (event.value === "on")
			{
				btn.html("Apagar");
				status.text("encendido");
			}
			else
			{
				btn.html("Encender");
				status.text("apagado");
			}
		}
		else if (event.name === "Blinds")
		{
			const btn    = $('#per_btn');
			const status = $('#persianas');

			if (event.value === "open")
			{
				btn.html("Cerrar");
				status.text("abiertas");
			}
			else
			{
				btn.html("Abrir");
				status.text("cerradas");
			}
		}

		updateHistory(event);
	});
}

$(() =>
{
	initAC();
	initBlinds();
	initSocket();
});
