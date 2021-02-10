
//==================================================================================\\
//FILE NAME:			XGLVBuffer.cpp												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/09/2017													\\
//LAST MODIIFED:		05/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XGLBuffer.h"


namespace X {	namespace Graphics {

	GLBuffer::GLBuffer() {	}
	GLBuffer::GLBuffer(GLenum targetBinding, const void *data, const int &byteSize, GLenum usage) {
		this->targetBinding = targetBinding;
		this->usage = usage;
		this->generate();
		this->bind();
		glBufferData(this->targetBinding, byteSize, data, this->usage);
		this->unbind();
	}

	void GLBuffer::generate() {
		glGenBuffers(1, &this->buffer);
	}
	void GLBuffer::destroy() {
		glDeleteBuffers(1, &this->buffer);
	}
	
	void GLBuffer::bind() const {
		glBindBuffer(this->targetBinding, this->buffer);
	}
	void GLBuffer::unbind() const {
		glBindBuffer(this->targetBinding, 0);
	}

}}