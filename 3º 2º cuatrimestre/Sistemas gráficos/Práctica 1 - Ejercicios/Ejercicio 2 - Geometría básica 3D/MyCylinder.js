import * as THREE from '../libs/three.module.js'

class MyCylinder extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		this.DEFAULTS = {
			RADIUS_TOP:    1.0,
			RADIUS_BOTTOM: 1.0,
			HEIGHT:        3.0,
			SEGMENTS:      30
		}

		this.properties = {
			radius_top:    this.DEFAULTS.RADIUS_TOP,
			radius_bottom: this.DEFAULTS.RADIUS_BOTTOM,
			height:        this.DEFAULTS.HEIGHT,
			segments:      this.DEFAULTS.SEGMENTS,

			default: () =>
			{
				this.properties.radius_top    = this.DEFAULTS.RADIUS_TOP;
				this.properties.radius_bottom = this.DEFAULTS.RADIUS_BOTTOM;
				this.properties.height        = this.DEFAULTS.HEIGHT;
				this.properties.segments      = this.DEFAULTS.SEGMENTS;
				this.reconstructGeometry();
			}
		}

		const geometry = new THREE.CylinderGeometry(
			this.properties.radius_top,
			this.properties.radius_bottom,
			this.properties.height,
			this.properties.segments,
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder("Cylinder properties");

		folder
			.add(this.properties, 'radius_top', 0.1, 5.0, 0.1)
			.name("Radius top")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'radius_bottom', 0.1, 5.0, 0.1)
			.name("Radius bottom")
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
		this.mesh.geometry = new THREE.CylinderGeometry(
			this.properties.radius_top,
			this.properties.radius_bottom,
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

export { MyCylinder };
