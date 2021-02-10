
//==================================================================================\\
//FILE NAME:			XImage.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/07/2017													\\
//LAST MODIIFED:		05/07/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\graphics\XImage.h"
#include "DevIL\IL\devil_cpp_wrapper.hpp"
#include <iostream>


namespace X {	namespace Graphics {

	Image::Image() {
		this->generate();
	}
	Image::Image(const char *path) {
		this->generate();
		this->bind();
		ilLoadImage(path);
		this->unbind();
	}
	Image::~Image() {
		this->destroy();
	}

	void Image::generate() {
		ilGenImages(1, &this->ILImage);
	}
	void Image::destroy() {
		ilDeleteImages(1, &this->ILImage);
	}
	void Image::bind() {
		ilBindImage(this->ILImage);
	}
	void Image::unbind() {
		ilBindImage(0);
	}
}}
