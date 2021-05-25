// import * as $ from '/node_modules/jquery/dist/jquery.min.js';
// import * as io from '/socket.io/socket.io.js';
import '/node_modules/jquery/dist/jquery.min.js';
import '/socket.io/socket.io.js';

const serviceURL = document.URL.substring(0, document.URL.lastIndexOf("/"));
const socket     = io.connect(serviceURL);

function initLum ()
{
	const lum_bar = $('#lum_bar');

	lum_bar.on('input', function ()
	{
		socket.emit('sensor-status', {name: 'Luminosity', value: Number(this.value)});
	});
	$('#lum_num').html(lum_bar.attr('value'));
}

function initSocket ()
{
	socket.on('connect', () =>
	{
		socket.emit('connection-status', 'env');
	});

	socket.on('update-sensors', (event) =>
	{
		if (event.name === "Luminosity")
			$('#lum_num').html(event.value);
		else if (event.name === "Temperature")
			$('#temp_num').html(event.value);
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

function initTemp ()
{
	const temp_bar = $('#temp_bar');

	temp_bar.on('input', function ()
	{
		socket.emit('sensor-status', {name: 'Temperature', value: Number(this.value)});
	});
	$('#temp_num').html(temp_bar.attr('value'));
}

$(() =>
{
	initLum();
	initTemp();
	initSocket();
});
