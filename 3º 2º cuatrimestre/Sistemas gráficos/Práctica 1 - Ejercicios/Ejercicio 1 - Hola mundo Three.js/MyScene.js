import * as THREE from '../libs/three.module.js';
import { GUI } from '../libs/dat.gui.module.js';
import { TrackballControls } from '../libs/TrackballControls.js';
import { MyBox } from './MyBox.js';

/*
 * Definimos las propiedades por defecto de la clase fuera de ella par
 * optimizar la memoria que usamos al crear el objeto.
 */

const SCENE_DEFAULTS = {
	AXES:            true,
	LIGHT_INTENSITY: 0.5,
};

class MyScene extends THREE.Scene
{
	/*
	 * Crea los objetos propios de la escena como hijos de ella y los modelos que
	 * se van a mostrar en la misma. Los objetos que se crean en este método
	 * deben añadirse manualmente. Recibe el lienzo html sobre el que se va a
	 * visualizar.
	 */

	constructor (canvas)
	{
		super();

		this.properties = {
			axes:            SCENE_DEFAULTS.AXES,
			light_intensity: SCENE_DEFAULTS.LIGHT_INTENSITY,

			default: () =>
			{
				this.axes            = SCENE_DEFAULTS.AXES;
				this.light_intensity = SCENE_DEFAULTS.LIGHT_INTENSITY;
			}
		};

		this.renderer = this.constructRenderer(canvas);
		this.gui      = this.constructGUI();
		this.constructLights();
		this.constructCamera();
		this.constructGround();

		this.axes  = new THREE.AxesHelper(5);
		this.model = new MyBox(this.gui);

		this.add(this.axes);
		this.add(this.model);
	}

	/*
	 * Se crea la cámara indicándole el ángulo de visión vertical en grados
	 * sexagesimales, la relación de aspecto, el near y el far. Se indica dónde
	 * se coloca y hacia dónde mira y se inicializan los parámetros de control de
	 * la misma.
	 */

	constructCamera ()
	{
		this.camera = new THREE.PerspectiveCamera(
			45,
			window.innerWidth / window.innerHeight,
			0.1,
			1000
		);

		const look = new THREE.Vector3(0, 0, 0);

		this.camera.position.set(20, 10, 10);
		this.camera.lookAt(look);
		this.add(this.camera);

		this.camera_control = new TrackballControls(
			this.camera,
			this.renderer.domElement
		);

		this.camera_control.rotateSpeed = 5;
		this.camera_control.zoomSpeed   = 2;
		this.camera_control.panSpeed    = 0.5;
		this.camera_control.target      = look;
	}

	/*
	 * Crea el suelo, que es un objeto Mesh con una geometría, un material y una
	 * textura. Como las figuras se crean centradas en el origen, hay que bajarlo
	 * manualmente antes de añadirlo a la escena.
	 */

	constructGround ()
	{
		const ground_geom = new THREE.BoxGeometry(50, 0.2, 50);
		const ground_tex  = new THREE.TextureLoader().load('../imgs/wood.jpg');
		const ground_mat  = new THREE.MeshPhongMaterial({map: ground_tex});
		const ground_mesh = new THREE.Mesh(ground_geom, ground_mat);

		ground_mesh.position.y = -0.1;
		this.add(ground_mesh);
	}

	/*
	 * Crea una GUI y un directorio de la misma con título 'Luz y Ejes'  que
	 * permite modificar la intensidad de la luz y conmutar los ejes. El valor
	 * por defecto de dichos valores se especifica en guiControls.
	 *
	 * Al añadir el control de la intensidad de la luz se especifican, en orden,
	 * los valores mínimo, máximo e incremento.
	 */

	constructGUI ()
	{
		const gui    = new GUI();
		const folder = gui.addFolder("Light and axes");

		folder
			.add(this.properties, 'light_intensity', 0, 1, 0.1)
			.name("Light intensity");

		folder
			.add(this.properties, 'axes')
			.name("Show axes");

		return gui;
	}

	/*
	 * Crea una luz ambiental y una luz focal. La primera sólo tiene un color y
	 * una intensidad y se declara como una variable local porque no se va a
	 * modificar desde otros métodos. La segunda se crea como parte de la escena
	 * y tiene una posición y un punto de mira (por defecto el origen).
	 */

	constructLights ()
	{
		const light    = new THREE.AmbientLight(0xccddee, 0.35);
		this.spotlight = new THREE.SpotLight(
			0xffffff,
			this.properties.light_intensity
		);

		this.spotlight.position.set(60, 60, 40);

		this.add(light);
		this.add(this.spotlight);
	}

	/*
	 * Inicializa el objeto de visualización de la escena con un color de fondo
	 * y un tamaño y se incluye en el lienzo pasado como argumento.
	 */

	constructRenderer (canvas)
	{
		const renderer = new THREE.WebGLRenderer();

		renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
		renderer.setSize(window.innerWidth, window.innerHeight);
		$(canvas).append(renderer.domElement);

		return renderer;
	}

	/*
	 * Modifica la relación de aspecto de la cámara  y actualiza la matriz de
	 * proyección con el nuevo valor.
	 */

	setCameraAspect (ratio)
	{
		this.camera.aspect = ratio;
		this.camera.updateProjectionMatrix();
	}

	/*
	 * Actualiza la relación de aspecto de la ventana y el tamaño del renderer.
	 */

	onWindowResize ()
	{
		this.setCameraAspect(window.innerWidth / window.innerHeight);
		this.renderer.setSize(window.innerWidth, window.innerHeight);
	}

	/*
	 * Visualiza la escena con la cámara activa y actualiza los elementos de luz,
	 * ejes, control de cámaras y el resto del modelo. La última llamada indica
	 * que cada vez que haya que actualizar la escena se llama de nuevo a este
	 * método.
	 */

	update ()
	{
		this.renderer.render(this, this.camera);
		this.spotlight.intensity = this.properties.light_intensity;
		this.axes.visible = this.properties.axes;
		this.camera_control.update();
		this.model.update();

		requestAnimationFrame(() => this.update());
	}
}

/*
 * La función main se ejecuta como una llamada a jQuery, que crea la escena en
 * el div "#WebGL-output" de index.html, añade los listeners (en este caso
 * modificar el tamaño de la escena si se modifica el de la ventana y llama a
 * update para mostrar la primera visualización de la escena.
 */

$(function ()
{
	const scene = new MyScene("#WebGL-output");

	window.addEventListener("resize", () => scene.onWindowResize());
	scene.update();
});
