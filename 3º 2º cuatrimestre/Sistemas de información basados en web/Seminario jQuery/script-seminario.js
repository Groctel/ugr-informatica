import './node_modules/jquery/dist/jquery.min.js'

/*     __ _ _ __ _ __ __ _ _ __   __ _ _   _  ___
 *    / _` | '__| '__/ _` | '_ \ / _` | | | |/ _ \
 *   | (_| | |  | | | (_| | | | | (_| | |_| |  __/
 *    \__,_|_|  |_|  \__,_|_| |_|\__, |\__,_|\___|
 *                                  |_|
 *
 * La función `$(fn)` indica a JQuery que se espere a ejecutar el cuerpo de la
 * función `fn` hasta que la página esté cargada. `$()` define sus propias
 * condiciones que indican si la página está cargada. En este script, hemos
 * definido nosotros mismo la función que pasamos como argumento dentro de
 * `$()`, aunque podríamos haberlo hecho fuera:
 *
 *     función () { cuerpo }
 *     $(función)
 */

$(function ()
{
	/*              _           _
	 *     ___  ___| | ___  ___| |_ ___  _ __ ___  ___
	 *    / __|/ _ \ |/ _ \/ __| __/ _ \| '__/ _ \/ __|
	 *    \__ \  __/ |  __/ (__| || (_) | | |  __/\__ \
	 *    |___/\___|_|\___|\___|\__\___/|_|  \___||___/
	 *
	 * Los selectores de JQuery nos permiten seleccionar (qué sorpresa) todos los
	 * elementos del DOM que se identifiquen con la misma sintaxis que permite
	 * seleccionar elementos en CSS. Utilizan la sintaxis `$('elemento')` donde
	 * el `elemento` es la sintaxis de CSS a la que nos referimos.
	 *
	 * Los selectores devuelven una lista de todos los elementos que cumplen las
	 * propiedades de selección y nos permiten ejecutar llamadas a la API de
	 * JQuery sobre cada objeto de la lista.
	 */

	// DESCOMENTA ESTAS LÍNEAS PARA PROBAR LAS FUNCIONES
	// -------------------------------------------------

	// Esconder todos los elementos de tipo h1:
		// $('h1').hide()
	// Esconder todos los elementos de la clase titulillo:
		// $('.titulillo').hide()
	// Esconder todos los elementos de la clase titulillo:
		// $('.titulillo').hide()


	// $('.titulillo').css({color: 'green'})
	$('p span').css({color: 'blue'})
	// $('[type]').hide()
	// $('*').css({color: 'green'})
	$('ul li:nth-child(3n)').css({color: 'red'})

	$('button').click(function (event)
	{
		// $('#titulo_gordo').slideToggle(300)
		// $('h3').toggleClass('titulillo')
		// alert(event.clientX + " " + event.clientY)
		// $('h1').remove()

		const cuadrado = $('#cuadrado');

		cuadrado.animate({left: '200px'});
		cuadrado.animate({top:  '200px'});
		cuadrado.animate({left: '0px'});
		cuadrado.animate({top:  '0px'})

		// cuadrado.animate({left: '200px'}).animate({top:  '200px'}).animate({left: '0px'}).animate({top:  '0px'})
	})

	$('h2').hover(
		function  ()
		{
			$(this).css({color: 'blue'})
		},
		function  ()
		{
			$(this).css({color: 'black'})
		}
	)

	// $('#titulo_gordo').hide()
})
