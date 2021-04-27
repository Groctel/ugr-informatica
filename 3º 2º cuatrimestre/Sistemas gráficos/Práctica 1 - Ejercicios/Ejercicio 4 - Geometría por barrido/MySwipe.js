import * as THREE from '/libs/three.module.js'

let swipe_properties = {
	steps: 50,
	curveSegments: 20,
	extrudePath: null
};

class MySwipe extends THREE.Object3D {
	constructor ()
	{
		super();

		const shape = this.createShape();

		swipe_properties.extrudePath = new THREE.CatmullRomCurve3([
			new THREE.Vector3(-20, 5,  0),
			new THREE.Vector3(-15, 5,  15),
			new THREE.Vector3(-10, 0,  10),
			new THREE.Vector3(-5,  5,  5),
			new THREE.Vector3(0,   0,  0),
			new THREE.Vector3(5,   -5, 5),
			new THREE.Vector3(10,  0,  10),
			new THREE.Vector3(15,  5,  15),
			new THREE.Vector3(20,  5,  0)
		]);

		const geometry = new THREE.ExtrudeGeometry(shape, swipe_properties);
		const material = new THREE.MeshPhongMaterial({color: 0x00ff00});

		this.mesh = new THREE.Mesh(geometry, material) ;
		this.mesh.scale.set(0.6,0.3,0.3);
		this.rotation.z = Math.PI/2;

		this.add(this.mesh);
	}

	createShape ()
	{
		var shape = new THREE.Shape();

		var x = -2.5;
		var y = -4.0;
		shape.moveTo(x + 2.5, y + 2.5);
		shape.bezierCurveTo(x + 2.5, y + 2.5, x + 2,   y,       x,       y);
		shape.bezierCurveTo(x - 3,   y,       x - 3,   y + 3.5, x - 3,   y + 3.5);
		shape.bezierCurveTo(x - 3,   y + 5.5, x - 1.5, y + 7.7, x + 2.5, y + 9.5);
		shape.bezierCurveTo(x + 6,   y + 7.7, x + 8,   y + 4.5, x + 8,   y + 3.5);
		shape.bezierCurveTo(x + 8,   y + 3.5, x + 8,   y,       x + 5,   y);
		shape.bezierCurveTo(x + 3.5, y,       x + 2.5, y + 2.5, x + 2.5, y + 2.5);

		return shape;
	}

	update ()
	{
		this.rotation.y += 0.02;
	}
}

export { MySwipe };
