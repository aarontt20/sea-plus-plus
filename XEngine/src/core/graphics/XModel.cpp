
//==================================================================================\\
//FILE NAME:			XModel.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/09/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XModel.h"
#include <iostream>


namespace X {	namespace Graphics {

	Mesh Model::processRawMesh(aiMesh* mesh, const aiScene* scene) {
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;

		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			Vertex vertex;

			vertex.position.x = mesh->mVertices[i].x;
			vertex.position.y = mesh->mVertices[i].y;
			vertex.position.z = mesh->mVertices[i].z;

			vertex.normal.x = mesh->mNormals[i].x;
			vertex.normal.y = mesh->mNormals[i].y;
			vertex.normal.z = mesh->mNormals[i].z;

			if (mesh->mTextureCoords[0]) {
				vertex.textureCoordinate.x = mesh->mTextureCoords[0][i].x;
				vertex.textureCoordinate.y = mesh->mTextureCoords[0][i].y;
			}


			vertices.push_back(vertex);
		}

		for (int f = 0; f < mesh->mNumFaces; f++) {
			aiFace face = mesh->mFaces[f];

			for (int i = 0; i < face.mNumIndices; i++) {
				indices.push_back(face.mIndices[i]);
			}
		}

		return Mesh(vertices, indices);
	}
	void Model::processNode(aiNode* node, const aiScene* scene) {
		for (GLuint i = 0; i < node->mNumMeshes; i++)
		{
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			this->meshes.push_back(this->processRawMesh(mesh, scene));
		}
		for (GLuint i = 0; i < node->mNumChildren; i++)
		{
			this->processNode(node->mChildren[i], scene);
		}
	}

	Model::Model() {

	}
	Model::Model(const char * path) {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path,
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_RemoveRedundantMaterials |
			aiProcess_OptimizeGraph |
			aiProcess_OptimizeMeshes |
			aiProcess_SplitLargeMeshes |
			aiProcess_JoinIdenticalVertices |
			aiProcess_ImproveCacheLocality |
			aiProcess_ValidateDataStructure);

		if (!scene) {
			std::cout << importer.GetErrorString() << std::endl;
		}
		else	this->processNode(scene->mRootNode, scene);
	}

	void Model::render() {
		for each (Mesh m in this->meshes) {
			m.render();
		}
	}

	void Model::destroy() {
		for each (Mesh m in this->meshes) {
			m.destroy();
		}
	}
}}
