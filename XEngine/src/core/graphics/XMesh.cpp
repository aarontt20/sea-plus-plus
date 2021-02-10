
//==================================================================================\\
//FILE NAME:			XMesh.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/09/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XMesh.h"


namespace X {	namespace Graphics {

	Vertex::Vertex() {	}
	Vertex::Vertex(const X::Math::Vector3 &pos) {
		this->position = pos;
	}
	Vertex::Vertex(const X::Math::Vector3 &pos, const X::Math::Vector3 & norm) {
		this->position = pos;
		this->normal = norm;
	}
	Vertex::Vertex(const X::Math::Vector3 &pos, const X::Math::Vector3 & norm, const X::Math::Vector2 &texCoord) {
		this->position = pos;
		this->normal = norm;
		this->textureCoordinate = texCoord;
	}
	Mesh::Mesh() {	}
	Mesh::Mesh(const std::vector<Vertex> &verts) {
		this->vertices = verts;

		this->VAO.generate();
		this->VAO.bind();

		this->VBO = GLBuffer(GL_ARRAY_BUFFER, this->vertices, GL_STATIC_DRAW);
		this->VBO.bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(sizeof(X::Math::Vector3)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(sizeof(X::Math::Vector3) * 2));

		this->VAO.unbind();
	}
	Mesh::Mesh(const std::vector<Vertex> &verts, const std::vector<GLuint> &inds) {
		this->vertices = verts;
		this->indices = inds;

		this->VAO.generate();
		this->VAO.bind();

		this->VBO = GLBuffer(GL_ARRAY_BUFFER, this->vertices, GL_STATIC_DRAW);
		this->VBO.bind();

		this->EBO = GLBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices, GL_STATIC_DRAW);
		this->EBO.bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(sizeof(X::Math::Vector3)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(sizeof(X::Math::Vector3) * 2));

		this->VAO.unbind();
	}
	void Mesh::render() {
		this->VAO.bind();
		if (this->indices.size() > 0) {
			glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
		}
		else {
			glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
		}
		this->VAO.unbind();
	}
	void Mesh::destroy() {
		this->EBO.destroy();
		this->VBO.destroy();
		this->VAO.destroy();
	}
	std::vector<X::Graphics::Vertex> Mesh::getVertices() {
		return this->vertices;
	}
	std::vector<GLuint> Mesh::getIndices() {
		return this->indices;
	}
}}