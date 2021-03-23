import * as THREE from '../libs/three.module.js'

class MyTorus extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		const that = this;

		this.DEFAULTS = {
			RADIUS:           2,
			TUBE:             0.5,
			SEGMENTS_RADIAL:  30,
			SEGMENTS_TUBULAR: 30
		}

		this.properties = {
			radius:           this.DEFAULTS.RADIUS,
			tube:             this.DEFAULTS.TUBE,
			segments_radial:  this.DEFAULTS.SEGMENTS_RADIAL,
			segments_tubular: this.DEFAULTS.SEGMENTS_TUBULAR,

			default: function ()
			{
				this.radius           = that.DEFAULTS.RADIUS;
				this.tube             = that.DEFAULTS.TUBE;
				this.segments_radial  = that.DEFAULTS.SEGMENTS_RADIAL;
				this.segments_tubular = that.DEFAULTS.SEGMENTS_TUBULAR;
			}
		}

		const geometry = new THREE.TorusGeometry(
			this.properties.radius,
			this.properties.tube,
			this.properties.segments_radial,
			this.properties.segments_tubular
		);
		const material = new THREE.MeshNormalMaterial();
		this.mesh      = new THREE.Mesh(geometry, material);
		this.add(this.mesh);

		this.createGUI(gui);
	}

	createGUI (gui)
	{
		const that   = this;
		const folder = gui.addFolder('Torus properties');

		folder
			.add(this.properties, 'radius', 0.1, 5.0, 0.1)
			.name('Radius')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.TorusGeometry(
					that.properties.radius,
					that.properties.tube,
					that.properties.segments_radial,
					that.properties.segments_tubular
				);
			});

		folder
			.add(this.properties, 'tube', 0.1, 5.0, 0.1)
			.name('Tube')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.TorusGeometry(
					that.properties.radius,
					that.properties.tube,
					that.properties.segments_radial,
					that.properties.segments_tubular
				);
			});

		folder
			.add(this.properties, 'segments_radial', 3, 50, 1)
			.name('Radial segments')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.TorusGeometry(
					that.properties.radius,
					that.properties.tube,
					that.properties.segments_radial,
					that.properties.segments_tubular
				);
			});

		folder
			.add(this.properties, 'segments_tubular', 3, 50, 1)
			.name('Tubular segments')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.TorusGeometry(
					that.properties.radius,
					that.properties.tube,
					that.properties.segments_radial,
					that.properties.segments_tubular
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

export { MyTorus };
