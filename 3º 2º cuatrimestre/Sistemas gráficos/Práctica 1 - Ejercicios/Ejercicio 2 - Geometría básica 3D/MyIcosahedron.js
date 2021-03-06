import * as THREE from '/libs/three.module.js'

const ICOSAHEDRON_DEFAULTS = {
	RADIUS: 3.0,
	DETAIL: 0,
}

class MyIcosahedron extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		this.properties = {
			radius: ICOSAHEDRON_DEFAULTS.RADIUS,
			detail: ICOSAHEDRON_DEFAULTS.DETAIL,

			default: () =>
			{
				this.properties.radius = ICOSAHEDRON_DEFAULTS.RADIUS;
				this.properties.detail = ICOSAHEDRON_DEFAULTS.DETAIL;
				this.reconstructGeometry();
			}
		}

		const geometry = new THREE.IcosahedronGeometry(
			this.properties.radius,
			this.properties.detail
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder('Icosahedron properties');

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name("Radius")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'detail', 0, 50, 1)
			.name("Detail")
			.onChange(() => this.reconstructGeometry())
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	reconstructGeometry ()
	{
		this.mesh.geometry = new THREE.IcosahedronGeometry(
			this.properties.radius,
			this.properties.detail
		);
	}

	update ()
	{
		this.rotation.x += 0.01;
		this.rotation.y += 0.01;
		this.rotation.z += 0.01;
	}
}

export { MyIcosahedron };
