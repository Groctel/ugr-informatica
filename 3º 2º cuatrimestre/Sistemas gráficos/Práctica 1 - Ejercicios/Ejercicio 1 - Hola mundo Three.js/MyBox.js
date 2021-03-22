import * as THREE from '../libs/three.module.js'

class MyBox extends THREE.Object3D
{
	/*
	 * Creamos la GUI primero para permitir a los métodos llamados después usarla.
	 * Luego asignamos el material y creamos la caja, que se añade al objeto.
	 */

	constructor (gui,titleGui)
	{
		super();

		this.createGUI(gui,titleGui);

		let boxGeom = new THREE.BoxGeometry(1,1,1);
		let boxMat  = new THREE.MeshPhongMaterial({color: 0xCF0000});
		let box     = new THREE.Mesh (boxGeom, boxMat);

		box.position.y = 0.5;
		this.add (box);
	}

	/*
	 * Crea un directorio de la GUI con título titlegui que permite modificar la
	 * apertura de la grapadora. El valor por defecto de dicha apertura se
	 * especifica en guiControls.
	 *
	 * Al añadir el control de la apertura se especifican, en orden, los valores
	 * mínimo, máximo e incremento.
	 */

	createGUI (gui, titleGui)
	{
		this.guiControls = new function ()
		{
			this.sizeX = 1.0;
			this.sizeY = 1.0;
			this.sizeZ = 1.0;

			this.rotX = 0.0;
			this.rotY = 0.0;
			this.rotZ = 0.0;

			this.posX = 0.0;
			this.posY = 0.0;
			this.posZ = 0.0;

			this.reset = function ()
			{
				this.sizeX = 1.0;
				this.sizeY = 1.0;
				this.sizeZ = 1.0;

				this.rotX = 0.0;
				this.rotY = 0.0;
				this.rotZ = 0.0;

				this.posX = 0.0;
				this.posY = 0.0;
				this.posZ = 0.0;
			}
		}

		var folder = gui.addFolder (titleGui);

		folder.add(
			this.guiControls, 'sizeX',
			0.1, 5.0, 0.1
		).name('Tamaño X').listen();

		folder.add(
			this.guiControls, 'sizeY',
			0.1, 5.0, 0.1
		).name('Tamaño Y').listen();

		folder.add(
			this.guiControls, 'sizeZ',
			0.1, 5.0, 0.1
		).name('Tamaño Z').listen();

		folder.add(
			this.guiControls, 'rotX',
			0.0, Math.PI/2, 0.1
		).name('Rotación X').listen();

		folder.add(
			this.guiControls, 'rotY',
			0.0, Math.PI/2, 0.1
		).name('Rotación Y').listen();

		folder.add(
			this.guiControls, 'rotZ',
			0.0, Math.PI/2, 0.1
		).name('Rotación Z').listen();

		folder.add(
			this.guiControls, 'posX',
			-20.0, 20.0, 0.1
		).name('Posición X').listen();

		folder.add(
			this.guiControls, 'posY',
			0.0, 10.0, 0.1
		).name('Posición Y').listen();

		folder.add(
			this.guiControls, 'posZ',
			-20.0, 20.0, 0.1
		).name('Posición Z').listen();

		folder.add(this.guiControls, 'reset').name ('[ Reset ]');
	}

	/*
	 * La actualización de la Caja consiste en modificar su posición en la escena,
	 * su rotación y su escalado siguiendo la regla de TRES de las transformaciones.
	 */

	update ()
	{
		this.position.set(this.guiControls.posX,this.guiControls.posY,this.guiControls.posZ);
		this.rotation.set(this.guiControls.rotX,this.guiControls.rotY,this.guiControls.rotZ);
		this.scale.set(this.guiControls.sizeX,this.guiControls.sizeY,this.guiControls.sizeZ);
	}
}

export { MyBox };
