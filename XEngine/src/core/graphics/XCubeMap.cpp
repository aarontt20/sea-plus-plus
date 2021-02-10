
//==================================================================================\\
//FILE NAME:			XCubeMap.cpp												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/21/2017													\\
//LAST MODIIFED:		05/21/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\



#include "core\graphics\XCubeMap.h"



namespace X {	namespace Graphics {
	
	CubeMap::CubeMap() {	}
	CubeMap::CubeMap(Image *right, Image *left, Image *top, Image *bottom, Image *front, Image *back) {
		this->generate();
		this->bind();
		right->bind();
		ILinfo rInfo;
		iluGetImageInfo(&rInfo);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, rInfo.Format, rInfo.Width, rInfo.Height, 0, rInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
		right->unbind();
		left->bind();
		ILinfo lInfo;
		iluGetImageInfo(&lInfo);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, lInfo.Format, lInfo.Width, lInfo.Height, 0, lInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
		left->unbind();
		top->bind();
		ILinfo tInfo;
		iluGetImageInfo(&tInfo);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, tInfo.Format, tInfo.Width, tInfo.Height, 0, tInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
		top->unbind();
		bottom->bind();
		ILinfo bInfo;
		iluGetImageInfo(&bInfo);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, bInfo.Format, bInfo.Width, bInfo.Height, 0, bInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
		bottom->unbind();
		front->bind();
		ILinfo fInfo;
		iluGetImageInfo(&fInfo);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, fInfo.Format, fInfo.Width, fInfo.Height, 0, fInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
		front->unbind();
		back->bind();
		ILinfo bkInfo;
		iluGetImageInfo(&bkInfo);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, bkInfo.Format, bkInfo.Width, bkInfo.Height, 0, bkInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
		back->unbind();
		this->unbind();
	}
	CubeMap::CubeMap(Image *sides) {
		this->generate();
		this->bind();
		for (int i = 0; i < 6; i++) {
			Image side = sides[i];
			side.bind();
			ILinfo sideInfo;
			iluGetImageInfo(&sideInfo);
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, sideInfo.Format, sideInfo.Width, sideInfo.Height, 0, sideInfo.Format, GL_UNSIGNED_BYTE, ilGetData());
			side.unbind();
		}
		this->unbind();
	}

	void CubeMap::bind() const {
		glBindTexture(GL_TEXTURE_CUBE_MAP, this->GLCubeMap);
	}
	void CubeMap::unbind() const {
		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	}

	void CubeMap::generate() {
		glGenTextures(1, &this->GLCubeMap);
	}
	void CubeMap::destroy() {
		glDeleteTextures(1, &this->GLCubeMap);
	}

	void  CubeMap::setParameter(GLenum parameter, GLint value) {
		this->bind();
		glTexParameteri(GL_TEXTURE_CUBE_MAP, parameter, value);
		this->unbind();
	}
	void  CubeMap::setParameter(GLenum parameter, GLfloat value) {
		this->bind();
		glTexParameterf(GL_TEXTURE_CUBE_MAP, parameter, value);
		this->unbind();
	}
	void  CubeMap::setParameter(GLenum parameter, const X::Math::Vector4i &value) {
		this->bind();
		glTexParameteriv(GL_TEXTURE_CUBE_MAP, parameter, &value[0]);
		this->unbind();
	}
	void  CubeMap::setParameter(GLenum parameter, const X::Math::Vector4 &value) {
		this->bind();
		glTexParameterfv(GL_TEXTURE_CUBE_MAP, parameter, &value[0]);
		this->unbind();
	}
}}