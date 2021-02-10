
//==================================================================================\\
//FILE NAME:			XGLVertexArray.h											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/09/2017													\\
//LAST MODIIFED:		05/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef X_GL_VERTEX_ARRAY_H
#define X_GL_VERTEX_ARRAY_H


#define GLEW_STATIC
#include "GL\glew.h"
#include <vector>


namespace X {	namespace Graphics {

	struct GLVertexArray {
	private:
		GLuint VertexArrayObject;

	public:
		void generate();
		void destroy();

		void bind() const;
		void unbind() const;
	};

}}

#endif // !X_GL_
