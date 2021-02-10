
//==================================================================================\\
//FILE NAME:			XTexture2D.h												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/07/2017													\\
//LAST MODIIFED:		05/07/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef X_TEXTURE_2D_H
#define X_TEXTURE_2D_H


#define GLEW_STATIC
#include "GL\glew.h"
#include "core\math\XMath.h"


namespace X {	namespace Graphics {
	
	class Image;

	class Texture2D {
		friend class ShaderGL;
		friend class GLFrameBuffer;
	private:
		GLuint GLTexture;

		void generate();
		void destroy();

		void bind() const;
		void unbind() const;
	public:
		Texture2D();
		Texture2D(Image& image);
		Texture2D(GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLenum pixleFormat, GLenum dataType, const GLvoid *pixles);
		~Texture2D();
		void setParameter(GLenum parameter, GLint value);
		void setParameter(GLenum parameter, GLfloat value);
		void setParameter(GLenum parameter, const X::Math::Vector4i &value);
		void setParameter(GLenum parameter, const X::Math::Vector4 &value);
	};
}}

#endif // !X_TEXTURE_2D_H
