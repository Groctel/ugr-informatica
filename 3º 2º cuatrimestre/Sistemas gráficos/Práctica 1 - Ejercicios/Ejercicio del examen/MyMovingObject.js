import * as THREE from '/libs/three.module.js'
import * as TWEEN from '/libs/tween.esm.js'

import { ThreeBSP } from '/libs/ThreeBSP.js'

class MyMovingObject extends THREE.Object3D
{
	constructor ()
	{
		super();

		this.constructTours();
		this.constructMesh();
		this.constructAnimation();

		this.last_time = Date.now();
	}

	constructAnimation ()
	{
		const origin_point  = {p:0};
		const end_point = {p:1};

		this.shift_bot = new TWEEN.Tween(origin_point)
			.to(end_point, 4000)
			.easing(TWEEN.Easing.Quartic.InOut)
			.onUpdate(() =>
			{
				const t        = origin_point.p;
				const posicion = this.bot_path.getPointAt(t);
				const tangente = this.bot_path.getTangentAt(t);

				this.pacman.position.copy(posicion);
				posicion.add(tangente);
				this.pacman.lookAt(posicion);
			})
			.onComplete(() =>
			{
				origin_point.p = 0;
			})
			.start();

		this.shift_top = new TWEEN.Tween(origin_point)
			.to(end_point, 6000)
			.easing(TWEEN.Easing.Quartic.InOut)
			.onUpdate(() =>
			{
				const t        = origin_point.p;
				const posicion = this.top_path.getPointAt(t);
				const tangente = this.top_path.getTangentAt(t);

				this.pacman.position.copy(posicion);
				posicion.add(tangente);
				this.pacman.lookAt(posicion);
			})
			.onComplete(() =>
			{
				origin_point.p = 0;
			})
			.start();

		this.shift_bot.chain(this.shift_top);
		this.shift_top.chain(this.shift_bot);
	}

	constructMesh ()
	{
		const mouth = new THREE.SphereGeometry(2, 32, 32, 0, Math.PI);
		const head  = new THREE.SphereGeometry(2, 32, 32, Math.PI, Math.PI);
		const eye   = new THREE.CylinderGeometry(0.2, 0.2, 20, 20);

		eye.translate(1, 0, 1);
		eye.rotateZ(Math.PI/2);
		eye.rotateY(Math.PI);

		const mouth_bsp = new ThreeBSP(mouth);
		const head_bsp = new ThreeBSP(head);
		const eye_bsp  = new ThreeBSP(eye);

		const head_geom = head_bsp.subtract(eye_bsp);
		const top       = head_geom.toMesh(
			new THREE.MeshPhongMaterial({color: 0xffff00})
		);

		this.pacman_mouth = mouth_bsp.toMesh(
			new THREE.MeshPhongMaterial({color: 0xffff00})
		);

		this.pacman = new THREE.Object3D();
		this.pacman.add(top);
		this.pacman.add(this.pacman_mouth);

		this.add(this.pacman);
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
		this.pacman_mouth.rotation.x = (1 - Math.sin(Date.now()/100)) * 0.5;
	}
}

export { MyMovingObject }

