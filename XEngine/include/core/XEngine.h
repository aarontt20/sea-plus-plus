
//==================================================================================\\
//FILE NAME:			XEngine.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_ENGINE_H
#define X_ENGINE_H


#define STATIC_GLEW
#include "GL\glew.h"
#include "GLFW\glfw3.h"


namespace X {
	bool initilize();
	void terminate();
}


#endif // !X_ENGINE_H
