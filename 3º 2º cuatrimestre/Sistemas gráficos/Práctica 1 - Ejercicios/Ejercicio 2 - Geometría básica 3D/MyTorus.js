import * as THREE from '/libs/three.module.js'

const TORUS_DEFAULTS = {
	RADIUS:           2,
	TUBE:             0.5,
	SEGMENTS_RADIAL:  30,
	SEGMENTS_TUBULAR: 50
}

class MyTorus extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		this.properties = {
			radius:           TORUS_DEFAULTS.RADIUS,
			tube:             TORUS_DEFAULTS.TUBE,
			segments_radial:  TORUS_DEFAULTS.SEGMENTS_RADIAL,
			segments_tubular: TORUS_DEFAULTS.SEGMENTS_TUBULAR,

			default: () =>
			{
				this.properties.radius           = TORUS_DEFAULTS.RADIUS;
				this.properties.tube             = TORUS_DEFAULTS.TUBE;
				this.properties.segments_radial  = TORUS_DEFAULTS.SEGMENTS_RADIAL;
				this.properties.segments_tubular = TORUS_DEFAULTS.SEGMENTS_TUBULAR;
				this.reconstructGeometry();
			}
		}

		const geometry = new THREE.TorusGeometry(
			this.radius,
			this.tube,
			this.segments_radial,
			this.segments_tubular
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder("Torus properties");

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name("Radius")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'tube', 0.1, 5.0, 0.1)
			.name("Tube")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'segments_radial', 3, 50, 1)
			.name("Radial segments")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'segments_tubular', 3, 50, 1)
			.name("Tubular segments")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	reconstructGeometry ()
	{
		this.mesh.geometry = new THREE.TorusGeometry(
			this.properties.radius,
			this.properties.tube,
			this.properties.segments_radial,
			this.properties.segments_tubular
		);
	}

	update ()
	{
		this.rotation.x += 0.01;
		this.rotation.y += 0.01;
		this.rotation.z += 0.01;
	}
}

export { MyTorus };
