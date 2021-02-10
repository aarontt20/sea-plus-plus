
//==================================================================================\\
//FILE NAME:			XMesh.h														\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/09/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_MESH_H
#define X_MESH_H


#define GLEW_STATIC
#include "GL\glew.h"
#include <vector>
#include "XGLVertexArray.h"
#include "XGLBuffer.h"
#include "core\math\XMath.h"


namespace X {	namespace Graphics {

	struct Vertex {
		X::Math::Vector3 position;
		X::Math::Vector3 normal;
		X::Math::Vector2 textureCoordinate;

		Vertex();
		Vertex(const X::Math::Vector3 &pos);
		Vertex(const X::Math::Vector3 &pos, const X::Math::Vector3 & norm);
		Vertex(const X::Math::Vector3 &pos, const X::Math::Vector3 & norm, const X::Math::Vector2 &texCoord);
	};

	class Mesh {
	private:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		GLVertexArray VAO;
		GLBuffer VBO, EBO;
	
	public:
		Mesh();
		Mesh(const std::vector<Vertex> &verts);
		Mesh(const std::vector<Vertex> &verts, const std::vector<GLuint> &inds);
	
		void render();
	
		void destroy();

		std::vector<Vertex> getVertices();

		std::vector<GLuint> getIndices();
	};
}}

#include "../src/core/graphics/Mesh.inl"

#endif // !X_MESH_H
