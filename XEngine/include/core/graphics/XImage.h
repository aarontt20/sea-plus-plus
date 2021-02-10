
//==================================================================================\\
//FILE NAME:			XImage.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/07/2017													\\
//LAST MODIIFED:		05/07/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef X_IMAGE_H
#define X_IMAGE_H


#include "DevIL\IL\il.h"
#include "DevIL\IL\ilu.h"
#include "DevIL\IL\ilut.h"




namespace X {	namespace Graphics {

	class Image {
		friend class Texture2D;
	private:
		ILuint ILImage;

		void generate();
		void destroy();
	public:
		Image();
		Image(const char *path);

		~Image();

		void bind();
		void unbind();
	};

}}


#endif // !X_IMAGE_H
