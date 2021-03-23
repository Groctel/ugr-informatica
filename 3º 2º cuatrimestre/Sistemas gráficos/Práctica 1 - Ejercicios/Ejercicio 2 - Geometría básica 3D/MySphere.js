import * as THREE from '../libs/three.module.js'

class MySphere extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		const that = this;

		this.DEFAULTS = {
			RADIUS:          2.0,
			SEGMENTS_WIDTH:  32,
			SEGMENTS_HEIGHT: 32
		}

		this.properties = {
			radius:          this.DEFAULTS.RADIUS,
			segments_width:  this.DEFAULTS.SEGMENTS_WIDTH,
			segments_height: this.DEFAULTS.SEGMENTS_HEIGHT,

			default: function ()
			{
				this.radius          = that.DEFAULTS.RADIUS;
				this.segments_width  = that.DEFAULTS.SEGMENTS_WIDTH;
				this.segments_height = that.DEFAULTS.SEGMENTS_HEIGHT;
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

		this.createGUI(gui);
	}

	createGUI (gui)
	{
		const that   = this;
		const folder = gui.addFolder('Sphere properties');

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name('Radius')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.SphereGeometry(
					that.properties.radius,
					that.properties.segments_width,
					that.properties.segments_height
				);
			});

		folder
			.add(this.properties, 'segments_width', 3, 50, 1)
			.name('Width segments')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.SphereGeometry(
					that.properties.radius,
					that.properties.segments_width,
					that.properties.segments_height
				);
			});

		folder
			.add(this.properties, 'segments_height', 3, 50, 1)
			.name('Height segments')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.SphereGeometry(
					that.properties.radius,
					that.properties.segments_width,
					that.properties.segments_height
				);
			});

		folder
			.add(this.properties, 'default')
			.name('Default');
	}

	update ()
	{
		this.rotation.x += 0.01;
		this.rotation.y += 0.01;
		this.rotation.z += 0.01;
	}
}

export { MySphere };
