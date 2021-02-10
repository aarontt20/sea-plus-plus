
//==================================================================================\\
//FILE NAME:			XGLFrameBuffer.h											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/19/2017													\\
//LAST MODIIFED:		05/19/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_GL_FRAMEBUFFER_H
#define X_GL_FRAMEBUFFER_H


#define GLEW_STATIC
#include "GL\glew.h"
#include "core\graphics\XTexture2D.h"
#include "core\graphics\XCubeMap.h"
#include <vector>


namespace X {	namespace Graphics {

	struct GLFrameBuffer {
	private:
		GLuint frameBuffer;

		struct GLRenderBuffer {
			friend struct GLFrameBuffer;
		private:
			GLuint renderBuffer;

			void bind();
			void unbind();
		public:
			GLRenderBuffer();

			void generate();
			void destroy();

			void setStorage(GLenum internalFormat, GLsizei width, GLsizei height);
			void setStorageMultiSampled(GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height);
		};
		
		std::vector<GLRenderBuffer> renderBufferAttachments;

	public:
		GLFrameBuffer();

		void attachRenderBuffer(GLenum attachment, GLenum internalFormat, GLsizei width, GLsizei height);
		void attachMultiSampledRenderBuffer(GLenum attachment, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height);
		void attachTexture(GLenum attachment, Texture2D *texture, GLint level);
		void attachTexture(GLenum attachment, CubeMap *cubMap, GLenum face, GLint level);
		bool isComplete();

		void generate();
		
		void destroy();
		void bind();
		void unbind();
	};

}}


#endif // !X_GL_FRAMEBUFFER_H
