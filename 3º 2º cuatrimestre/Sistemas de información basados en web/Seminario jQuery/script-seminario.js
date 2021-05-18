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

$(() =>
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
	// Esconder todos los elementos de la clase seccion:
		// $('.seccion').hide()
	// Cambiar el color de todos los <span> incluidos en un <p> a magenta:
		// $('p span').css({color: 'magenta'})
	// Cambiar el color de todos los elementos a verde:
		// $('*').css({color: 'green'})
	// Esconder todos los elementos con una propiedad `type=*`:
		// $('[type]').hide()
	// Cambiar el color de cada tercer elemento de la lista a r:ojo
		// $('ul li:nth-child(3n)').css({color: 'red'})

	/*                       _
	 *   _____   _____ _ __ | |_ ___  ___
	 *  / _ \ \ / / _ \ '_ \| __/ _ \/ __|
	 * |  __/\ V /  __/ | | | || (_) \__ \
	 *  \___| \_/ \___|_| |_|\__\___/|___/
	 *
	 * JQuery permite capturar eventos en el callback de una función y ejecutar
	 * acciones cuando éste se dispara. Por ejemplo, la página demo tiene un
	 * botón pulsable y aquí utilizamos la función `click` para capturar el
	 * evento (que realmente es una secuencia de `mousedown` y `mouseup`) y
	 * ejecutamos la función del callback al pulsar sobre él.
	 */

	$('button').click((event) =>
	{
		// DESCOMENTA ESTAS LÍNEAS PARA PROBAR LAS FUNCIONES
		// -------------------------------------------------

		// Ocultar y mostrar con animación el bloque animado:
			// $('#bloque_animado').slideToggle(300)
		// Mostrar una alerta en pantalla con la posición del ratón al pulsar:
			// alert(event.clientX + " " + event.clientY)

		// Animar el movimiento del cuadrado:
		// Podemos encadenar varias animaciones encadenando llamadas a JQuery, ya
		// que cada función devuelve el objeto sobre el que se aplica.
			/*
			$('#cuadrado')
				.animate({right: '55%'})
				.animate({top:   '700px'})
				.animate({right: '32%'})
				.animate({top:   '550px'})
			*/

		/*                        _             _            _    __
		 *  _ __ ___   __ _ _ __ (_)_ __  _   _| | __ _  ___(_) _/_/ _ __
		 * | '_ ` _ \ / _` | '_ \| | '_ \| | | | |/ _` |/ __| |/ _ \| '_ \
		 * | | | | | | (_| | | | | | |_) | |_| | | (_| | (__| | (_) | | | |
		 * |_| |_| |_|\__,_|_| |_|_| .__/ \__,_|_|\__,_|\___|_|\___/|_| |_|
		 *                         |_|
		 *      _      _   ____   ___  __  __
		 *   __| | ___| | |  _ \ / _ \|  \/  |
		 *  / _` |/ _ \ | | | | | | | | |\/| |
		 * | (_| |  __/ | | |_| | |_| | |  | |
		 *  \__,_|\___|_| |____/ \___/|_|  |_|
		 *
		 * Aunque el DOM puede manipularse en cualquier momento del script, los
		 * eventos son el lugar idóneo para demostar su funcionalidad.
		 *
		 * JQuery nos permite modificar cualquier propiedad de cualquier elemento
		 * de la web con la que estamos trabajando. Podemos modificar las clases
		 * de los objetos, eliminarlos, modificar el CSS, el HTML... Cualquier
		 * cosa que se nos ocurra. Algunas de estas funcionalidades tendrás que
		 * corroborarlas con el depurador de tu navegador.
		 */

		// DESCOMENTA ESTAS LÍNEAS PARA PROBAR LAS FUNCIONES
		// -------------------------------------------------

		// Agregar la clase `'titulo_chulo'` a todos los `h1`:
			// $('h1').toggleClass('titulo_chulo')
		// Podar los `h1` del DOM hasta recargar la página:
			// $('h1').remove()
		// Cambiar el HTML del título por otro
			 // $('#titulo').html('Aguante Telegram');
	})

	/*                       _                  _       _     _
	 *   _____   _____ _ __ | |_ ___  ___    __| | ___ | |__ | | ___  ___
	 *  / _ \ \ / / _ \ '_ \| __/ _ \/ __|  / _` |/ _ \| '_ \| |/ _ \/ __|
	 * |  __/\ V /  __/ | | | || (_) \__ \ | (_| | (_) | |_) | |  __/\__ \
	 *  \___| \_/ \___|_| |_|\__\___/|___/  \__,_|\___/|_.__/|_|\___||___/
	 *
	 * Algunos eventos, como `hover`, pueden recibir una o dos funciones para
	 * ejecutar en la entrada y la salida al evento. En este caso, usamos la
	 * primera función para definir el comportamiento de la página al iniciar el
	 * evento (poner el ratón encima del elemento) y la segunda, para el de
	 * finalizar el evento (quitar el ratón de encima del elemento). Con una sola
	 * función se ejecutaría ésta en ambos casos.
	 *
	 * Observa que estamos utilizando `this` para referirnos al objeto que hemos
	 * seleccionado. En este caso no podemos utilizar una función flecha porque
	 * ésta capturaría el `this` del script, no del objeto devuelto por el
	 * selector, que es el que nos interesa.
	 */

	// DESCOMENTA ESTAS LÍNEAS PARA PROBAR LAS FUNCIONES
	// -------------------------------------------------

	/*
	$('.seccion').hover(
		function ()
		{
			$(this).css({color: 'red'})
		},
		function ()
		{
			$(this).css({color: 'blue'})
		}
	)
	*/
})
