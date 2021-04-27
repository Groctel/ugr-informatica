import * as THREE from '../libs/three.module.js'

const CLOCK_DEFAULTS = {
	SPEED: 1.0,
};

class MyClock extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		this.properties = {
			speed: CLOCK_DEFAULTS.SPEED,

			default: () =>
			{
				this.properties.speed = CLOCK_DEFAULTS.SPEED;
			}
		};

		const radius = 20;
		const sphere = new THREE.SphereGeometry(1, 20, 20);

		this.constructDial(radius, sphere);
		this.constructHand(radius, sphere);
		this.constructGUI(gui);

		this.last_time = Date.now();
	}

	constructDial (radius, geometry)
	{
		const material = new THREE.MeshPhongMaterial({color: "#00ff00"});
		this.dial      = new Array();

		for (let i = 0; i < 12; i++)
		{
			const angle = (2 * Math.PI) / 12.0;

			this.dial.push(new THREE.Mesh(geometry, material));

			this.dial[i].translateX(Math.cos(i*angle) * radius);
			this.dial[i].translateZ(-Math.sin(i*angle) * radius);

			this.add(this.dial[i]);
		}

	}

	constructGUI (gui)
	{
		const folder = gui.addFolder("Clock controls");

		folder
			.add(this.properties, 'speed', -30.0, 30.0, 1.0)
			.name("Speed")
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	constructHand (radius, geometry)
	{
		this.hand_mesh = new THREE.Mesh(
			geometry,
			new THREE.MeshPhongMaterial({color: "#ff0000"})
		);
		this.hand_mesh.translateX(radius-3);

		this.hand = new THREE.Object3D();
		this.hand.add(this.hand_mesh);
		this.add(this.hand);
	}

	update ()
	{
		const now = Date.now();

		this.hand.rotation.y -=
			this.properties.speed *
			((2*Math.PI) / 120) *
			((now - this.last_time) / 1000.0);

		this.last_time = now;
	}
}

export { MyClock }
