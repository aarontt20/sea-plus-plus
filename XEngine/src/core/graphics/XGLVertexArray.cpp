
//==================================================================================\\
//FILE NAME:			XGLVertexArray.h											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/09/2017													\\
//LAST MODIIFED:		05/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XGLVertexArray.h"


namespace X {	namespace Graphics{
	
	void GLVertexArray::generate() {
		glGenVertexArrays(1, &this->VertexArrayObject);
	}
	void GLVertexArray::destroy() {
		glDeleteVertexArrays(1, &this->VertexArrayObject);
	}
	
	void GLVertexArray::bind() const {
		glBindVertexArray(this->VertexArrayObject);
	}
	void GLVertexArray::unbind() const {
		glBindVertexArray(0);
	}

}}