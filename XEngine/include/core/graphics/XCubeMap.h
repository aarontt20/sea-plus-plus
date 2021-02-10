
//==================================================================================\\
//FILE NAME:			XCubeMap.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/21/2017													\\
//LAST MODIIFED:		05/21/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_CUBE_MAP_H
#define X_CUBE_MAP_H


#define GLEW_STATIC
#include "GL\glew.h"
#include "core\math\XMath.h"
#include "core\graphics\XImage.h"


namespace X {	namespace Graphics {
	
	class CubeMap {
		friend class ShaderGL;
		friend struct GLFrameBuffer;
	private:
		GLuint GLCubeMap;

	public:
		CubeMap();
		CubeMap(Image *right, Image *left, Image *top, Image *bottom, Image *front, Image *back);
		CubeMap(Image *sides);

		void generate();
		void destroy();

		void bind()  const;
		void unbind() const;

		void setParameter(GLenum parameter, GLint value);
		void setParameter(GLenum parameter, GLfloat value);
		void setParameter(GLenum parameter, const X::Math::Vector4i &value);
		void setParameter(GLenum parameter, const X::Math::Vector4 &value);
	};

}}



#endif // !X_CUBE_MAP_H
