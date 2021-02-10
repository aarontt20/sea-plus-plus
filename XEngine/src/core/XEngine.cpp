
//==================================================================================\\
//FILE NAME:			XEngine.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\



////Window callBacks
//glfwSetWindowSizeCallback;
//glfwSetWindowRefreshCallback;
//glfwSetWindowPosCallback;
//glfwSetWindowIconifyCallback;
//glfwSetWindowFocusCallback;
//glfwSetWindowCloseCallback;
//
////Hardware connection callbacks
//glfwSetJoystickCallback;
//glfwSetMonitorCallback;
//
////Text callbacks
//glfwSetCharCallback;
//glfwSetCharModsCallback;
//
////Pathdrop callbacks
//glfwSetDropCallback;
//
////OpenGL specific callbacks
//glfwSetFramebufferSizeCallback;
//
////Other callbacks
//glfwSetErrorCallback;


#define STATIC_GLEW
#include "GL\glew.h"
#include "core\XEngine.h"
#include "GLFW\glfw3.h"
#include "core\graphics\display\XMonitor.h"
#include "core\graphics\display\XWindow.h"
#include "core\input\XInput.h"
#include <iostream>
#include <string>
#include <chrono>
#include "core\graphics\Camera.h"
#include "core\graphics\XImage.h"
#include "core\graphics\XTexture2D.h"
#include "core\graphics\XShaderGL.h"
#include "core\graphics\XModel.h"
#include "game\Boat.h"
#include "game\Water.h"
#include "core\graphics\XGLFramebuffer.h"
#include "core\graphics\XCubeMap.h"

#define MOUSE_ACCELERATION 3 * 0.002f


X::Math::Matrix4 projectionMatrtix;
X::Graphics::Camera camera;

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
) {

	int state = 0;
	X::initilize();

	std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();

	X::Graphics::Display::Monitor *monitor = X::Graphics::Display::Monitor::getPrimaryMonitor();
	X::Graphics::Display::windowHint(X::Graphics::Display::Window::SAMPLES, 4);
	X::Graphics::Display::Window window(1440, 900, "Sea++", monitor, nullptr);
	window.setShowCursor(false);

	projectionMatrtix = X::Math::perspective((float)X::Math::radians(72.0), window.getClientWidth() / (float)window.getClientHeight(), 0.01f, 2048.0f);
	//projectionMatrtix = X::Math::perspectiveOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 2048.0f);
	camera = X::Graphics::Camera(X::Math::Vector3(0, 0, 0));

	Boat boat;
	Water water;

	float time = 0;

	camera.setRotationSpeed(0.8);
	camera.setMovementSpeed(0.8);
	camera.linkMoveForwardKey(X::Input::KEY_W);
	camera.linkMoveBackwardKey(X::Input::KEY_S);
	camera.linkMoveLeftKey(X::Input::KEY_A);
	camera.linkMoveRightKey(X::Input::KEY_D);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_FRAMEBUFFER_SRGB);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.05, 0.1, 0.2, 1.0);

	X::Graphics::GLFrameBuffer shadowFBO;
	shadowFBO.generate();

	X::Graphics::Texture2D shadowMap(0, GL_DEPTH_COMPONENT, 512, 512, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
	shadowMap.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	shadowMap.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	shadowMap.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	shadowMap.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	X::Math::Vector4 color(1.0);
	shadowMap.setParameter(GL_TEXTURE_BORDER_COLOR, color);
	shadowFBO.attachTexture(GL_DEPTH_ATTACHMENT, &shadowMap, 0);

	shadowFBO.bind();
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	shadowFBO.unbind();


	X::Graphics::GLFrameBuffer envFBO;
	envFBO.generate();
	envFBO.bind();
	glDrawBuffer(GL_COLOR_ATTACHMENT0);
	glReadBuffer(GL_NONE);
	envFBO.attachRenderBuffer(GL_DEPTH_ATTACHMENT, GL_DEPTH_COMPONENT24, 1024, 1024);
	envFBO.unbind();

	X::Graphics::CubeMap envMap;
	envMap.generate();


	std::vector<X::Graphics::Vertex> verts{
		X::Graphics::Vertex(X::Math::Vector3(-1.0, -1.0, 0.0), X::Math::Vector3(), X::Math::Vector2(0, 0)),
		X::Graphics::Vertex(X::Math::Vector3(1.0 ,-1.0, 0.0), X::Math::Vector3(), X::Math::Vector2(1, 0)),
		X::Graphics::Vertex(X::Math::Vector3(1.0, 1.0, 0.0), X::Math::Vector3(), X::Math::Vector2(1, 1)),
		X::Graphics::Vertex(X::Math::Vector3(-1.0, 1.0, 0.0), X::Math::Vector3(), X::Math::Vector2(0, 1)),
	};
	std::vector<GLuint> inds{
		0, 1, 2,
		0, 2, 3
	};

	X::Graphics::Mesh quad(verts, inds);

	std::vector<X::Graphics::ShaderVertexAttribute> quadAt = {
		X::Graphics::ShaderVertexAttribute(0, "position"),
		X::Graphics::ShaderVertexAttribute(2, "textureCoords"),
	};

	std::vector<X::Graphics::ShaderVertexAttribute> shadowAt = {
		X::Graphics::ShaderVertexAttribute(0, "v_Position"),
	};
	
	std::vector<X::Graphics::ShaderVertexAttribute> SBAt = {
		X::Graphics::ShaderVertexAttribute(0, "i_Position"),
	};

	X::Graphics::ShaderGL quadShader("resources/shaders/QuadVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/QuadFragShader.glsl", &quadAt);

	X::Graphics::ShaderGL shadowShader("resources/shaders/ShadowVertShader.glsl", nullptr, nullptr, nullptr, nullptr, &shadowAt);

	X::Graphics::ShaderGL skyBoxShader("resources/shaders/SkyBoxVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/SkyBoxFragShader.glsl", &SBAt);

	X::Graphics::Image rt("resources/bluecloud_rt.jpg");
	X::Graphics::Image lf("resources/bluecloud_lf.jpg");
	X::Graphics::Image up("resources/bluecloud_up.jpg");
	X::Graphics::Image dn("resources/bluecloud_dn.jpg");
	X::Graphics::Image ft("resources/bluecloud_ft.jpg");
	X::Graphics::Image bk("resources/bluecloud_bk.jpg");
	//X::Graphics::Texture2D(X::Graphics::Image("resources/BoatUVNoMastBasic.png"));

	std::vector<X::Graphics::Vertex> skyBoxVerts = {
		X::Graphics::Vertex(X::Math::Vector3(-1.0, -1.0,  1.0)),
		X::Graphics::Vertex(X::Math::Vector3(1.0, -1.0,  1.0)),
		X::Graphics::Vertex(X::Math::Vector3(1.0,  1.0,  1.0)),
		X::Graphics::Vertex(X::Math::Vector3(-1.0,  1.0,  1.0)),
		X::Graphics::Vertex(X::Math::Vector3(-1.0, -1.0, -1.0)),
		X::Graphics::Vertex(X::Math::Vector3(1.0, -1.0, -1.0)),
		X::Graphics::Vertex(X::Math::Vector3(1.0,  1.0, -1.0)),
		X::Graphics::Vertex(X::Math::Vector3(-1.0,  1.0, -1.0))
	};

	std::vector<GLuint> skyBoxInds = {
		0, 2, 1,
		2, 0, 3,
		1, 6, 5,
		6, 1, 2,
		7, 5, 6,
		5, 7, 4,
		4, 3, 0,
		3, 4, 7,
		4, 1, 5,
		1, 4, 0,
		3, 6, 2,
		6, 3, 7,
	};

	X::Graphics::Mesh skyBox(skyBoxVerts, skyBoxInds);

	X::Graphics::CubeMap skyBoxCubeMap(&rt, &lf, &up, &dn, &ft, &bk);
	skyBoxCubeMap.setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	skyBoxCubeMap.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	skyBoxCubeMap.setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	skyBoxCubeMap.setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	X::Math::Vector2 windDirection(1, 1);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	bool canPress = true;
	X::Graphics::Texture2D splash(X::Graphics::Image("resources/splash.png"));
	X::Graphics::Texture2D pause(X::Graphics::Image("resources/pause.png"));
	splash.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	splash.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	float pitch = -X::Math::PI / 32.0f, yaw = -X::Math::PI/2;
	float angleAround = 0;
	float dist = 20;


	while (!window.requestedClose()) {


		if (X::Input::isKeyPressed(X::Input::KEY_ESC) && canPress && (state == 1 || state == 2)) {
			canPress = false;
			if (state == 1) state = 2;
			else if (state == 2) state = 1;
		}
		if (!X::Input::isKeyPressed(X::Input::KEY_ESC)) canPress = true;

		if (state == 0) {
			if (X::Input::isKeyPressed(X::Input::KEY_SPACE)) state = 1;

			glDisable(GL_DEPTH_TEST);
			quadShader.bind();
			quadShader.setUniform("u_texture", &splash, 0);
			quad.render();
			quadShader.unbind();
			glEnable(GL_DEPTH_TEST);
		}
		else if (state == 1) {
			time += 0.02;
			boat.update(&water, windDirection, time);
			water.update();

			if (X::Input::getCursorX() > X::Input::getLastCursorX()) {
				yaw -= 0.8 * X::Math::abs(X::Input::getCursorX() - X::Input::getLastCursorX()) * MOUSE_ACCELERATION;
				//float baseRotation = camera.getRoationSpeed();
				
				//camera.setRotationSpeed(baseRotation * X::Math::abs(X::Input::getCursorX() - X::Input::getLastCursorX()) * MOUSE_ACCELERATION);
				//camera.rotateRight();
				//camera.setRotationSpeed(baseRotation);
			}
			if (X::Input::getCursorX() < X::Input::getLastCursorX()) {
				yaw += 0.8 * X::Math::abs(X::Input::getCursorX() - X::Input::getLastCursorX()) * MOUSE_ACCELERATION;
				//float baseRotation = camera.getRoationSpeed();
				//camera.setRotationSpeed(baseRotation * X::Math::abs(X::Input::getCursorX() - X::Input::getLastCursorX()) * MOUSE_ACCELERATION);
				//camera.rotateLeft();
				//camera.setRotationSpeed(baseRotation);
			}
			if (X::Input::getCursorY() < X::Input::getLastCursorY() && pitch < -X::Math::PI / 32.0f) {
				pitch += 0.8 * X::Math::abs(X::Input::getCursorY() - X::Input::getLastCursorY()) * MOUSE_ACCELERATION;
				//float baseRotation = camera.getRoationSpeed();
				//camera.setRotationSpeed(baseRotation * X::Math::abs(X::Input::getCursorY() - X::Input::getLastCursorY()) * MOUSE_ACCELERATION);
				//camera.rotateUp();
				//camera.setRotationSpeed(baseRotation);
			}
			if (X::Input::getCursorY() > X::Input::getLastCursorY()&& pitch > -X::Math::PI / 2.5f) {
				pitch -= 0.8 * X::Math::abs(X::Input::getCursorY() - X::Input::getLastCursorY()) * MOUSE_ACCELERATION;
				//float baseRotation = camera.getRoationSpeed();
				//camera.setRotationSpeed(baseRotation * X::Math::abs(X::Input::getCursorY() - X::Input::getLastCursorY()) * MOUSE_ACCELERATION);
				//camera.rotateDown();
				//camera.setRotationSpeed(baseRotation);
			}
			if (X::Input::getScrollYOffset() > 0) {
				if (dist > 16) dist -= X::Input::getScrollYOffset();
			}
			if (X::Input::getScrollYOffset() < 0) {
				if (dist < 32) dist -= X::Input::getScrollYOffset();
			}

			//camera.update();
			X::Math::Vector3 pos;
			//float yaw = 0;
			float h = dist * X::Math::cos(pitch);
			float v = dist * X::Math::sin(pitch);
			float xoffset = h * X::Math::sin(yaw);
			float zoffset = h * X::Math::cos(yaw);
			pos.x = boat.getPosition().x - xoffset;
			pos.z = boat.getPosition().z - zoffset;
			pos.y = boat.getPosition().y - v;

			
			X::Math::Matrix4 viewMatrix = X::Math::view(pos, X::Math::Vector3::normalize(boat.getPosition() - pos), X::Math::Vector3(0, 1, 0));



			float a = 64.0f;

			X::Math::Matrix4 lightProjection = X::Math::perspectiveOrtho(-a / 4, a / 4, -a / 4, a / 2, -a / 4, a * 4);
			X::Math::Matrix4 lightView = X::Math::view(X::Math::Vector3(0, 0, 0), X::Math::Vector3(1, -.8, 1), X::Math::Vector3(0, 1, 0)) * X::Math::translate(X::Math::Matrix4(), -boat.getPosition());

			X::Math::Matrix4 lightSpace = lightProjection * lightView;

			shadowFBO.bind();
			glViewport(0, 0, 512, 512);
			glClear(GL_DEPTH_BUFFER_BIT);
			glCullFace(GL_FRONT);
			boat.renderShadowMap(&shadowShader, lightSpace, time);
			water.renderShadowMap(&shadowShader, lightSpace);
			glCullFace(GL_BACK);
			shadowFBO.unbind();


			glViewport(0, 0, window.getClientWidth(), window.getClientHeight());
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			skyBoxShader.bind();
			skyBoxShader.setUniform("cubeMap", &skyBoxCubeMap, 0);
			X::Math::Matrix4 SBMVP;
			X::Math::Matrix4 view = viewMatrix;
			view[3][0] = 0;
			view[3][1] = 0;
			view[3][2] = 0;
			SBMVP = projectionMatrtix * view  * X::Math::scale(X::Math::Matrix4(), X::Math::Vector3(256 * 4.5))/* X::Math::rotate(X::Math::scale(X::Math::Matrix4(), X::Math::Vector3(256 * 4.5)), time*0.02, X::Math::Vector3(0, 1, 0))*/;
			skyBoxShader.setUniform("u_MVP", 1, false, &SBMVP);
			skyBox.render();
			skyBoxShader.unbind();

			boat.render(&shadowMap, lightSpace, viewMatrix, time, pos);
			water.render(&shadowMap, lightSpace, &boat, &skyBoxCubeMap, viewMatrix, time, pos);


			//glDisable(GL_DEPTH_TEST);
			//quadShader.bind();
			//quadShader.setUniform("screenTexture", &shadowMap, 0);
			//quad.render();
			//quadShader.unbind();
			//glEnable(GL_DEPTH_TEST);
		}
		else if (state == 2) {

			X::Math::Vector3 pos;
			//float yaw = 0;
			float h = dist * X::Math::cos(pitch);
			float v = dist * X::Math::sin(pitch);
			float xoffset = h * X::Math::sin(yaw);
			float zoffset = h * X::Math::cos(yaw);
			pos.x = boat.getPosition().x - xoffset;
			pos.z = boat.getPosition().z - zoffset;
			pos.y = boat.getPosition().y - v;

			
			X::Math::Matrix4 viewMatrix = X::Math::view(pos, X::Math::Vector3::normalize(boat.getPosition() - pos), X::Math::Vector3(0, 1, 0));

			float a = 64.0f;

			X::Math::Matrix4 lightProjection = X::Math::perspectiveOrtho(-a / 4, a / 4, -a / 4, a / 2, -a / 4, a * 4);
			X::Math::Matrix4 lightView = X::Math::view(X::Math::Vector3(0, 0, 0), X::Math::Vector3(1, -.8, 1), X::Math::Vector3(0, 1, 0)) * X::Math::translate(X::Math::Matrix4(), -boat.getPosition());

			X::Math::Matrix4 lightSpace = lightProjection * lightView;

			shadowFBO.bind();
			glViewport(0, 0, 512, 512);
			glClear(GL_DEPTH_BUFFER_BIT);
			glCullFace(GL_FRONT);
			boat.renderShadowMap(&shadowShader, lightSpace, time);
			water.renderShadowMap(&shadowShader, lightSpace);
			glCullFace(GL_BACK);
			shadowFBO.unbind();


			glViewport(0, 0, window.getClientWidth(), window.getClientHeight());
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			skyBoxShader.bind();
			skyBoxShader.setUniform("cubeMap", &skyBoxCubeMap, 0);
			X::Math::Matrix4 SBMVP;
			X::Math::Matrix4 view = viewMatrix;
			view[3][0] = 0;
			view[3][1] = 0;
			view[3][2] = 0;
			SBMVP = projectionMatrtix * view  * X::Math::scale(X::Math::Matrix4(), X::Math::Vector3(256 * 4.5))/* X::Math::rotate(X::Math::scale(X::Math::Matrix4(), X::Math::Vector3(256 * 4.5)), time*0.02, X::Math::Vector3(0, 1, 0))*/;
			skyBoxShader.setUniform("u_MVP", 1, false, &SBMVP);
			skyBox.render();
			skyBoxShader.unbind();

			boat.render(&shadowMap, lightSpace, viewMatrix, time, pos);
			water.render(&shadowMap, lightSpace, &boat, &skyBoxCubeMap, viewMatrix, time, pos);

			glDisable(GL_DEPTH_TEST);
			quadShader.bind();
			quadShader.setUniform("u_texture", &pause, 0);
			quad.render();
			quadShader.unbind();
			glEnable(GL_DEPTH_TEST);

			if (X::Input::isKeyPressed(X::Input::KEY_E))	window.setShouldClose(true);
		}

		window.swapBuffers();
		X::Input::updateInput();
		window.processEvents();
	}

	quad.destroy();
	shadowFBO.destroy();
	skyBox.destroy();
	skyBoxCubeMap.destroy();
	envFBO.destroy();
	envMap.destroy();

	X::terminate();

	return 0;
}

namespace X {
	bool initilize() {
		glfwInit();
		Graphics::Display::Monitor::init();
		ilInit();
		iluInit();
		ilutInit();
		ilutRenderer(ILUT_OPENGL);

		return true;
	}
	void terminate() {

		glfwTerminate();
	}
}
