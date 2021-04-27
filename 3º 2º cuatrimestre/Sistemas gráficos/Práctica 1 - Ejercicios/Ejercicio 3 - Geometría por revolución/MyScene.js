import * as THREE from '../libs/three.module.js'
import { GUI } from '../libs/dat.gui.module.js'
import { TrackballControls } from '../libs/TrackballControls.js'

import { MyLathe } from './MyLathe.js'

const SCENE_DEFAULTS = {
	AXES:            true,
	LIGHT_INTENSITY: 0.5,
};

class MyScene extends THREE.Scene
{
	constructor (canvas)
	{
		super();

		const pawn_outline = [
			new THREE.Vector3(0.0,  -1.4, 0.0),
			new THREE.Vector3(1.0,  -1.4, 0.0),
			new THREE.Vector3(1.0,  -1.1, 0.0),
			new THREE.Vector3(0.5,  -0.7, 0.0),
			new THREE.Vector3(0.4,  -0.4, 0.0),
			new THREE.Vector3(0.4,  0.5, 0.0),
			new THREE.Vector3(0.5,  0.6, 0.0),
			new THREE.Vector3(0.3,  0.6, 0.0),
			new THREE.Vector3(0.5,  0.8, 0.0),
			new THREE.Vector3(0.55, 1.0, 0.0),
			new THREE.Vector3(0.5,  1.2, 0.0),
			new THREE.Vector3(0.3,  1.4, 0.0),
			new THREE.Vector3(0.0,  1.4, 0.0)
		];

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

		const line_geom    = new THREE.Geometry();
		const material     = new THREE.MeshNormalMaterial()
		line_geom.vertices = pawn_outline;

		this.line_axes  = new THREE.AxesHelper(3);
		this.line_model = new THREE.Line(line_geom, material);
		this.add(this.line_axes);
		this.add(this.line_model);
		this.line_axes.position.set(0, 0, -2.5);
		this.line_model.position.set(0, 0, -2.5);


		this.lathe_axes  = new THREE.AxesHelper(3);
		this.lathe_model = new MyLathe(this.gui, pawn_outline);
		this.add(this.lathe_axes);
		this.add(this.lathe_model);
		this.lathe_axes.position.set(0, 0, 2.5);
		this.lathe_model.position.set(0, 0, 2.5);
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

	constructRenderer (canvas)
	{
		const renderer = new THREE.WebGLRenderer();

		renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
		renderer.setSize(window.innerWidth, window.innerHeight);
		$(canvas).append(renderer.domElement);

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

		this.lathe_axes.visible = this.properties.axes;

		requestAnimationFrame(() => this.update())
	}
}

$(function ()
{
	const scene = new MyScene("#WebGL-output");

	window.addEventListener('resize', () => scene.onWindowResize());
	scene.update();
});
