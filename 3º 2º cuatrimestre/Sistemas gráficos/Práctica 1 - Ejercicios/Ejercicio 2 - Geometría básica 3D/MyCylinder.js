import * as THREE from '../libs/three.module.js'

class MyCylinder extends THREE.Object3D
{
	constructor (gui)
	{
		super();

		const that = this;

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

			default: function ()
			{
				this.radius_top    = that.DEFAULTS.RADIUS_TOP;
				this.radius_bottom = that.DEFAULTS.RADIUS_BOTTOM;
				this.height        = that.DEFAULTS.HEIGHT;
				this.segments      = that.DEFAULTS.SEGMENTS;
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

		this.createGUI(gui);
	}

	createGUI (gui)
	{
		const that   = this;
		const folder = gui.addFolder('Cylinder properties');

		folder
			.add(this.properties, 'radius_top', 0.1, 5.0, 0.1)
			.name('Radius top')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.CylinderGeometry(
					that.properties.radius_top,
					that.properties.radius_bottom,
					that.properties.height,
					that.properties.segments
				);
			});

		folder
			.add(this.properties, 'radius_bottom', 0.1, 5.0, 0.1)
			.name('Radius bottom')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.CylinderGeometry(
					that.properties.radius_top,
					that.properties.radius_bottom,
					that.properties.height,
					that.properties.segments
				);
			});

		folder
			.add(this.properties, 'height', 0.1, 5.0, 0.1)
			.name('Height')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.CylinderGeometry(
					that.properties.radius_top,
					that.properties.radius_bottom,
					that.properties.height,
					that.properties.segments
				);
			});

		folder
			.add(this.properties, 'segments', 3, 50, 1)
			.name('Segments')
			.onChange(function ()
			{
				that.mesh.geometry = new THREE.CylinderGeometry(
					that.properties.radius_top,
					that.properties.radius_bottom,
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

export { MyCylinder };
