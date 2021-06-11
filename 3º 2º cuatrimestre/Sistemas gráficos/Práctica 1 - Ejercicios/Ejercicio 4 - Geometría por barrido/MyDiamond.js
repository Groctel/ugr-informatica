import * as THREE from '/libs/three.module.js'

class MyDiamond extends THREE.Object3D
{
	constructor (properties, radius)
	{
		super();

		var outline = new THREE.Shape();

		outline.moveTo(0,      4.75);
		outline.lineTo(2.375,  0);
		outline.lineTo(0,      -4.75);
		outline.lineTo(-2.375, 0);
		outline.lineTo(0,      4.75);

		const  geometry = new THREE.ExtrudeGeometry(outline, properties);
		const material  = new THREE.MeshToonMaterial({color: 0xff0000});
		this.mesh       = new THREE.Mesh(geometry, material);

		this.rotation_obj = new THREE.Object3D();
		this.rotation_obj.position.x = -radius;
		this.rotation_obj.add(this.mesh);

		this.traslation_obj = new THREE.Object3D();
		this.traslation_obj.add(this.rotation_obj);

		this.add(this.traslation_obj);
	}

	/*
	 * El movimiento se hace primero en el eje de traslación, luego se compensa
	 * en el eje de rotación para mantener la rotationidad de la figura y, por
	 * último, se rota alrededor del eje Y.
	 */

	update ()
	{
		this.traslation_obj.rotation.z += 0.01;
		this.rotation_obj.rotation.z   -= 0.01;
		this.mesh.rotation.y           += 0.02;
	}
}

export { MyDiamond };
