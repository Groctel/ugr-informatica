import * as THREE from '../libs/three.module.js'
import * as TWEEN from '../libs/tween.esm.js'

class MyMovingObject extends THREE.Object3D
{
	constructor ()
	{
		super();

		this.constructTours();

		this.mesh = this.constructMesh();
		this.add(this.mesh);

		const origin_pint  = {p:0};
		const end_point = {p:1};

		this.shift_right = new TWEEN.Tween(origin_pint)
			.to(end_point, 4000)
			.easing(TWEEN.Easing.Quartic.InOut)
			.onUpdate(() =>
			{
				const t        = origin_pint.p;
				const posicion = this.right_path.getPointAt(t);
				const tangente = this.right_path.getTangentAt(t);

				this.mesh.position.copy(posicion);
				posicion.add(tangente);
				this.mesh.lookAt(posicion);
			})
			.onComplete(() =>
			{
				origin_pint.p = 0;
			})
			.start();

		this.shift_left = new TWEEN.Tween(origin_pint)
			.to(end_point, 8000)
			.easing(TWEEN.Easing.Quartic.InOut)
			.onUpdate(() =>
			{
				var t        = origin_pint.p;
				var posicion = this.left_path.getPointAt(t);
				var tangente = this.left_path.getTangentAt(t);

				this.mesh.position.copy(posicion);
				posicion.add(tangente);
				this.mesh.lookAt(posicion);
			})
			.onComplete(() =>
			{
				origin_pint.p = 0;
			})
			.start();

		this.shift_right.chain(this.shift_left);
		this.shift_left.chain(this.shift_right);
	}

	constructMesh ()
	{
		const cone = new THREE.Mesh(
			new THREE.ConeGeometry(0.5, 3.0, 10),
			new THREE.MeshPhongMaterial({color : 0x00CF00})
		);
		cone.rotation.x = Math.PI/2;

		const mesh = new THREE.Object3D();
		mesh.add(cone);

		return mesh;
	}

	constructTours ()
	{
		const material = new THREE.LineBasicMaterial({color : 0x000000});

		this.right_path = new THREE.CatmullRomCurve3([
			new THREE.Vector3 (0,  0,  0),
			new THREE.Vector3 (13, 1,  10),
			new THREE.Vector3 (16, 3,  13),
			new THREE.Vector3 (20, 5,  13),
			new THREE.Vector3 (24, 7,  13),
			new THREE.Vector3 (25, 12, 10),
			new THREE.Vector3 (26, 12, 0),
			new THREE.Vector3 (24, 7,  -13),
			new THREE.Vector3 (20, 5,  -13),
			new THREE.Vector3 (16, 3,  -12),
			new THREE.Vector3 (13, 1,  -10),
			new THREE.Vector3 (0,  0,  0)
		]);

		const right_tour    = new THREE.Geometry();
		right_tour.vertices = this.right_path.getPoints(100);

		this.add(new THREE.Line(right_tour, material));

		this.left_path = new THREE.CatmullRomCurve3([
			new THREE.Vector3 (0,   0, 0),
			new THREE.Vector3 (-13, 0, 13),
			new THREE.Vector3 (-20, 0, 15),
			new THREE.Vector3 (-24, 0, 13),
			new THREE.Vector3 (-25, 0, 10),
			new THREE.Vector3 (-26, 0, 0),
			new THREE.Vector3 (-24, 0, -13),
			new THREE.Vector3 (-20, 0, -15),
			new THREE.Vector3 (-13, 0, -13),
			new THREE.Vector3 (0,   0, 0)
		]);

		const left_tour    = new THREE.Geometry();
		left_tour.vertices = this.left_path.getPoints(100);

		this.add(new THREE.Line(left_tour, material));
	}

	update ()
	{
		TWEEN.update();
	}
}

export { MyMovingObject }

