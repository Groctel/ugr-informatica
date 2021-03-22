import * as THREE from '../libs/three.module.js'
import { GUI } from '../libs/dat.gui.module.js'
import { TrackballControls } from '../libs/TrackballControls.js'
import { MyBox } from './MyBox.js'

class MyScene extends THREE.Scene
{
	/*
	 * Crea los objetos propios de la escena como hijos de ella y los modelos que
	 * se van a mostrar en la misma. Los objetos que se crean en este método
	 * deben añadirse manualmente. Recibe el lienzo html sobre el que se va a
	 * visualizar.
	 */
	constructor (myCanvas)
	{
		super();

		this.renderer = this.createRenderer(myCanvas);
		this.gui = this.createGUI ();
		this.createLights();
		this.createCamera();
		this.createGround();

		this.axis  = new THREE.AxesHelper(5);
		this.model = new MyBox(this.gui, "Controles de la Caja");

		this.add(this.axis);
		this.add(this.model);
  }

	/*
	 * Se crea la cámara indicándole el ángulo de visión vertical en grados
	 * sexagesimales, la relación de aspecto, el near y el far. Se indica dónde
	 * se coloca y hacia dónde mira y se inicializan los parámetros de control de
	 * la misma.
	 */

	createCamera ()
	{
		this.camera = new THREE.PerspectiveCamera(
			45,
			window.innerWidth / window.innerHeight,
			0.1,
			1000
		);

		this.camera.position.set(20, 10, 10);
		let look = new THREE.Vector3(0, 0, 0);
		this.camera.lookAt(look);
		this.add(this.camera);

		this.cameraControl = new TrackballControls(this.camera, this.renderer.domElement);

		this.cameraControl.rotateSpeed = 5;
		this.cameraControl.zoomSpeed   = -2;
		this.cameraControl.panSpeed    = 0.5;
		this.cameraControl.target      = look;
	}

	/*
	 * Crea el suelo, que es un objeto Mesh con una geometría, un material y una
	 * textura. Como las figuras se crean centradas en el origen, hay que bajarlo
	 * manualmente antes de añadirlo a la escena.
	 */

	createGround ()
	{
		let geometryGround = new THREE.BoxGeometry(50, 0.2, 50);
		let textureGround  = new THREE.TextureLoader().load('../imgs/wood.jpg');
		let materialGround = new THREE.MeshPhongMaterial({map: textureGround});

		let ground = new THREE.Mesh(geometryGround, materialGround);
		ground.position.y = -0.1;

		this.add (ground);
	}

	/*
	 * Crea una GUI y un directorio de la misma con título 'Luz y Ejes'  que
	 * permite modificar la intensidad de la luz y conmutar los ejes. El valor
	 * por defecto de dichos valores se especifica en guiControls.
	 *
	 * Al añadir el control de la intensidad de la luz se especifican, en orden,
	 * los valores mínimo, máximo e incremento.
	 */

	createGUI ()
	{
		let gui = new GUI();

		this.guiControls = new function ()
		{
			this.lightIntensity = 0.5;
			this.axisOnOff = true;
		}

		var folder = gui.addFolder('Luz y Ejes');

		folder.add(
			this.guiControls, 'lightIntensity',
			0, 1, 0.1
		).name('Intensidad de la Luz');

		folder.add(this.guiControls, 'axisOnOff').name('Mostrar ejes')

		return gui;
	}

	/*
	 * Crea una luz ambiental y una luz focal. La primera sólo tiene un color y
	 * una intensidad y se declara como una variable local porque no se va a
	 * modificar desde otros métodos. La segunda se crea como parte de la escena
	 * y tiene una posición y un punto de mira (por defecto el origen).
	 */

	createLights ()
	{
		var ambientLight = new THREE.AmbientLight(0xccddee, 0.35);
		this.spotLight   = new THREE.SpotLight(0xffffff, this.guiControls.lightIntensity);

		this.spotLight.position.set(60, 60, 40);

		this.add(ambientLight);
		this.add(this.spotLight);
	}

	/*
	 * Inicializa el objeto de visualización de la escena con un color de fondo
	 * y un tamaño y se incluye en el lienzo pasado como argumento.
	 */

	createRenderer (myCanvas)
	{
		var renderer = new THREE.WebGLRenderer();

		renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
		renderer.setSize(window.innerWidth, window.innerHeight);
		$(myCanvas).append(renderer.domElement);

		return renderer;
	}

	/*
	 * Consultor de la cámara de toda la vida.
	 */

	getCamera ()
	{
		return this.camera;
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
		this.renderer.render(this, this.getCamera());
		this.spotLight.intensity = this.guiControls.lightIntensity;
		this.axis.visible = this.guiControls.axisOnOff;
		this.cameraControl.update();
		this.model.update();

		requestAnimationFrame(() => this.update())
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
	var scene = new MyScene("#WebGL-output");

	window.addEventListener("resize", () => scene.onWindowResize());
	scene.update();
});
