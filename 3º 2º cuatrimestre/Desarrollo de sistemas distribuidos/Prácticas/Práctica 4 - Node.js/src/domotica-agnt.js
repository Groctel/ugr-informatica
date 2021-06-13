// import * as $ from '/node_modules/jquery/dist/jquery.min.js';
// import * as io from '/socket.io/socket.io.js';
import '/node_modules/jquery/dist/jquery.min.js';
import '/socket.io/socket.io.js';

const serviceURL = document.URL.substring(0, document.URL.lastIndexOf("/"));
const socket     = io.connect(serviceURL);

let user_ac       = false;
let user_blinds   = false;
let user_purifier = false;

function evalSystems(event)
{
	if (event.name === "Luminosity")
	{
		if (event.value > 80 && $('#persianas').text() === "abiertas")
		{
			socket.emit('system-status', {name: 'Blinds', value: 'closed'});
			socket.emit('agent-alert', {name: 'Blinds', value: 'closed', trigger: event.value});
			user_blinds = false;
		}
		else if (event.value < 70 && $('#persianas').text() === "cerradas" && !user_blinds)
		{
			socket.emit('system-status', {name: 'Blinds', value: 'open'});
		}
	}
	else if (event.name === "Humidity")
	{
		if (event.value > 65 && $('#purificador').text() === "apagado")
		{
			socket.emit('system-status', {name: 'Purifier', value: 'on'});
			socket.emit('agent-alert', {name: 'Purifier', value: 'on', trigger: event.value});
			user_purifier = false;
		}
		else if (event.value < 15 && $('#purificador').text() === "encendido" && !user_purifier)
		{
			socket.emit('system-status', {name: 'Purifier', value: 'off'});
		}
	}
	else if (event.name === "Temperature")
	{
		if (event.value > 45 && $('#aire').text() === "apagado")
		{
			socket.emit('system-status', {name: 'AC', value: 'on'});
			socket.emit('agent-alert', {name: 'AC', value: 'on', trigger: event.value});
			user_ac = false;
		}
		else if (event.value < 35 && $('#aire').text() === "encendido" && !user_ac)
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

	socket.on('get-action', (event) =>
	{
		console.log(event);
		if (event.name === "AC")
			user_ac = (event.value === 'on');
		else if (event.name === "Blinds")
			user_blinds = (event.value === 'closed');
		else if (event.name === "Purifier")
			user_purifier = (event.value === 'on');
	});

	socket.on('update-sensors', (event) =>
	{
		if (event.name === "Luminosity")
			$('#lum_num').html(event.value);
		else if (event.name === "Humidity")
			$('#hum_num').html(event.value);
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
		else if (event.name === "Purifier")
		{
			const status = $('#purificador');

			if (event.value === "on")
				status.text("encendido");
			else
				status.text("apagado");
		}
	});
}

$(() =>
{
	initSocket();
});
