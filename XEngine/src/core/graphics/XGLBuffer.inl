
//==================================================================================\\
//FILE NAME:			XGLVBuffer.inl												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/09/2017													\\
//LAST MODIIFED:		05/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\



#include "core\graphics\XGLBuffer.h"


namespace X {	namespace Graphics {

	template <typename T>	GLBuffer::GLBuffer(GLenum targetBinding, const std::vector<T> &data, GLenum usage) {
		this->targetBinding = targetBinding;
		this->usage = usage;
		this->generate();
		this->bind();
		glBufferData(this->targetBinding, data.size() * sizeof(T), &data[0], this->usage);
		this->unbind();
	}

}}