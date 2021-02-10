
//==================================================================================\\
//FILE NAME:			XGLVBuffer.h												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/09/2017													\\
//LAST MODIIFED:		05/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef X_GL_BUFFER_H
#define X_GL_BUFFER_H


#define GLEW_STATIC
#include "GL\glew.h"
#include <vector>


namespace X {	namespace Graphics {

		struct GLBuffer {
		private:
			GLuint buffer;
			GLenum targetBinding;
			GLenum usage;

		public:
			GLBuffer();
			GLBuffer(GLenum targetBinding, const void *data, const int &byteSize, GLenum usage);
			template <typename T> GLBuffer(GLenum targetBinding, const std::vector<T> &data, GLenum usage);

			void generate();
			void destroy();

			void bind() const;
			void unbind() const;
		};

}}

#include "../src/core/graphics/XGLBuffer.inl"

#endif // !X_GL_BUFFER_H
