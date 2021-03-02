
import * as THREE from '../libs/three.module.js'

class Grapadora extends THREE.Object3D {
  constructor(gui,titleGui) {
    super();
    
    // Se crea la parte de la interfaz que corresponde a la grapadora
    // Se crea primero porque otros métodos usan las variables que se definen para la interfaz
    this.createGUI(gui,titleGui);
    
    // El material se usa desde varios métodos. Por eso se alamacena en un atributo
    this.material = new THREE.MeshPhongMaterial({color: 0xCF0000});
    
    // A la base no se accede desde ningún método. Se almacena en una variable local del constructor.
    var base = this.createBase();
    // Al nodo que contiene la transformación interactiva que abre y cierra la grapadora se accede desde el método update, se almacena en un atributo.
    this.movil = this.createMovil();
    
    // Al nodo  this, la grapadora, se le cuelgan como hijos la base y la parte móvil
    this.add (base);
    this.add (this.movil);
  }
  
  createBase() {
    // El nodo del que van a colgar la caja y los 2 conos y que se va a devolver
    var base = new THREE.Object3D();
    // Cada figura, un Mesh, está compuesto de una geometría y un material
    var cajaBase = new THREE.Mesh (new THREE.BoxGeometry (5,0.4,1), this.material);
    cajaBase.position.y = 0.2;
    // La componente geometría se puede compartir entre varios meshes
    var geometriaPivote = new THREE.ConeGeometry (0.25, 0.6);
    var pivote1 = new THREE.Mesh (geometriaPivote, this.material);
    var pivote2 = new THREE.Mesh (geometriaPivote, this.material);
    // Se posicionan los pivotes con respecto a la base
    pivote1.position.set (2.25, 0.3+0.4,  0.25);
    pivote2.position.set (2.25, 0.3+0.4, -0.25);
    base.add(cajaBase);
    base.add(pivote1);
    base.add(pivote2);
    return base;
  }
  
  createGUI (gui,titleGui) {
    // Controles para el movimiento de la parte móvil
    this.guiControls = new function () {
      this.rotacion = 0;
    } 
    
    // Se crea una sección para los controles de la caja
    var folder = gui.addFolder (titleGui);
    // Estas lineas son las que añaden los componentes de la interfaz
    // Las tres cifras indican un valor mínimo, un máximo y el incremento
    folder.add (this.guiControls, 'rotacion', -0.1, 0.125, 0.001).name ('Apertura : ');
  }
  
  createMovil () {
    // Se crea la parte móvil
    var cajaMovil = new THREE.Mesh (
        new THREE.BoxGeometry (5, 0.6, 1),
        this.material
    );
    cajaMovil.position.set (-2.25, 0.3, 0);
    
    var movil = new THREE.Object3D();
    // IMPORTANTE: Con independencia del orden en el que se escriban las 2 líneas siguientes, SIEMPRE se aplica primero la rotación y después la traslación. Prueba a intercambiar las dos líneas siguientes y verás que no se produce ningún cambio al ejecutar.    
    movil.rotation.z = this.guiControls.rotacion;
    movil.position.set(2.25,1,0);
    movil.add(cajaMovil);
    return movil;
  }
  
  update () {
    // Se actualiza el nodo  this.movil  con el valor de la variable rotacion de la GUI
    this.movil.rotation.z = this.guiControls.rotacion;
  }
}

export { Grapadora }
