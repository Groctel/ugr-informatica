import * as THREE from '../libs/three.module.js'
import { GUI } from '../libs/dat.gui.module.js'
import { TrackballControls } from '../libs/TrackballControls.js'

import { MyClock } from './MyClock.js'

const SCENE_DEFAULTS = {
	AXES:            true,
	LIGHT_INTENSITY: 0.5,
};

class MyScene extends THREE.Scene {
	constructor (myCanvas)
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

		this.renderer = this.constructRenderer(myCanvas);
		this.gui      = this.constructGUI ();
		this.constructLights ();
		this.constructCamera ();
		this.constructGround();

		this.axes = new THREE.AxesHelper (50);
		this.add(this.axes);

		this.reloj = new MyClock(this.gui);
		this.add(this.reloj);

	}

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

	constructGround ()
	{
		const ground_geom = new THREE.BoxGeometry(50, 0.2, 50);
		const ground_tex  = new THREE.TextureLoader().load('../imgs/wood.jpg');
		const ground_mat  = new THREE.MeshPhongMaterial({map: ground_tex});
		const ground_mesh = new THREE.Mesh(ground_geom, ground_mat);

		ground_mesh.position.y = -0.1;
		this.add(ground_mesh);
	}

	constructGUI ()
	{
		const gui    = new GUI();
		const folder = gui.addFolder("Lights and axes");

		folder
			.add(this.properties, 'light_intensity', 0, 1, 0.1)
			.name("Light intensity");

		folder
			.add(this.properties, 'axes')
			.name("Show axes");

		return gui;
	}

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

	constructRenderer (myCanvas)
	{
		const renderer = new THREE.WebGLRenderer();

		renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
		renderer.setSize(window.innerWidth, window.innerHeight);
		$(myCanvas).append(renderer.domElement);

		return renderer;
	}

	setCameraAspect (ratio)
	{
		this.camera.aspect = ratio;
		this.camera.updateProjectionMatrix();
	}

	onWindowResize ()
	{
		this.setCameraAspect(window.innerWidth / window.innerHeight);
		this.renderer.setSize(window.innerWidth, window.innerHeight);
	}

	update ()
	{
		this.renderer.render(this, this.camera);
		this.spotlight.intensity = this.properties.light_intensity;
		this.camera_control.update();
		this.reloj.update();

		this.axes.visible = this.properties.axes;

		requestAnimationFrame(() => this.update())
	}
}

$(function ()
{
	const scene = new MyScene("#WebGL-output");

	window.addEventListener('resize', () => scene.onWindowResize());
	scene.update();
});

