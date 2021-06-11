import * as THREE from '/libs/three.module.js';

const BOX_DEFAULTS = {
	SIZE_X: 1.0,
	SIZE_Y: 1.0,
	SIZE_Z: 1.0,
};

class MyBox extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		this.properties = {
			size_x: BOX_DEFAULTS.SIZE_X,
			size_y: BOX_DEFAULTS.SIZE_Y,
			size_z: BOX_DEFAULTS.SIZE_Z,

			default: () =>
			{
				this.properties.size_x = BOX_DEFAULTS.SIZE_X;
				this.properties.size_y = BOX_DEFAULTS.SIZE_Y;
				this.properties.size_z = BOX_DEFAULTS.SIZE_Z;
			}
		};

		const geometry = new THREE.BoxGeometry(
			this.properties.size_x,
			this.properties.size_y,
			this.properties.size_z
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.constructGUI(gui);
	}

	constructGUI (gui)
	{
		const folder = gui.addFolder ('Box properties');

		folder
			.add(this.properties, 'size_x', 0.1, 5.0, 0.1)
			.name('X size')
			.listen();

		folder
			.add(this.properties, 'size_y', 0.1, 5.0, 0.1)
			.name('Y size')
			.listen();

		folder
			.add(this.properties, 'size_z', 0.1, 5.0, 0.1)
			.name('Z size')
			.listen();

		folder
			.add(this.properties, 'default')
			.name('Default');
	}

	update ()
	{
		this.rotation.x += 0.01;
		this.rotation.y += 0.01;
		this.rotation.z += 0.01;

		this.scale.set(
			this.properties.size_x,
			this.properties.size_y,
			this.properties.size_z
		);
	}
}

export { MyBox };
