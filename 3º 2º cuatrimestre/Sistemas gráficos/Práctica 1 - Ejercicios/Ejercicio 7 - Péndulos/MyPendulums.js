import * as THREE from '/libs/three.module.js'

const PENDULUM_DEFAULTS = {
	TOP_ANGLE:  0.0,
	TOP_HEIGHT: 1.0,
	SUB_ANGLE:  0.0,
	SUB_LENGTH: 1.0,
	SUB_SHIFT:  10.0,
}

class MyPendulums extends THREE.Object3D {
	constructor(gui) {
		super();

		this.properties = {
			top_angle:  PENDULUM_DEFAULTS.TOP_ANGLE,
			top_length: PENDULUM_DEFAULTS.TOP_HEIGHT,
			sub_angle:  PENDULUM_DEFAULTS.SUB_ANGLE,
			sub_length: PENDULUM_DEFAULTS.SUB_LENGTH,
			sub_shift:  PENDULUM_DEFAULTS.SUB_SHIFT,

			default: () =>
			{
				this.properties.top_angle  = PENDULUM_DEFAULTS.TOP_ANGLE;
				this.properties.top_length = PENDULUM_DEFAULTS.TOP_HEIGHT;
				this.properties.sub_angle  = PENDULUM_DEFAULTS.SUB_ANGLE;
				this.properties.sub_length = PENDULUM_DEFAULTS.SUB_LENGTH;
				this.properties.sub_shift  = PENDULUM_DEFAULTS.SUB_SHIFT;
			}
		}

		this.pendulums_model = new THREE.Object3D;
		this.pendulums_model.add(this.constructBottomPendulum());
		this.pendulums_model.add(this.constructTopPendulum());
		this.add(this.pendulums_model);

		this.createGUI(gui);
	}

	constructBottomPendulum ()
	{
		this.bp_box = new THREE.Mesh(
			new THREE.BoxGeometry(2.0, PENDULUM_DEFAULTS.SUB_LENGTH, 1.0),
			new THREE.MeshPhongMaterial({color: "#0000ff"}
		));
		this.bp_box.geometry.translate(0.0, -PENDULUM_DEFAULTS.SUB_LENGTH/2, 1.5);
		this.bp_box.translateY(0.5);

		this.bp_bolt = new THREE.Mesh(
			new THREE.ExtrudeGeometry(
				new THREE.Shape().absarc(0, 0.25, 0.25, 0, 2 * Math.PI),
				{depth: 0.3, bevelEnabled: false}
			),
			new THREE.MeshPhongMaterial({color: "#006600"})
		);
		this.bp_bolt.geometry.translate(0, -0.25, 2.0);

		this.bot_pendulum = new THREE.Object3D();
		this.bot_pendulum.add(this.bp_box);
		this.bot_pendulum.add(this.bp_bolt);

		return this.bot_pendulum;
	}

	constructTopPendulum ()
	{
		const fixed_geom  = new THREE.BoxGeometry(2, 4, 2);
		const fixed_mat   = new THREE.MeshPhongMaterial({color: "#00ff00"});
		this.tp_top_fixed = new THREE.Mesh(fixed_geom, fixed_mat);
		this.tp_bot_fixed = new THREE.Mesh(fixed_geom, fixed_mat);

		this.add(this.tp_bot_fixed);
		this.add(this.tp_top_fixed);

		this.tp_resizable = new THREE.Mesh(
			new THREE.BoxGeometry(2, PENDULUM_DEFAULTS.TOP_HEIGHT, 2),
			new THREE.MeshPhongMaterial({color: "#ff0000"})
		);
		this.tp_resizable.geometry.translate(0, -PENDULUM_DEFAULTS.TOP_HEIGHT/2, 0);
		this.tp_resizable.translateY(-2);

		this.tp_bolt = new THREE.Mesh(
			new THREE.ExtrudeGeometry(
				new THREE.Shape().absarc(0, 0.7, 0.7, 0, 2 * Math.PI),
				{depth: 0.3, bevelEnabled: false}
			),
			new THREE.MeshPhongMaterial({color: "#ffc0cb"})
		);
		this.tp_bolt.geometry.translate(0, -0.7, 1);

		this.top_pendulum = new THREE.Object3D();
		this.top_pendulum.add(this.tp_resizable);
		this.top_pendulum.add(this.tp_bot_fixed);
		this.top_pendulum.add(this.tp_top_fixed);
		this.top_pendulum.add(this.tp_bolt);

		return this.top_pendulum;
	}

	createGUI (gui)
	{
		const folder        = gui.addFolder("Pendulums controls");
		const top_subfolder = folder.addFolder("Top pendulum");
		const sub_subfolder = folder.addFolder("Subordinate pendulum");

		top_subfolder
			.add(this.properties, 'top_length', 1.0, 5.0, 0.1)
			.name("Length")
			.listen();

		top_subfolder
			.add(this.properties, 'top_angle', -Math.PI/4.0, Math.PI/4.0, 0.1)
			.name("Angle")
			.listen();

		sub_subfolder
			.add(this.properties, 'sub_length', 1.0, 10.0, 0.1)
			.name("Length")
			.listen();

		sub_subfolder
			.add(this.properties, 'sub_angle', -Math.PI/4.0, Math.PI/4.0, 0.1)
			.name("Angle")
			.listen();

		sub_subfolder
			.add(this.properties, 'sub_shift', 10.0, 90.0, 1.0)
			.name("Shift")
			.listen();

		folder
			.add(this.properties, 'default')
			.name("Default");
	}

	update ()
	{
		this.tp_resizable.scale.y       = this.properties.top_length;
		this.pendulums_model.rotation.z = this.properties.top_angle;
		this.tp_bot_fixed.position.y    = -(this.properties.top_length+4);

		this.bp_box.scale.y          = this.properties.sub_length;
		this.bot_pendulum.rotation.z = this.properties.sub_angle;
		this.bot_pendulum.position.y = -(
			(this.properties.sub_shift * (this.properties.top_length/100)) + 2);
	}
}

export { MyPendulums }
