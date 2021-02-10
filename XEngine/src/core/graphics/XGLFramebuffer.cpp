
//==================================================================================\\
//FILE NAME:			XGLFrameBuffer.h											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			05/19/2017													\\
//LAST MODIIFED:		05/19/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\



#include "core\graphics\XGLFramebuffer.h"



namespace X {	namespace Graphics {

	GLFrameBuffer::GLRenderBuffer::GLRenderBuffer() {	}
	void GLFrameBuffer::GLRenderBuffer::generate() {
		glGenRenderbuffers(1, &this->renderBuffer);
	}
	void GLFrameBuffer::GLRenderBuffer::destroy() {
		glDeleteRenderbuffers(1, &this->renderBuffer);
	}
	void GLFrameBuffer::GLRenderBuffer::bind() {
		glBindRenderbuffer(GL_RENDERBUFFER, this->renderBuffer);
	}
	void GLFrameBuffer::GLRenderBuffer::unbind() {
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
	}
	void GLFrameBuffer::GLRenderBuffer::setStorage(GLenum internalFormat, GLsizei width, GLsizei height) {
		this->bind();
		glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
		this->unbind();
	}
	void GLFrameBuffer::GLRenderBuffer::setStorageMultiSampled(GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) {
		this->bind();
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalFormat, width, height);
		this->unbind();
	}

	GLFrameBuffer::GLFrameBuffer() {	}
	void GLFrameBuffer::generate() {
		glGenFramebuffers(1, &this->frameBuffer);
	}
	void GLFrameBuffer::destroy() {
		for each (GLFrameBuffer::GLRenderBuffer r in this->renderBufferAttachments) {
			r.destroy();
		}

		glDeleteFramebuffers(1, &this->frameBuffer);
	}
	void GLFrameBuffer::bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, this->frameBuffer);
	}
	void GLFrameBuffer::unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	void GLFrameBuffer::attachRenderBuffer(GLenum attachment, GLenum internalFormat, GLsizei width, GLsizei height) {
		GLRenderBuffer RBO;
		RBO.generate();
		RBO.bind();
		RBO.setStorage(internalFormat, width, height);
		this->bind();
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, RBO.renderBuffer);
		this->unbind();
		RBO.unbind();
		this->renderBufferAttachments.push_back(RBO);
	}
	void GLFrameBuffer::attachMultiSampledRenderBuffer(GLenum attachment, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) {
		GLRenderBuffer RBO;
		RBO.generate();
		RBO.bind();
		RBO.setStorageMultiSampled(samples, internalFormat, width, height);
		this->bind();
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, RBO.renderBuffer);
		this->unbind();
		RBO.unbind();
		this->renderBufferAttachments.push_back(RBO);
	}
	void GLFrameBuffer::attachTexture(GLenum attachment, Texture2D *texture, GLint level) {
		this->bind();
		glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture->GLTexture, level);
		this->unbind();
	}
	void GLFrameBuffer::attachTexture(GLenum attachment, CubeMap *cubMap, GLenum face, GLint level) {
		this->bind();
		glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, face, cubMap->GLCubeMap, level);
		this->unbind();
	}
	bool GLFrameBuffer::isComplete() {
		this->bind();
		bool b = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
		this->unbind();
		return b;
	}
}}
