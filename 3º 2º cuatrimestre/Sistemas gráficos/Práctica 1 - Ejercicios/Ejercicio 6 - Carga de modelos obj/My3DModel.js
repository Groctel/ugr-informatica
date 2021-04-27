import * as THREE from '/libs/three.module.js'

import { OBJLoader } from '/libs/OBJLoader.js'
import { MTLLoader } from '/libs/MTLLoader.js'

class My3DModel extends THREE.Object3D
{
	constructor (obj_path, mtl_path)
	{
		super();

		const obj_loader = new OBJLoader();
		const mtl_loader = new MTLLoader();

		mtl_loader.load(mtl_path, (mtl) =>
		{
			mtl.preload();
			obj_loader.setMaterials(mtl);
			obj_loader.load(obj_path, (root) =>
			{
				root.scale.set(5, 5, 5);
				root.translateY(3);
				this.add(root);
			});
		});
	}

	update ()
	{
		this.rotation.y += 0.01;
	}
}

export { My3DModel };
