import * as THREE from '../libs/three.module.js'

const SPHERE_DEFAULTS = {
	RADIUS:          2.0,
	SEGMENTS_WIDTH:  32,
	SEGMENTS_HEIGHT: 32
}

class MySphere extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		this.properties = {
			radius:          SPHERE_DEFAULTS.RADIUS,
			segments_width:  SPHERE_DEFAULTS.SEGMENTS_WIDTH,
			segments_height: SPHERE_DEFAULTS.SEGMENTS_HEIGHT,

			default: () =>
			{
				this.properties.radius          = SPHERE_DEFAULTS.RADIUS;
				this.properties.segments_width  = SPHERE_DEFAULTS.SEGMENTS_WIDTH;
				this.properties.segments_height = SPHERE_DEFAULTS.SEGMENTS_HEIGHT;
				this.reconstructGeometry();
			}
		}

		const geometry = new THREE.SphereGeometry(
			this.radius,
			this.segments_width,
			this.segments_height
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder("Sphere properties");

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name("Radius")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'segments_width', 3, 50, 1)
			.name("Width segments")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'segments_height', 3, 50, 1)
			.name("Height segments")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	reconstructGeometry ()
	{
		this.mesh.geometry = new THREE.SphereGeometry(
			this.properties.radius,
			this.properties.segments_width,
			this.properties.segments_height
		);
	}

	update ()
	{
		this.rotation.x += 0.01;
		this.rotation.y += 0.01;
		this.rotation.z += 0.01;
	}
}

export { MySphere };
