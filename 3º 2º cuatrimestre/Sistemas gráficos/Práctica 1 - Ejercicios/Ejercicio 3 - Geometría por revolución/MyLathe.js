import * as THREE from '../libs/three.module.js'

class MyLathe extends THREE.Object3D
{
	constructor (gui, outline)
	{
		super();

		this.outline = outline;

		this.DEFAULTS = {
			SEGMENTS:   12,
			PHI_START:  0,
			PHI_LENGTH: 6.3
		}

		this.properties = {
			segments:   this.DEFAULTS.SEGMENTS,
			phi_start:  this.DEFAULTS.PHI_START,
			phi_length: this.DEFAULTS.PHI_LENGTH,

			default: () =>
			{
				this.properties.segments   = this.DEFAULTS.SEGMENTS;
				this.properties.phi_start  = this.DEFAULTS.PHI_START;
				this.properties.phi_length = this.DEFAULTS.PHI_LENGTH;
				this.reconstructGeometry();
			}
		}

		const geometry = new THREE.LatheGeometry(
			this.outline,
			this.properties.segments,
			this.properties.phi_start,
			this.properties.phi_length
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder("Lathe properties");

		folder
			.add(this.properties, 'segments', 3, 50, 1)
			.name("Segments")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'phi_start', 0, Math.PI * 2, 0.05)
			.name("Phi start")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'phi_length', 0, Math.PI * 2, 0.05)
			.name("Phi length")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	reconstructGeometry ()
	{
		this.mesh.geometry = new THREE.LatheGeometry(
			this.outline,
			this.properties.segments,
			this.properties.phi_start,
			this.properties.phi_length
		);
	}
}

export { MyLathe };
