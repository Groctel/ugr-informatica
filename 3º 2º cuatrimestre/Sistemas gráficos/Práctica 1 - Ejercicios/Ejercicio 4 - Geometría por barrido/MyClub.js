import * as THREE from '/libs/three.module.js'

class MyClub extends THREE.Object3D
{
	constructor (properties, radius)
	{
		super();

		const leaf_center = this.constructLeaf(0,    4, 3, properties);
		const leaf_right  = this.constructLeaf(2.5,  0, 3, properties);
		const leaf_left   = this.constructLeaf(-2.5, 0, 3, properties);

		const body_outline = new THREE.Shape();

		body_outline.moveTo(0,  -1);
		body_outline.lineTo(1,  -5);
		body_outline.lineTo(-1, -5);

		const geometry = new THREE.ExtrudeGeometry(body_outline, properties);
		const material = new THREE.MeshToonMaterial({color: 0x0000ff});
		const body     = new THREE.Mesh(geometry, material);

		this.mesh = new THREE.Object3D();
		this.mesh.add(leaf_center);
		this.mesh.add(leaf_left);
		this.mesh.add(leaf_right);
		this.mesh.add(body);

		this.rotation_obj = new THREE.Object3D();
		this.rotation_obj.position.y = radius;
		this.rotation_obj.add(this.mesh);

		this.traslation_obj = new THREE.Object3D();
		this.traslation_obj.add(this.rotation_obj);

		this.add(this.traslation_obj);
	}

	constructLeaf (x, y, radius, properties)
	{
		/*
		 * De forma absolutamente idiótica y estúpida creamos el círculo con una
		 * revolución de 1.99999PI. ¿Por qué? Porque la informática es así.
		 */

		const outline  = new THREE.Shape().absarc(x, y, radius, 0, 1.99999*Math.PI);
		const geometry = new THREE.ExtrudeGeometry(outline, properties);
		const material = new THREE.MeshToonMaterial({color: 0x0000ff});
		material.side  = THREE.DoubleSide;

		return new THREE.Mesh(geometry, material);
	}

	/*
	 * El movimiento se hace primero en el eje de traslación, luego se compensa
	 * en el eje de rotación para mantener la rotationidad de la figura y, por
	 * último, se rota alrededor del eje Y.
	 */

	update ()
	{
		this.traslation_obj.rotation.z += 0.01;
		this.rotation_obj.rotation.z -= 0.01;
		this.mesh.rotation.y += 0.02;
	}
}

export { MyClub };
