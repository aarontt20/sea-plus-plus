
//==================================================================================\\
//FILE NAME:			XTexture2D.cpp												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/07/2017													\\
//LAST MODIIFED:		05/07/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XTexture2D.h"
#include "core\graphics\XImage.h"
#include <iostream>


namespace X {	namespace Graphics {
	
	Texture2D::Texture2D() {
		this->generate();
	}
	Texture2D::Texture2D(Image &image) {
		image.bind();
		this->GLTexture = ilutGLBindTexImage();
		image.unbind();
		glGenerateMipmap(GL_TEXTURE_2D);
		this->unbind();
	}
	Texture2D::Texture2D(GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLenum pixleFormat, GLenum dataType, const GLvoid *pixles) {
		this->generate();
		this->bind();
		glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, height, 0, pixleFormat, dataType, pixles);
		glGenerateMipmap(GL_TEXTURE_2D);
		this->unbind();
	}

	Texture2D::~Texture2D() {
		this->destroy();
	}

	void Texture2D::generate() {
		glGenTextures(1, &this->GLTexture);
	}
	void Texture2D::destroy() {
		glDeleteTextures(1, &this->GLTexture);
	}
	void Texture2D::bind() const {
		glBindTexture(GL_TEXTURE_2D, this->GLTexture);
	}
	void Texture2D::unbind() const {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void  Texture2D::setParameter(GLenum parameter, GLint value) {
		this->bind();
		glTexParameteri(GL_TEXTURE_2D, parameter, value);
		this->unbind();
	}
	void  Texture2D::setParameter(GLenum parameter, GLfloat value) {
		this->bind();
		glTexParameterf(GL_TEXTURE_2D, parameter, value);
		this->unbind();
	}
	void  Texture2D::setParameter(GLenum parameter, const X::Math::Vector4i &value) {
		this->bind();
		glTexParameteriv(GL_TEXTURE_2D, parameter, &value[0]);
		this->unbind();
	}
	void  Texture2D::setParameter(GLenum parameter, const X::Math::Vector4 &value) {
		this->bind();
		glTexParameterfv(GL_TEXTURE_2D, parameter, &value[0]);
		this->unbind();
	}
}}
