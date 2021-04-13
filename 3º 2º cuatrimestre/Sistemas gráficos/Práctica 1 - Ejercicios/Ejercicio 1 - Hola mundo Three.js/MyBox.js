import * as THREE from '../libs/three.module.js';

class MyBox extends THREE.Object3D
{
	/*
	 * Creamos la GUI primero para permitir a los métodos llamados después usarla.
	 * Luego asignamos el material y creamos la caja, que se añade al objeto.
	 */

	constructor (gui)
	{
		super();

		this.DEFAULTS = {
			SIZE_X: 1.0,
			SIZE_Y: 1.0,
			SIZE_Z: 1.0,

			ROT_X: 0.0,
			ROT_Y: 0.0,
			ROT_Z: 0.0,

			POS_X: 0.0,
			POS_Y: 0.5,
			POS_Z: 0.0,
		};

		this.properties = {
			size_x: this.DEFAULTS.SIZE_X,
			size_y: this.DEFAULTS.SIZE_Y,
			size_z: this.DEFAULTS.SIZE_Z,

			rot_x: this.DEFAULTS.ROT_X,
			rot_y: this.DEFAULTS.ROT_Y,
			rot_z: this.DEFAULTS.ROT_Z,

			pos_x: this.DEFAULTS.POS_X,
			pos_y: this.DEFAULTS.POS_Y,
			pos_z: this.DEFAULTS.POS_Z,

			default: () =>
			{
				this.properties.size_x = 1.0;
				this.properties.size_y = 1.0;
				this.properties.size_z = 1.0;

				this.properties.rot_x = 0.0;
				this.properties.rot_y = 0.0;
				this.properties.rot_z = 0.0;

				this.properties.pos_x = 0.0;
				this.properties.pos_y = 0.5;
				this.properties.pos_z = 0.0;
			}
		};

		const box_geom = new THREE.BoxGeometry(1,1,1);
		const box_mat  = new THREE.MeshPhongMaterial({color: 0xCF0000});
		this.mesh      = new THREE.Mesh (box_geom, box_mat);
		this.add(this.mesh);

		this.createGUI(gui);
	}

	/*
	 * Crea un directorio de la GUI que permite modificar el tamaño del cubo. El
	 * valor por defecto del tamaño se especifica en guiControls.
	 *
	 * Al añadir el control del tamaño se especifican, en orden, los valores
	 * mínimo, máximo e incremento.
	 *
	 * Cada elemento del directorio contiene una llamada .listen() para que se
	 * actualice su valor en la pantalla al pulsar el botón de reset.
	 */

	createGUI (gui)
	{
		const folder = gui.addFolder('Box properties');

		folder
			.add(this.properties, 'size_x', 0, 5.0, 0.1)
			.name('X size')
			.listen();

		folder
			.add(this.properties, 'size_y', 0, 5.0, 0.1)
			.name('Y size')
			.listen();

		folder
			.add(this.properties, 'size_z', 0, 5.0, 0.1)
			.name('Z size')
			.listen();

		folder
			.add(this.properties, 'rot_x', 0, Math.PI/2, 0.1)
			.name('X rotation')
			.listen();

		folder
			.add(this.properties, 'rot_y', 0, Math.PI/2, 0.1)
			.name('Y rotation')
			.listen();

		folder
			.add(this.properties, 'rot_z', 0, Math.PI/2, 0.1)
			.name('Z rotation')
			.listen();

		folder
			.add(this.properties, 'pos_x', 0, 5.0, 0.1)
			.name('X position')
			.listen();

		folder
			.add(this.properties, 'pos_y', 0, 5.0, 0.1)
			.name('Y position')
			.listen();

		folder
			.add(this.properties, 'pos_z', 0, 5.0, 0.1)
			.name('Z position')
			.listen();

		folder
			.add(this.properties, 'default')
			.name('Default');
	}

	/*
	 * La actualización de la caja consiste en modificar su posición en la escena,
	 * su rotación y su escalado siguiendo la regla de TRES de las transformaciones:
	 *
	 * TRES transformaciones deberás hacer:
	 * - Traslación
	 * - Rotación
	 * - Escalado... y todo saldrá
	 * - Súper bien!
	 */

	update ()
	{
		this.position.set(
			this.properties.pos_x,
			this.properties.pos_y,
			this.properties.pos_z
		);
		this.rotation.set(
			this.properties.rot_x,
			this.properties.rot_y,
			this.properties.rot_z
		);
		this.scale.set(
			this.properties.size_x,
			this.properties.size_y,
			this.properties.size_z
		);
	}
}

/*
 * Por último, exportamos el módulo para utilizarlo en otras clases.
 */

export { MyBox };
