
//==================================================================================\\
//FILE NAME:			XShaderGL.cpp												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/09/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XShaderGL.h"
#include <fstream>
#include <iostream>

namespace X {	namespace Graphics {

	ShaderVertexAttribute::ShaderVertexAttribute() {
		this->index = -1;
		this->name = "/0";
	}
	ShaderVertexAttribute::ShaderVertexAttribute(const int &index, const char *name) {
		this->index = index;
		this->name = name;
	}
	ShaderGL::ShaderGL() {}
	ShaderGL::ShaderGL(const char *vertShaderSource, const char *tesselationControlShaderSource, const char *tesselationEvaluationShaderSource, const char *geometryShaderSource, const char *fragmentShaderSource, const std::vector<ShaderVertexAttribute>* explicitVertexAtrributes) {
		GLuint vertShader = 0, tessControlShader = 0, tessEvalShader = 0, geomShader = 0, fragShader = 0;

		std::ifstream source;

		if (vertShaderSource) {
			source.open(vertShaderSource, std::ios::in);
			if (source.is_open()) {
				if (source.good()) {
					unsigned long pos = source.tellg();
					source.seekg(0, std::ios::end);
					unsigned long len = source.tellg();
					source.seekg(std::ios::beg);

					GLchar *code = new char[len + 1];
					if (code != 0) {
						code[len] = 0;

						int i = 0;
						while (source.good()) {
							code[i] = source.get();
							if (!source.eof())	i++;
						}

						code[i] = 0;

						vertShader = glCreateShader(GL_VERTEX_SHADER);

						const GLint length = static_cast<GLint>(len);
						glShaderSource(vertShader, 1, &code, &length);

						glCompileShader(vertShader);

						GLint compiled = 0;
						glGetShaderiv(vertShader, GL_COMPILE_STATUS, &compiled);
						if (compiled == GL_FALSE) {
							GLint maxLength = 0;
							glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &maxLength);

							GLchar *errorLog = new GLchar[maxLength];
							glGetShaderInfoLog(vertShader, maxLength, &maxLength, errorLog);

							std::cerr << "ERROR: ShaderGL > the vertex shader source from \"" << vertShaderSource << "\" was unable to be compiled: " << errorLog << std::endl;

							delete[] errorLog;

							glDeleteShader(vertShader);
						}

						delete[] code;
					}
					else	std::cerr << "ERROR: ShaderGL > cannot reserve memory to load vertex shader: " << vertShaderSource << std::endl;
				}
				else	std::cerr << "ERROR: ShaderGL > vertex shader source file \"" << vertShaderSource << "\" is an emtpy file" << std::endl;
			}
			else	std::cerr << "ERROR: ShaderGL > unable to open vertex shader source file: " << vertShaderSource << std::endl;
			source.close();
		}
		if (tesselationControlShaderSource) {
			source.open(tesselationControlShaderSource, std::ios::in);
			if (source.is_open()) {
				if (source.good()) {
					unsigned long pos = source.tellg();
					source.seekg(0, std::ios::end);
					unsigned long len = source.tellg();
					source.seekg(std::ios::beg);

					GLchar *code = new char[len + 1];
					if (code != 0) {
						code[len] = 0;

						int i = 0;
						while (source.good()) {
							code[i] = source.get();
							if (!source.eof())	i++;
						}

						code[i] = 0;

						tessControlShader = glCreateShader(GL_TESS_CONTROL_SHADER);

						const GLint length = static_cast<GLint>(len);
						glShaderSource(tessControlShader, 1, &code, &length);

						glCompileShader(tessControlShader);

						GLint compiled = 0;
						glGetShaderiv(tessControlShader, GL_COMPILE_STATUS, &compiled);
						if (compiled == GL_FALSE) {
							GLint maxLength = 0;
							glGetShaderiv(tessControlShader, GL_INFO_LOG_LENGTH, &maxLength);

							GLchar *errorLog = new GLchar[maxLength];
							glGetShaderInfoLog(tessControlShader, maxLength, &maxLength, errorLog);

							std::cerr << "ERROR: ShaderGL > the tesselation control shader source from \"" << tesselationControlShaderSource << "\" was unable to be compiled: " << errorLog << std::endl;

							delete[] errorLog;

							glDeleteShader(tessControlShader);
						}

						delete[] code;
					}
					else	std::cerr << "ERROR: ShaderGL > cannot reserve memory to load tesselation control shader: " << tesselationControlShaderSource << std::endl;
				}
				else	std::cerr << "ERROR: ShaderGL > tesselation control shader source file \"" << tesselationControlShaderSource << "\" is an emtpy file" << std::endl;
			}
			else	std::cerr << "ERROR: ShaderGL > unable to open tesselation control shader source file: " << tesselationControlShaderSource << std::endl;
			source.close();
		}
		if (tesselationEvaluationShaderSource) {
			source.open(tesselationEvaluationShaderSource, std::ios::in);
			if (source.is_open()) {
				if (source.good()) {
					unsigned long pos = source.tellg();
					source.seekg(0, std::ios::end);
					unsigned long len = source.tellg();
					source.seekg(std::ios::beg);

					GLchar *code = new char[len + 1];
					if (code != 0) {
						code[len] = 0;

						int i = 0;
						while (source.good()) {
							code[i] = source.get();
							if (!source.eof())	i++;
						}

						code[i] = 0;

						tessEvalShader = glCreateShader(GL_TESS_EVALUATION_SHADER);

						const GLint length = static_cast<GLint>(len);
						glShaderSource(tessEvalShader, 1, &code, &length);

						glCompileShader(tessEvalShader);

						GLint compiled = 0;
						glGetShaderiv(tessEvalShader, GL_COMPILE_STATUS, &compiled);
						if (compiled == GL_FALSE) {
							GLint maxLength = 0;
							glGetShaderiv(tessEvalShader, GL_INFO_LOG_LENGTH, &maxLength);

							GLchar *errorLog = new GLchar[maxLength];
							glGetShaderInfoLog(tessEvalShader, maxLength, &maxLength, errorLog);

							std::cerr << "ERROR: ShaderGL > the tesselation evaluation shader source from \"" << tesselationEvaluationShaderSource << "\" was unable to be compiled: " << errorLog << std::endl;

							delete[] errorLog;

							glDeleteShader(tessEvalShader);
						}

						delete[] code;
					}
					else	std::cerr << "ERROR: ShaderGL > cannot reserve memory to load tesselation evaluation shader: " << tesselationEvaluationShaderSource << std::endl;
				}
				else	std::cerr << "ERROR: ShaderGL > tesselation evaluation shader source file \"" << tesselationEvaluationShaderSource << "\" is an emtpy file" << std::endl;
			}
			else	std::cerr << "ERROR: ShaderGL > unable to open tesselation evaluation shader source file: " << tesselationEvaluationShaderSource << std::endl;
			source.close();
		}
		if (geometryShaderSource) {
			source.open(geometryShaderSource, std::ios::in);
			if (source.is_open()) {
				if (source.good()) {
					unsigned long pos = source.tellg();
					source.seekg(0, std::ios::end);
					unsigned long len = source.tellg();
					source.seekg(std::ios::beg);

					GLchar *code = new char[len + 1];
					if (code != 0) {
						code[len] = 0;

						int i = 0;
						while (source.good()) {
							code[i] = source.get();
							if (!source.eof())	i++;
						}

						code[i] = 0;

						geomShader = glCreateShader(GL_GEOMETRY_SHADER);

						const GLint length = static_cast<GLint>(len);
						glShaderSource(geomShader, 1, &code, &length);

						glCompileShader(geomShader);

						GLint compiled = 0;
						glGetShaderiv(geomShader, GL_COMPILE_STATUS, &compiled);
						if (compiled == GL_FALSE) {
							GLint maxLength = 0;
							glGetShaderiv(geomShader, GL_INFO_LOG_LENGTH, &maxLength);

							GLchar *errorLog = new GLchar[maxLength];
							glGetShaderInfoLog(geomShader, maxLength, &maxLength, errorLog);

							std::cerr << "ERROR: ShaderGL > the geometry shader source from \"" << geometryShaderSource << "\" was unable to be compiled: " << errorLog << std::endl;

							delete[] errorLog;

							glDeleteShader(geomShader);
						}

						delete[] code;
					}
					else	std::cerr << "ERROR: ShaderGL > cannot reserve memory to load geometry shader: " << geometryShaderSource << std::endl;
				}
				else	std::cerr << "ERROR: ShaderGL > geometry shader source file \"" << geometryShaderSource << "\" is an emtpy file" << std::endl;
			}
			else	std::cerr << "ERROR: ShaderGL > unable to open geometry shader source file: " << geometryShaderSource << std::endl;
			source.close();
		}
		if (fragmentShaderSource) {
			source.open(fragmentShaderSource, std::ios::in);
			if (source.is_open()) {
				if (source.good()) {
					unsigned long pos = source.tellg();
					source.seekg(0, std::ios::end);
					unsigned long len = source.tellg();
					source.seekg(std::ios::beg);

					GLchar *code = new char[len + 1];
					if (code != 0) {
						code[len] = 0;

						int i = 0;
						while (source.good()) {
							code[i] = source.get();
							if (!source.eof())	i++;
						}

						code[i] = 0;

						fragShader = glCreateShader(GL_FRAGMENT_SHADER);

						const GLint length = static_cast<GLint>(len);
						glShaderSource(fragShader, 1, &code, &length);

						glCompileShader(fragShader);

						GLint compiled = 0;
						glGetShaderiv(fragShader, GL_COMPILE_STATUS, &compiled);
						if (compiled == GL_FALSE) {
							GLint maxLength = 0;
							glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &maxLength);

							GLchar *errorLog = new GLchar[maxLength];
							glGetShaderInfoLog(fragShader, maxLength, &maxLength, errorLog);

							std::cerr << "ERROR: ShaderGL > the fragment shader source from \"" << fragmentShaderSource << "\" was unable to be compiled: " << errorLog << std::endl;

							delete[] errorLog;

							glDeleteShader(fragShader);
						}

						delete[] code;
					}
					else	std::cerr << "ERROR: ShaderGL > cannot reserve memory to load fragment shader: " << fragmentShaderSource << std::endl;
				}
				else	std::cerr << "ERROR: ShaderGL > fragment shader source file \"" << fragmentShaderSource << "\" is an emtpy file" << std::endl;
			}
			else	std::cerr << "ERROR: ShaderGL > unable to open fragment shader source file: " << fragmentShaderSource << std::endl;
			source.close();
		}

		this->shaderProgram = glCreateProgram();

		if (vertShader) {
			glAttachShader(this->shaderProgram, vertShader);
		}
		if (tessControlShader) {
			glAttachShader(this->shaderProgram, tessControlShader);
		}
		if (tessEvalShader) {
			glAttachShader(this->shaderProgram, tessEvalShader);
		}
		if (geomShader) {
			glAttachShader(this->shaderProgram, geomShader);
		}
		if (fragShader) {
			glAttachShader(this->shaderProgram, fragShader);
		}
		int i = 0;
		if (explicitVertexAtrributes) {
			for each (ShaderVertexAttribute a in *explicitVertexAtrributes) {
				glBindAttribLocationARB(this->shaderProgram, a.index, a.name);
				std::cout << i << std::endl;
				i++;
			}
		}

		glLinkProgram(this->shaderProgram);

		if (vertShader) {
			glDetachShader(this->shaderProgram, vertShader);
		}
		if (tessControlShader) {
			glDetachShader(this->shaderProgram, tessControlShader);
		}
		if (tessEvalShader) {
			glDetachShader(this->shaderProgram, tessEvalShader);
		}
		if (geomShader) {
			glDetachShader(this->shaderProgram, geomShader);
		}
		if (fragShader) {
			glDetachShader(this->shaderProgram, fragShader);
		}

		if (vertShader) {
			glDeleteShader(vertShader);
		}
		if (tessControlShader) {
			glDeleteShader(tessControlShader);
		}
		if (tessEvalShader) {
			glDeleteShader(tessEvalShader);
		}
		if (geomShader) {
			glDeleteShader(geomShader);
		}
		if (fragShader) {
			glDeleteShader(fragShader);
		}

		GLint linked;
		glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE) {
			GLint maxLength = 0;
			glGetProgramiv(this->shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

			GLchar *errorLog = new GLchar[maxLength];
			glGetProgramInfoLog(this->shaderProgram, maxLength, &maxLength, errorLog);

			std::cerr << "ERROR: ShaderGL > the shader program \"" << this << "\" was unable to be linked: " << errorLog << std::endl;

			delete[] errorLog;

			glDeleteProgram(this->shaderProgram);
		}
	}
	ShaderGL::~ShaderGL() {
		glDeleteProgram(this->shaderProgram);
	}

	int ShaderGL::getUniformLocation(const char *name) {
		return glGetUniformLocation(this->shaderProgram, name);
	}

	void ShaderGL::setUniform(const char *name, const unsigned int &v0) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1ui(this->getUniformLocation(name), v0);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const unsigned int &v0, const unsigned int &v1) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2ui(this->getUniformLocation(name), v0, v1);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const unsigned int &v0, const unsigned int &v1, const unsigned int &v2) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3ui(this->getUniformLocation(name), v0, v1, v2);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const unsigned int &v0, const unsigned int &v1, const unsigned int &v2, const unsigned int &v3) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4ui(this->getUniformLocation(name), v0, v1, v2, v3);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &v0) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1i(this->getUniformLocation(name), v0);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &v0, const int &v1) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2i(this->getUniformLocation(name), v0, v1);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &v0, const int &v1, const int &v2) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3i(this->getUniformLocation(name), v0, v1, v2);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &v0, const int &v1, const int &v2, const int &v3) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4i(this->getUniformLocation(name), v0, v1, v2, v3);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const float &v0) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1f(this->getUniformLocation(name), v0);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const float &v0, const float &v1) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2f(this->getUniformLocation(name), v0, v1);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const float &v0, const float &v1, const float &v2) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3f(this->getUniformLocation(name), v0, v1, v2);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const float &v0, const float &v1, const float &v2, const float &v3) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4f(this->getUniformLocation(name), v0, v1, v2, v3);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const double &v0) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1d(this->getUniformLocation(name), v0);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const double &v0, const double &v1) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2d(this->getUniformLocation(name), v0, v1);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const double &v0, const double &v1, const double &v2) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3d(this->getUniformLocation(name), v0, v1, v2);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const double &v0, const double &v1, const double &v2, const double &v3) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4d(this->getUniformLocation(name), v0, v1, v2, v3);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const unsigned int *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1uiv(this->getUniformLocation(name), count, &value[0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector2u *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2uiv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector3u *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3uiv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector4u *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4uiv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const int *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1iv(this->getUniformLocation(name), count, &value[0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector2i *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2iv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector3i *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3iv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector4i *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4iv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const float *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1fv(this->getUniformLocation(name), count, &value[0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector2 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2fv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector3 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3fv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector4 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4fv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const double *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform1dv(this->getUniformLocation(name), count, &value[0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector2d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform2dv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector3d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform3dv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const X::Math::Vector4d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniform4dv(this->getUniformLocation(name), count, &value[0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix2fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x3 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix2x3fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x4 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix2x4fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x2 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix3x2fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix3fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x4 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix3x4fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x2 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix4x2fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x3 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix4x3fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4 *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix4fv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix2dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x3d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix2x3dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix2x4d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix2x4dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x2d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix3x2dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix3dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix3x4d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix3x4dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x2d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix4x2dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4x3d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix4x3dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const int &count, const bool &transpose, const X::Math::Matrix4d *value) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glUniformMatrix4dv(this->getUniformLocation(name), count, transpose, &value[0][0][0]);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const X::Graphics::Texture2D *texture, const unsigned int &textureUnit) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glUniform1i(this->getUniformLocation(name), textureUnit);
		texture->bind();
		glActiveTexture(GL_TEXTURE0);
		this->unbind();
		glUseProgram(curShader);
	}
	void ShaderGL::setUniform(const char *name, const X::Graphics::CubeMap *cubeMap, const unsigned int &textureUnit) {
		GLint curShader;
		glGetIntegerv(GL_CURRENT_PROGRAM, &curShader);
		this->bind();
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glUniform1i(this->getUniformLocation(name), textureUnit);
		cubeMap->bind();
		glActiveTexture(GL_TEXTURE0);
		this->unbind();
		glUseProgram(curShader);
	}

	void ShaderGL::bind() {
		glUseProgram(this->shaderProgram);
	}
	void ShaderGL::unbind() {
		glUseProgram(0);
	}
}}