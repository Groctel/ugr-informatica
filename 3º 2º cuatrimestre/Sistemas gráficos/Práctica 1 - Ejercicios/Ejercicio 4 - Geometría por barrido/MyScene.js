import * as THREE from '../libs/three.module.js'
import { GUI } from '../libs/dat.gui.module.js'
import { TrackballControls } from '../libs/TrackballControls.js'

import { MyHeart   } from './MyHeart.js'
import { MyClub    } from './MyClub.js'
import { MySpade   } from './MySpade.js'
import { MyDiamond } from './MyDiamond.js'
import { MySwipe   } from './MySwipe.js'

const SCENE_DEFAULTS = {
	AXES:            true,
	LIGHT_INTENSITY: 0.5,
};

const EXTRUDE_DEFAULTS = {
	steps:          2,
	depth:          1,
	bevelEnabled:   true,
	bevelThickness: 1,
	bevelSize:      1,
	bevelOffset:    0,
	bevelSegments:  10
};

class MyScene extends THREE.Scene {
	constructor (myCanvas) {
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
		this.gui      = this.constructGUI();
		this.constructLights();
		this.constructCamera();

		this.axes = new THREE.AxesHelper (50);
		this.add (this.axes);

		const radius = 20;

		this.heart   = new MyHeart(EXTRUDE_DEFAULTS, radius);
		this.club    = new MyClub(EXTRUDE_DEFAULTS, radius);
		this.spade   = new MySpade(EXTRUDE_DEFAULTS, radius);
		this.diamond = new MyDiamond(EXTRUDE_DEFAULTS, radius);
		this.swipe   = new MySwipe(radius);

		this.add(this.heart);
		this.add(this.club);
		this.add(this.spade);
		this.add(this.diamond);
		this.add(this.swipe);
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
		this.heart.update();
		this.club.update();
		this.spade.update();
		this.diamond.update();
		this.swipe.update();

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


