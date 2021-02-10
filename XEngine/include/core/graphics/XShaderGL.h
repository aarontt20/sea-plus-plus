
//==================================================================================\\
//FILE NAME:			XShaderGL.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/09/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_SHADER_GL_H
#define X_SHADER_GL_H


#define GLEW_STATIC
#include "GL\glew.h"
#include <vector>
#include "core\math\XMath.h"
#include "XTexture2D.h"
#include "core\graphics\XCubeMap.h"

namespace X {	namespace Graphics {

	struct ShaderVertexAttribute {
		int index;
		const char *name;

		ShaderVertexAttribute();
		ShaderVertexAttribute(const int &index, const char *name);
	};

	class ShaderGL {
	private:
		GLuint shaderProgram;

	public:
		ShaderGL();
		ShaderGL(const char *vertShaderSource, const char *tesselationControlShaderSource, const char *tesselationEvaluationShaderSource, const char *geometryShaderSource, const char *fragmentShaderSource, const std::vector<ShaderVertexAttribute>* explicitVertexAtrributes);
		~ShaderGL();

		int getUniformLocation(const char *name);

		void setUniform(const char *name, const unsigned int &v0);
		void setUniform(const char *name, const unsigned int &v0, const unsigned int &v1);
		void setUniform(const char *name, const unsigned int &v0, const unsigned int &v1, const unsigned int &v2);
		void setUniform(const char *name, const unsigned int &v0, const unsigned int &v1, const unsigned int &v2, const unsigned int &v3);
		void setUniform(const char *name, const int &v0);
		void setUniform(const char *name, const int &v0, const int &v1);
		void setUniform(const char *name, const int &v0, const int &v1, const int &v2);
		void setUniform(const char *name, const int &v0, const int &v1, const int &v2, const int &v3);
		void setUniform(const char *name, const float &v0);
		void setUniform(const char *name, const float &v0, const float &v1);
		void setUniform(const char *name, const float &v0, const float &v1, const float &v2);
		void setUniform(const char *name, const float &v0, const float &v1, const float &v2, const float &v3);
		void setUniform(const char *name, const double &v0);
		void setUniform(const char *name, const double &v0, const double &v1);
		void setUniform(const char *name, const double &v0, const double &v1, const double &v2);
		void setUniform(const char *name, const double &v0, const double &v1, const double &v2, const double &v3);
		void setUniform(const char *name, const int &count, const unsigned int *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector2u *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector3u *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector4u *value);
		void setUniform(const char *name, const int &count, const int *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector2i *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector3i *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector4i *value);
		void setUniform(const char *name, const int &count, const float *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector2 *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector3 *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector4 *value);
		void setUniform(const char *name, const int &count, const double *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector2d *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector3d *value);
		void setUniform(const char *name, const int &count, const X::Math::Vector4d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x3 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x4 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x2 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x4 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x2 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x3 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4 *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x3d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x4d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x2d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x4d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x2d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x3d *value);
		void setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4d *value);
		void setUniform(const char *name, const X::Graphics::Texture2D *texture, const unsigned int &textureUnit);
		void setUniform(const char *name, const X::Graphics::CubeMap *cubeMap, const unsigned int &textureUnit);

		void bind();
		void unbind();
	};

}}


#endif // !X_SHADER_GL_H
