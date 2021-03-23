import * as THREE from '../libs/three.module.js'

class MyCone extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		const that = this;

		this.DEFAULTS = {
			RADIUS:   2.0,
			HEIGHT:   4.0,
			SEGMENTS: 30
		}

		this.properties = {
			radius:   this.DEFAULTS.RADIUS,
			height:   this.DEFAULTS.HEIGHT,
			segments: this.DEFAULTS.SEGMENTS,

			default: function ()
			{
				that.properties.radius   = that.DEFAULTS.RADIUS;
				that.properties.height   = that.DEFAULTS.HEIGHT;
				that.properties.segments = that.DEFAULTS.SEGMENTS;
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

		this.createGUI(gui);
	}

	createGUI (gui)
	{
		const that   = this;
		const folder = gui.addFolder('Cone properties');

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name('Radius')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.ConeGeometry(
					that.properties.radius,
					that.properties.height,
					that.properties.segments
				);
			});

		folder
			.add(this.properties, 'height', 0.1, 5.0, 0.1)
			.name('Height')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.ConeGeometry(
					that.properties.radius,
					that.properties.height,
					that.properties.segments
				);
			});

		folder
			.add(this.properties, 'segments', 3, 50, 1)
			.name('Segments')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.ConeGeometry(
					that.properties.radius,
					that.properties.height,
					that.properties.segments
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

export { MyCone };
