import * as THREE from '/libs/three.module.js'
import * as TWEEN from '/libs/tween.esm.js'

class MyMovingObject extends THREE.Object3D
{
	constructor ()
	{
		super();

		this.constructTours();

		this.mesh = this.constructMesh();
		this.add(this.mesh);

		const origin_point  = {p:0};
		const end_point = {p:1};

		this.shift_right = new TWEEN.Tween(origin_point)
			.to(end_point, 4000)
			.easing(TWEEN.Easing.Quartic.InOut)
			.onUpdate(() =>
			{
				const t        = origin_point.p;
				const posicion = this.bot_path.getPointAt(t);
				const tangente = this.bot_path.getTangentAt(t);

				this.mesh.position.copy(posicion);
				posicion.add(tangente);
				this.mesh.lookAt(posicion);
			})
			.onComplete(() =>
			{
				origin_point.p = 0;
			})
			.start();

		this.shift_left = new TWEEN.Tween(origin_point)
			.to(end_point, 8000)
			.easing(TWEEN.Easing.Quartic.InOut)
			.onUpdate(() =>
			{
				const t        = origin_point.p;
				const posicion = this.top_path.getPointAt(t);
				const tangente = this.top_path.getTangentAt(t);

				this.mesh.position.copy(posicion);
				posicion.add(tangente);
				this.mesh.lookAt(posicion);
			})
			.onComplete(() =>
			{
				origin_point.p = 0;
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
		const material = new THREE.LineBasicMaterial({color: 0xff0000});

		this.bot_path = new THREE.CatmullRomCurve3([
			new THREE.Vector3(-5,   0, 0),
			new THREE.Vector3(-5,   0, 20),
			new THREE.Vector3(-2.5, 0, 20),
			new THREE.Vector3(0,    0, 20),
			new THREE.Vector3(2.5,  0, 20),
			new THREE.Vector3(5,    0, 20),
			new THREE.Vector3(5,    0, 0)
		]);

		const right_tour    = new THREE.Geometry();
		right_tour.vertices = this.bot_path.getPoints(100);

		this.add(new THREE.Line(right_tour, material));

		this.top_path = new THREE.CatmullRomCurve3([
			new THREE.Vector3(5,   0, 0),
			new THREE.Vector3(5, 0, -7),
			new THREE.Vector3(10, 0, -8),
			new THREE.Vector3(10, 0, -20),
			new THREE.Vector3(10, 0, -20),
			new THREE.Vector3(2.5, 0, -20),
			new THREE.Vector3(0, 0, -20),
			new THREE.Vector3(-2.5, 0, -20),
			new THREE.Vector3(-5, 0, -20),
			new THREE.Vector3(-5,   0, 0)
		]);

		const left_tour    = new THREE.Geometry();
		left_tour.vertices = this.top_path.getPoints(100);

		this.add(new THREE.Line(left_tour, material));
	}

	update ()
	{
		TWEEN.update();
	}
}

export { MyMovingObject }

