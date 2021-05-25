// import * as $ from '/node_modules/jquery/dist/jquery.min.js';
// import * as io from '/socket.io/socket.io.js';
import '/node_modules/jquery/dist/jquery.min.js';
import '/socket.io/socket.io.js';

const serviceURL = document.URL.substring(0, document.URL.lastIndexOf("/"));
const socket     = io.connect(serviceURL);

function evalSystems(event)
{
	if (event.name === "Luminosity")
	{
		if (event.value > 80 && $('#persianas').text() === "abiertas")
		{
			socket.emit('system-status', {name: 'Blinds', value: 'closed'});
			socket.emit('agent-alert', {name: 'Blinds', value: 'closed', trigger: event.value});
		}
		else if (event.value < 70 && $('#persianas').text() === "cerradas")
		{
			socket.emit('system-status', {name: 'Blinds', value: 'open'});
		}
	}
	else if (event.name === "Temperature")
	{
		if (event.value > 45 && $('#aire').text() === "apagado")
		{
			socket.emit('system-status', {name: 'AC', value: 'on'});
			socket.emit('agent-alert', {name: 'AC', value: 'on', trigger: event.value});
		}
		else if (event.value < 35 && $('#aire').text() === "encendido")
		{
			socket.emit('system-status', {name: 'AC', value: 'off'});
		}
	}
}

function initSocket ()
{
	socket.on('connect', () =>
	{
		socket.emit('connection-status', 'agnt');
	});

	socket.on('update-sensors', (event) =>
	{
		if (event.name === "Luminosity")
			$('#lum_num').html(event.value);
		else if (event.name === "Temperature")
			$('#temp_num').html(event.value);

		evalSystems(event);
	});

	socket.on('update-systems', (event) =>
	{
		if (event.name === "AC")
		{
			const status = $('#aire');

			if (event.value === "on")
				status.text("encendido");
			else
				status.text("apagado");
		}
		else if (event.name === "Blinds")
		{
			const status = $('#persianas');

			if (event.value === "open")
				status.text("abiertas");
			else
				status.text("cerradas");
		}
	});
}

$(() =>
{
	initSocket();
});
