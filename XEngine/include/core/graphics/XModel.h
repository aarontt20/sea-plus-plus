
//==================================================================================\\
//FILE NAME:			XModel.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/09/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef X_MODEL_H
#define X_MODEL_H


#include "XMesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"


namespace X {	namespace Graphics {

	class Model {
	private:
		std::vector<Mesh> meshes;

		Mesh processRawMesh(aiMesh* mesh, const aiScene* scene);
		void processNode(aiNode* node, const aiScene* scene);

	public:
		Model();
		Model(const char * path);

		void render();

		void destroy();
	};
}}

#endif // !X_MODEL_H
