
//==================================================================================\\
//FILE NAME:			XWindow.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/19/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "core\graphics\display\XWindow.h"
#include "core\graphics\display\XMonitor.h"
#include <iostream>
#include "core\input\XInput.h"


namespace X {	namespace Graphics {	namespace Display {
	
	void windowHint(int hint, int value) {
		glfwWindowHint(hint, value);
	}
	void resetWindowHints() {
		glfwDefaultWindowHints();
	}

	std::map<GLFWwindow*, Window*> Window::windowMap;
	
	Window::Window() {
		this->title = "XEngine";
		this->glWindow = glfwCreateWindow(640, 480, this->title, nullptr, nullptr);

		Window::windowMap.insert({ this->glWindow, this });

		glfwMakeContextCurrent(this->glWindow);

		glfwSetKeyCallback(this->glWindow, Input::detail::glKeyCallback);
		glfwSetCursorPosCallback(this->glWindow, Input::detail::glCursorPosCallback);
		glfwSetScrollCallback(this->glWindow, Input::detail::glScrollCallback);

		glfwSetMouseButtonCallback(this->glWindow, Input::detail::glMouseButtonCallback);
		glfwSetInputMode(this->glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glewInit();
	}
	Window::Window(const unsigned int& width, const unsigned int& height, const char *title, Monitor *monitor, Window *share) {
		this->title = title;
		if(monitor && share)	this->glWindow = glfwCreateWindow(width, height, this->title, monitor->glMonitor, share->glWindow);
		else if(monitor)		this->glWindow = glfwCreateWindow(width, height, this->title, monitor->glMonitor, nullptr);
		else if(share)			this->glWindow = glfwCreateWindow(width, height, this->title, nullptr, share->glWindow);
		else					this->glWindow = glfwCreateWindow(width, height, this->title, nullptr, nullptr);
		
		Window::windowMap.insert({ this->glWindow, this });
		
		glfwMakeContextCurrent(this->glWindow);

		glfwSetKeyCallback(this->glWindow, Input::detail::glKeyCallback);
		glfwSetCursorPosCallback(this->glWindow, Input::detail::glCursorPosCallback);
		glfwSetScrollCallback(this->glWindow, Input::detail::glScrollCallback);

		glfwSetMouseButtonCallback(this->glWindow, Input::detail::glMouseButtonCallback);

		glfwSetInputMode(this->glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glewInit();
	}
	Window::~Window() {
		Window::windowMap.erase(this->glWindow);
		glfwDestroyWindow(this->glWindow);
	}

	Math::Vector2i Window::getClientSize() const {
		Math::Vector2i size;

		glfwGetWindowSize(this->glWindow, &size.x, &size.y);

		return size;
	}
	int Window::getClientWidth() const {
		int width;
		glfwGetWindowSize(this->glWindow, &width, nullptr);

		return width;
	}
	int Window::getClientHeight() const {
		int height;
		glfwGetWindowSize(this->glWindow, nullptr, &height);

		return height;
	}
	const char * Window::getTitle() const {
		return this->title;
	}
	Math::Vector2i Window::getClientPosition() const {
		Math::Vector2i pos;

		glfwGetWindowPos(this->glWindow, &pos.x, &pos.y);

		return pos;
	}
	int Window::getClientXPos() const {
		int x;
		glfwGetWindowPos(this->glWindow, &x, nullptr);

		return x;
	}
	int Window::getClientYPos() const {
		int y;
		glfwGetWindowPos(this->glWindow, nullptr, &y);

		return y;
	}
	Math::Vector2i Window::getPosition() const {
		Math::Vector2i pos = this->getClientPosition();
		pos.x -= this->getDecorationsLeftSize();
		pos.y -= this->getDecorationsTopSize();
		return pos;
	}
	int Window::getXPos() const {
		int clientX = this->getClientXPos();
		int left = this->getDecorationsLeftSize();

		return clientX - left;
	}
	int Window::getYPos() const {
		int clientY = this->getClientYPos();
		int top = this->getDecorationsTopSize();

		return clientY - top;
	}
	Math::Vector2i Window::getFrameBufferSize() const {
		Math::Vector2i FBSize;

		glfwGetFramebufferSize(this->glWindow, &FBSize.x, &FBSize.y);

		return FBSize;
	}
	int Window::getFrameBufferWidth() const {
		int width;
		glfwGetFramebufferSize(this->glWindow, &width, nullptr);

		return width;
	}
	int Window::getFrameBufferHeight() const {
		int height;
		glfwGetFramebufferSize(this->glWindow, nullptr, &height);

		return height;
	}
	Math::Vector2i Window::getSize() const {
		Math::Vector2i size = this->getClientSize();

		size.x += this->getDecorationsLeftSize() + this->getDecorationsRightSize();
		size.y += this->getDecorationsTopSize() + this->getDecorationsBottomSize();

		return size;
	}
	int Window::getWidth() const {
		int clientWidth = this->getClientWidth();
		int left, right;

		left = this->getDecorationsLeftSize();
		right = this->getDecorationsRightSize();

		return left + clientWidth + right;
	}
	int Window::getHeight() const {
		int clientHeight = this->getClientHeight();
		int top, bottom;
		top = this->getDecorationsTopSize();
		bottom = this->getDecorationsBottomSize();

		return top + clientHeight + bottom;
	}
	int Window::getDecorationsLeftSize() const {
		int left;
		glfwGetWindowFrameSize(this->glWindow, &left, nullptr, nullptr, nullptr);

		return left;
	}
	int Window::getDecorationsTopSize() const {
		int top;
		glfwGetWindowFrameSize(this->glWindow, nullptr, &top, nullptr, nullptr);

		return top;
	}
	int Window::getDecorationsBottomSize() const {
		int bottom;
		glfwGetWindowFrameSize(this->glWindow, nullptr, nullptr, nullptr, &bottom);

		return bottom;
	}
	int Window::getDecorationsRightSize() const {
		int right;
		glfwGetWindowFrameSize(this->glWindow, nullptr, nullptr, &right, nullptr);

		return right;
	}
	bool Window::requestedClose() const{
		return glfwWindowShouldClose(this->glWindow);
	}
	bool Window::isInFocus() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_FOCUSED));
	}
	bool Window::isResizable() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_RESIZABLE));
	}
	bool Window::isMinimized() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_ICONIFIED));
	}
	bool Window::isMaximized() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_MAXIMIZED));
	}
	bool Window::isFullScreen() const {
		return this->getMonitor() != nullptr;
	}
	bool Window::isVisible() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_VISIBLE));
	}
	bool Window::isDecorated() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_DECORATED));
	}
	bool Window::isAlwaysOnTop() const {
		return static_cast<bool>(glfwGetWindowAttrib(this->glWindow, GLFW_FLOATING));

	}
	Monitor *Window::getMonitor() const {
		GLFWmonitor * m = glfwGetWindowMonitor(this->glWindow);
		if (m)	return Monitor::monitorMap[m]->get();
		else	return nullptr;
	}

	void Window::setClientSize(const Math::Vector2i &size) {
		glfwSetWindowSize(this->glWindow, size.x, size.y);
	}
	void Window::setClientSize(const int &width, const int &height) {
		glfwSetWindowSize(this->glWindow, width, height);
	}
	void Window::setClientWidth(const int& width) {
		glfwSetWindowSize(this->glWindow, width, this->getClientHeight());
	}
	void Window::setClientHeight(const int& height) {
		glfwSetWindowSize(this->glWindow, this->getClientWidth(), height);
	}
	void Window::setClientPosition(const Math::Vector2i &pos) {
		glfwSetWindowPos(this->glWindow, pos.x, pos.y);
	}
	void Window::setClientPosition(const int &xPos, const int &yPos) {
		glfwSetWindowPos(this->glWindow, xPos, yPos);
	}
	void Window::setClientXPos(const int& xPos) {
		glfwSetWindowPos(this->glWindow, xPos, this->getClientYPos());
	}
	void Window::setClientYPos(const int& yPos) {
		glfwSetWindowPos(this->glWindow, this->getClientXPos(), yPos);
	}
	void Window::setPosition(const Math::Vector2i &pos) {
		glfwSetWindowPos(this->glWindow, pos.x + this->getDecorationsLeftSize(), pos.y + this->getDecorationsTopSize());
	}
	void Window::setPosition(const int &xPos, int &yPos) {
		glfwSetWindowPos(this->glWindow, xPos + this->getDecorationsLeftSize(), yPos + this->getDecorationsTopSize());
	}
	void Window::setXPos(const int& xPos) {
		glfwSetWindowPos(this->glWindow, xPos + this->getDecorationsLeftSize(), this->getClientYPos());
	}
	void Window::setYPos(const int& yPos) {
		glfwSetWindowPos(this->glWindow, this->getClientXPos(), yPos + this->getDecorationsTopSize());
	}
	void Window::setSize(const Math::Vector2i &size) {
		glfwSetWindowSize(this->glWindow, size.x - this->getDecorationsLeftSize() - this->getDecorationsRightSize(), size.y - this->getDecorationsTopSize() - this->getDecorationsBottomSize());
	}
	void Window::setSize(const int &width, const int &height) {
		glfwSetWindowSize(this->glWindow, width - this->getDecorationsLeftSize() - this->getDecorationsRightSize(), height - this->getDecorationsTopSize() - this->getDecorationsBottomSize());
	}
	void Window::setWidth(const int & width) {
		glfwSetWindowSize(this->glWindow, width - this->getDecorationsLeftSize() - this->getDecorationsRightSize(), this->getClientHeight());
	}
	void Window::setHeight(const int & height) {
		glfwSetWindowSize(this->glWindow, this->getClientWidth(), height - this->getDecorationsTopSize() - this->getDecorationsBottomSize());
	}
	void Window::setTitle(const char* title) {
		glfwSetWindowTitle(this->glWindow, title);
	}
	void Window::setShouldClose(const bool& b) {
		glfwSetWindowShouldClose(this->glWindow, b);
	}
	void Window::maintainAspectRatio(const int& num, const int& denom) {
		glfwSetWindowAspectRatio(this->glWindow, num, denom);
	}
	void Window::releaseMaintainedAspectRatio() {
		glfwSetWindowAspectRatio(this->glWindow, -1, -1);
	}
	void Window::setSizeLimits(const int& minWidth, const int &minHeight, const int &maxWidth, const int maxHeight) {
		glfwSetWindowSizeLimits(this->glWindow, minWidth, minHeight, maxWidth, maxHeight);
	}
	void Window::releaseSizeLimits() {
		glfwSetWindowSizeLimits(this->glWindow, -1, -1, -1, -1);
	}
	void Window::setFullscreen(Monitor *monitor, const VideoMode &vidMode) {
		glfwSetWindowMonitor(this->glWindow, monitor->glMonitor, 0, 0, vidMode.width, vidMode.height, vidMode.refreshRate);
	}
	void Window::setFullscreen(Monitor *monitor, const Math::Vector2i &size, const int &refreshRate) {
		glfwSetWindowMonitor(this->glWindow, monitor->glMonitor, 0, 0, size.x, size.y, refreshRate);
	}
	void Window::setFullscreen(Monitor *monitor, const int &width, const int &height, const int &refreshRate) {
		glfwSetWindowMonitor(this->glWindow, monitor->glMonitor, 0, 0, width, height, refreshRate);
	}
	void Window::setWindowed(const int &xPos, const int &yPos, const int &width, const int &height) {
		glfwSetWindowMonitor(this->glWindow, nullptr, xPos, yPos, width, height, 0);
	}
	void Window::setWindowed(const Math::Vector2i &pos, const Math::Vector2i &size) {
		glfwSetWindowMonitor(this->glWindow, nullptr, pos.x, pos.y, size.x, size.y, 0);
	}
	void Window::setMinimized(const bool &minimize) {
		if (minimize)	glfwIconifyWindow(this->glWindow);
		else	glfwRestoreWindow(this->glWindow);
	}
	void Window::minimize() {
		glfwIconifyWindow(this->glWindow);
	}
	void Window::setMaximized(const bool &maximize) {
		if (maximize)	glfwMaximizeWindow(this->glWindow);
		else	glfwRestoreWindow(this->glWindow);
	}
	void Window::maximize() {
		glfwMaximizeWindow(this->glWindow);
	}
	void Window::restore() {
		glfwRestoreWindow(this->glWindow);
	}
	void Window::setVisiblity(const bool &visible) {
		if (visible)	glfwShowWindow(this->glWindow);
		else	glfwHideWindow(this->glWindow);
	}
	void Window::hide() {
		glfwHideWindow(this->glWindow);
	}
	void Window::show() {
		glfwShowWindow(this->glWindow);
	}
	void Window::focus() {
		glfwFocusWindow(this->glWindow);
	}

	void Window::processEvents() {
		glfwPollEvents();
	}
	void Window::swapBuffers() {
		glfwSwapBuffers(this->glWindow);
	}
	void Window::setShowCursor(const bool& b) {
		glfwSetInputMode(this->glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	void Window::showCursor() {

	}
	void Window::hideCursor() {

	}
}}}