import * as THREE from '/libs/three.module.js'

class MySpade extends THREE.Object3D {
	constructor (properties, radius)
	{
		super();

		const head_outline = new THREE.Shape();

		head_outline.moveTo(2.5, 2.5);
		head_outline.bezierCurveTo(2.5, 2.5, 2,    0,   0,   0);
		head_outline.bezierCurveTo(-3,  0,   -3,   3.5, -3,  3.5);
		head_outline.bezierCurveTo(-3,  5.5, -1.5, 7.7, 2.5, 9.5);
		head_outline.bezierCurveTo(6,   7.7, 8,    5.5, 8,   3.5);
		head_outline.bezierCurveTo(8,   3.5, 8,    0,   5,   0);
		head_outline.bezierCurveTo(3.5, 0,   2.5,  2.5, 2.5, 2.5);

		const head_geometry = new THREE.ExtrudeGeometry(head_outline, properties);
		const head_material = new THREE.MeshToonMaterial({color: 0x0000ff});
		this.head_mesh      = new THREE.Mesh(head_geometry, head_material);

		const body_outline = new THREE.Shape();

		body_outline.moveTo(2.5, 3);
		body_outline.lineTo(3.5, -3);
		body_outline.lineTo(1.5, -3);

		const body_geometry = new THREE.ExtrudeGeometry(body_outline, properties);
		const body_material = new THREE.MeshToonMaterial({color: 0x0000ff});
		this.body_mesh      = new THREE.Mesh(body_geometry, body_material);

		this.mesh = new THREE.Object3D();
		this.mesh.add(this.head_mesh);
		this.mesh.add(this.body_mesh);

		this.rotation_obj = new THREE.Object3D();
		this.rotation_obj.position.y = -radius;
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

export { MySpade };
