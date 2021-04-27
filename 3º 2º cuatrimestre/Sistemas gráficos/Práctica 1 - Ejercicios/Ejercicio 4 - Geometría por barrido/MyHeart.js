import * as THREE from '../libs/three.module.js'

class MyHeart extends THREE.Object3D
{
	constructor (properties, radius)
	{
		super();

		const outline = new THREE.Shape();

		outline.moveTo(2.5, 2.5);
		outline.bezierCurveTo(2.5, 2.5, 2,    0,   0,   0);
		outline.bezierCurveTo(-3,  0,   -3,   3.5, -3,  3.5);
		outline.bezierCurveTo(-3,  5.5, -1.5, 7.7, 2.5, 9.5);
		outline.bezierCurveTo(6,   7.7, 8,    5.5, 8,   3.5);
		outline.bezierCurveTo(8,   3.5, 8,    0,   5,   0);
		outline.bezierCurveTo(3.5, 0,   2.5,  2.5, 2.5, 2.5);

		const geometry = new THREE.ExtrudeGeometry(outline, properties);
		const material = new THREE.MeshToonMaterial({color: 0xff0000});
		this.mesh      = new THREE.Mesh(geometry, material);
		this.mesh.rotateX(Math.PI);

		this.rotation_obj = new THREE.Object3D();
		this.rotation_obj.position.x = radius;
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

export { MyHeart };
