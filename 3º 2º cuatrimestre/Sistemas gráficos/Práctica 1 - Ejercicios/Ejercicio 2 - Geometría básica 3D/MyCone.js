import * as THREE from '../libs/three.module.js'

const CONE_DEFAULTS = {
	RADIUS:   2.0,
	HEIGHT:   4.0,
	SEGMENTS: 30
}

class MyCone extends THREE.Object3D
{
	constructor (gui)
	{
		super();


		this.properties = {
			radius:   CONE_DEFAULTS.RADIUS,
			height:   CONE_DEFAULTS.HEIGHT,
			segments: CONE_DEFAULTS.SEGMENTS,

			default: () =>
			{
				this.properties.radius   = CONE_DEFAULTS.RADIUS;
				this.properties.height   = CONE_DEFAULTS.HEIGHT;
				this.properties.segments = CONE_DEFAULTS.SEGMENTS;
				this.reconstructGeometry();
			}
		}

		const geometry = new THREE.ConeGeometry(
			this.properties.radius,
			this.properties.height,
			this.properties.segments
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder("Cone properties");

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name("Radius")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'height', 0.1, 5.0, 0.1)
			.name("Height")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'segments', 3, 50, 1)
			.name("Segments")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	reconstructGeometry ()
	{
		this.mesh.geometry = new THREE.ConeGeometry(
			this.properties.radius,
			this.properties.height,
			this.properties.segments
		);
	}

	update ()
	{
		this.rotation.x += 0.01;
		this.rotation.y += 0.01;
		this.rotation.z += 0.01;
	}
}

export { MyCone };
