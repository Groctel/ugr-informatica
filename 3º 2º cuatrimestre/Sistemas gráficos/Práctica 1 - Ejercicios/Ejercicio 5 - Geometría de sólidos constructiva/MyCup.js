import * as THREE from '../libs/three.module.js'

import { ThreeBSP } from '../libs/ThreeBSP.js'

class MyCup extends THREE.Object3D
{
	constructor ()
	{
		super();

		const outline_cylinder = new THREE.CylinderGeometry(10.0, 10.0, 20.0, 30);
		const fill_cylinder    = new THREE.CylinderGeometry(10.0, 10.0, 20.0, 30);
		const handle           = new THREE.TorusGeometry(4.0, 1.0, 30.0, 30.0);

		fill_cylinder.scale(0.9, 1.0, 0.9);
		fill_cylinder.translate(0.0, 0.4, 0.0);
		handle.scale(1.5, 1.5, 1.5).translate(10.0, 0.1, 0.0);

		const outline_cylinder_bsp = new ThreeBSP(outline_cylinder);
		const fill_cylinder_bsp    = new ThreeBSP(fill_cylinder);
		const handle_bsp           = new ThreeBSP(handle);

		const body     = outline_cylinder_bsp.union(handle_bsp);
		const geometry = body.subtract(fill_cylinder_bsp);

		const material = new THREE.MeshPhongMaterial({color: 0x141414});
		this.mesh  = geometry.toMesh(material);
		this.mesh.geometry.computeFaceNormals();
		this.mesh.geometry.computeVertexNormals();

		this.add(this.mesh);
	}
}

export { MyCup };
