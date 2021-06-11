import * as THREE from '../libs/three.module.js'

class Grapadora extends THREE.Object3D
{
	/*
	 * Creamos la GUI primero para permitir a los métodos llamados después usarla.
	 * Luego asignamos el material y creamos la base y el móvil. Estos dos últimos
	 * se añaden al objeto. Como la base no la vamos a modificar, la almacenamos
	 * como una variable local al constructor. Sin embargo, la parte móvil la
	 * tenemos que declarar como atributo de la Grapadora para poder modificarla
	 * más tarde.
	 */

	constructor(gui, titleGui)
	{
		super();

		this.createGUI(gui, titleGui);

		this.material = new THREE.MeshPhongMaterial({color: 0xCF0000});

		let base   = this.createBase();
		this.movil = this.createMovil();

		this.add(base);
		this.add(this.movil);
	}

	/*
	 * Creamos la base como un nodo Object3D que contiene varios hijos de tipo
	 * Mesh. Definimos sus atributos, los añadimos al nodo base y lo devolvemos.
	 */

	createBase()
	{
		let base            = new THREE.Object3D();
		let geometriaPivote = new THREE.ConeGeometry(0.25, 0.6);

		let cajaBase = new THREE.Mesh(new THREE.BoxGeometry(5, 0.4, 1), this.material);
		let pivote1  = new THREE.Mesh(geometriaPivote, this.material);
		let pivote2  = new THREE.Mesh(geometriaPivote, this.material);

		cajaBase.position.y = 0.2;
		pivote1.position.set(2.25, 0.3+0.4,  0.25);
		pivote2.position.set(2.25, 0.3+0.4, -0.25);

		base.add(cajaBase);
		base.add(pivote1);
		base.add(pivote2);

		return base;
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
			this.rotacion = 0;
		}

		var folder = gui.addFolder(titleGui);

		folder.add(
			this.guiControls, 'rotacion',
			-0.1, 0.125, 0.001
		).name('Apertura');
	}

	/*
	 * Creamos la parte móvil  como un nodo Object3D que contiene un objeto de
	 * tipo Mesh. Definimos sus atributos, los añadimos al nodo movil y lo
	 * devolvemos.
	 */

	createMovil ()
	{
		let movil     = new THREE.Object3D();
		let cajaMovil = new THREE.Mesh(new THREE.BoxGeometry(5, 0.6, 1), this.material);

		movil.rotation.z = this.guiControls.rotacion;
		movil.position.set(2.25,1,0);
		cajaMovil.position.set(-2.25, 0.3, 0);

		movil.add(cajaMovil);

		return movil;
	}

	/*
	 * La actualización de la Grapadora consiste en modificar la rotazón de su
	 * parte móvil en el eje Z en función del valor indicado en la GUI.
	 */

	update ()
	{
		this.movil.rotation.z = this.guiControls.rotacion;
	}
}

export { Grapadora }
