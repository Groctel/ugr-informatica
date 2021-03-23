import * as THREE from '../libs/three.module.js'
import { GUI } from '../libs/dat.gui.module.js'
import { TrackballControls } from '../libs/TrackballControls.js'

import { MyBox         } from './MyBox.js'
import { MyCone        } from './MyCone.js'
import { MyCylinder    } from './MyCylinder.js'
import { MyIcosahedron } from './MyIcosahedron.js'
import { MySphere      } from './MySphere.js'
import { MyTorus       } from './MyTorus.js'

class MyScene extends THREE.Scene
{
	constructor (myCanvas)
	{
		super();

		this.renderer = this.createRenderer(myCanvas);
		this.gui = this.createGUI ();
		this.createLights();
		this.createCamera();

		this.box_axes  = new THREE.AxesHelper(3);
		this.box_model = new MyBox(this.gui);
		this.box_axes.position.set(5, 5, 5);
		this.box_model.position.set(5, 5, 5);
		this.add(this.box_axes);
		this.add(this.box_model);

		this.cone_axes  = new THREE.AxesHelper(3);
		this.cone_model = new MyCone(this.gui);
		this.cone_axes.position.set(5, -5, -5);
		this.cone_model.position.set(5, -5, -5);
		this.add(this.cone_axes);
		this.add(this.cone_model);

		this.cylinder_axes  = new THREE.AxesHelper(3);
		this.cylinder_model = new MyCylinder(this.gui);
		this.cylinder_axes.position.set(-5, -5, 5);
		this.cylinder_model.position.set(-5, -5, 5);
		this.add(this.cylinder_axes);
		this.add(this.cylinder_model);

		this.icosahedron_axes  = new THREE.AxesHelper(3);
		this.icosahedron_model = new MyIcosahedron(this.gui);
		this.icosahedron_axes.position.set(-5, 5, -5);
		this.icosahedron_model.position.set(-5, 5, -5);
		this.add(this.icosahedron_axes);
		this.add(this.icosahedron_model);

		this.sphere_axes  = new THREE.AxesHelper(3);
		this.sphere_model = new MySphere(this.gui);
		this.sphere_axes.position.set(-5, -5, -5);
		this.sphere_model.position.set(-5, -5, -5);
		this.add(this.sphere_axes);
		this.add(this.sphere_model);

		this.torus_axes  = new THREE.AxesHelper(3);
		this.torus_model = new MyTorus(this.gui);
		this.add(this.torus_axes);
		this.add(this.torus_model);
  }

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
		this.cameraControl.zoomSpeed   = 1;
		this.cameraControl.panSpeed    = 0.5;
		this.cameraControl.target      = look;
	}

	createGUI ()
	{
		let gui = new GUI();

		this.guiControls = new function ()
		{
			this.lightIntensity = 0.5;
			this.axesOnOff = true;
		}

		var folder = gui.addFolder('Lights and axes');

		folder.add(
			this.guiControls, 'lightIntensity',
			0, 1, 0.1
		).name('Light intensity');

		folder.add(this.guiControls, 'axesOnOff').name('Show axes')

		return gui;
	}

	createLights ()
	{
		var ambientLight = new THREE.AmbientLight(0xccddee, 0.35);
		this.spotLight   = new THREE.SpotLight(0xffffff, this.guiControls.lightIntensity);

		this.spotLight.position.set(60, 60, 40);

		this.add(ambientLight);
		this.add(this.spotLight);
	}

	createRenderer (myCanvas)
	{
		var renderer = new THREE.WebGLRenderer();

		renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
		renderer.setSize(window.innerWidth, window.innerHeight);
		$(myCanvas).append(renderer.domElement);

		return renderer;
	}

	getCamera ()
	{
		return this.camera;
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
		this.renderer.render(this, this.getCamera());
		this.spotLight.intensity = this.guiControls.lightIntensity;
		this.cameraControl.update();

		this.box_axes.visible         = this.guiControls.axesOnOff;
		this.cone_axes.visible        = this.guiControls.axesOnOff;
		this.cylinder_axes.visible    = this.guiControls.axesOnOff;
		this.icosahedron_axes.visible = this.guiControls.axesOnOff;
		this.sphere_axes.visible      = this.guiControls.axesOnOff;
		this.torus_axes.visible       = this.guiControls.axesOnOff;

		this.box_model.update();
		this.cone_model.update();
		this.cylinder_model.update();
		this.icosahedron_model.update();
		this.sphere_model.update();
		this.torus_model.update();

		requestAnimationFrame(() => this.update())
	}
}

$(function ()
{
	var scene = new MyScene("#WebGL-output");

	window.addEventListener("resize", () => scene.onWindowResize());
	scene.update();
});
