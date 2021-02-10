
//==================================================================================\\
//FILE NAME:			XMonitor.cpp												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "core\graphics\display\XMonitor.h"
#include <iostream>


namespace X {	namespace Graphics {	namespace Display {	namespace detail {
		void MonitorDeleter::operator()(Monitor *m) {
			delete m;
		}

		void monitor_callback(GLFWmonitor* monitor, int event) {
			//if (event == GLFW_CONNECTED) {
			//	Monitor::availableMonitors.push_back(std::unique_ptr<Monitor, detail::MonitorDeleter>(new Monitor(monitor), detail::MonitorDeleter()));
			//	Monitor::monitorMap.insert({ monitor,  &Monitor::availableMonitors.back() });
			//
			//}
			//if (event == GLFW_DISCONNECTED) {
			//	for (int i = 0; i < Monitor::availableMonitors.size(); i++) {
			//		if (Monitor::availableMonitors.at(i) == *Monitor::monitorMap[monitor]) {
			//			Monitor::availableMonitors.erase(Monitor::availableMonitors.begin()+i);
			//			break;
			//		}
			//	}
			//	Monitor::monitorMap.erase(monitor);
			//}
			//std::cout << Monitor::availableMonitors.size();
		}
	}

	VideoMode::VideoMode() {
		this->width = 0;
		this->height = 0;
		this->rBits = 0;
		this->gBits = 0;
		this->bBits = 0;
		this->refreshRate = 0;
	}
	VideoMode::VideoMode(const int & width, const int & height, const int & rBits, const int & gBits, const int & bBits, const int & refreshRate) {
		this->width = width;
		this->height = height;
		this->rBits = rBits;
		this->gBits = gBits;
		this->bBits = bBits;
		this->refreshRate = refreshRate;
	}

	GammaRamp::GammaRamp() {
		this->size = 0;
		this->red = nullptr;
		this->green = nullptr;
		this->blue = nullptr;
	}
	GammaRamp::GammaRamp(unsigned int &size, unsigned short *red, unsigned short *green, unsigned short *blue) {
		this->size = size;
		this->red = red;
		this->green = green;
		this->blue = blue;
	}

	std::vector<std::unique_ptr<Monitor, detail::MonitorDeleter>> Monitor::availableMonitors;
	std::map<GLFWmonitor *, std::unique_ptr<Monitor, detail::MonitorDeleter> *> Monitor::monitorMap;
	Monitor * Monitor::primaryMonitor;
	Monitor::Monitor(GLFWmonitor *glMonitor) {
		this->glMonitor = glMonitor;
	}
	Monitor::~Monitor() {

	}

	bool Monitor::init() {
		int monitorCount;
		GLFWmonitor **monitors = glfwGetMonitors(&monitorCount);

		for (int i = 0; i < monitorCount; i++) {
			Monitor::availableMonitors.push_back(std::unique_ptr<Monitor, detail::MonitorDeleter>(new Monitor(monitors[i]), detail::MonitorDeleter()));
			Monitor::monitorMap.insert({ monitors[i],  &Monitor::availableMonitors.at(i) });
			if (i == 0)	Monitor::primaryMonitor = Monitor::availableMonitors.at(i).get();
		}
		std::cerr << "WARNING: Monitor function callback will not be called. GLFW v3.3 needed for monitor callback functionality" << std::endl;
		glfwSetMonitorCallback(Graphics::Display::detail::monitor_callback);

		return true;
	}

	const char *Monitor::getName() const {
		return glfwGetMonitorName(this->glMonitor);
	}
	Math::Vector2i Monitor::getPhysicalSize() const {
		Math::Vector2i size;
		
		glfwGetMonitorPhysicalSize(this->glMonitor, &size.x, &size.y);

		return size;
	}
	int Monitor::getPhysicalWidth() const {
		int width;
		glfwGetMonitorPhysicalSize(this->glMonitor, &width, nullptr);
		return width;
	}
	int Monitor::getPhysicalHeight() const {
		int height;
		glfwGetMonitorPhysicalSize(this->glMonitor, nullptr, &height);
		return height;
	}
	Math::Vector2i Monitor::getPosition() const {
		Math::Vector2i pos;

		glfwGetMonitorPos(this->glMonitor, &pos.x, &pos.y);

		return pos;
	}
	int Monitor::getXPos() const {
		int x;
		glfwGetMonitorPos(this->glMonitor, &x, nullptr);
		return x;
	}
	int Monitor::getYPos() const {
		int y;
		glfwGetMonitorPos(this->glMonitor, nullptr, &y);
		return y;
	}
	std::vector<Monitor *> Monitor::getAvailalbeMonitors() {
		std::vector<Monitor *> monitors;

		for (int i = 0; i < (int)Monitor::availableMonitors.size(); i++) {
			monitors.push_back(Monitor::availableMonitors.at(i).get());
		}

		return monitors;
	}
	Monitor *Monitor::getPrimaryMonitor() {
		return Monitor::primaryMonitor;
	}

	GammaRamp Monitor::getCurrentGammaRamp() const {
		const GLFWgammaramp *gm = glfwGetGammaRamp(this->glMonitor);
		GammaRamp gammaRamp;

		gammaRamp.size = gm->size;
		gammaRamp.red = gm->red;
		gammaRamp.green = gm->green;
		gammaRamp.blue = gm->blue;

		return gammaRamp;
	}
	VideoMode Monitor::getCurrentVideoMode() const {
		const GLFWvidmode *vm = glfwGetVideoMode(this->glMonitor);

		VideoMode videoMode;

		videoMode.width = vm->width;
		videoMode.height = vm->height;
		videoMode.rBits = vm->redBits;
		videoMode.gBits = vm->greenBits;
		videoMode.bBits = vm->blueBits;
		videoMode.refreshRate = vm->refreshRate;

		return videoMode;
	}

	void Monitor::setGamma(const float & gamma) {
		glfwSetGamma(this->glMonitor, gamma);
	}
	void Monitor::setGammaRamp(const GammaRamp& gammaRamp) {
		GLFWgammaramp gr;

		gr.size = gammaRamp.size;
		gr.red = gammaRamp.red;
		gr.green = gammaRamp.green;
		gr.blue = gammaRamp.blue;

		glfwSetGammaRamp(this->glMonitor, &gr);
	}

	std::vector<VideoMode>	Monitor::getAvailalbeVideoModes() const {
		int count;

		const GLFWvidmode* glModes = glfwGetVideoModes(this->glMonitor, &count);

		std::vector<VideoMode> videoModes;
		
		for (int i = 0; i < count; i++) {
			VideoMode vm;
			vm.width = glModes[i].width;
			vm.height = glModes[i].height;
			vm.rBits = glModes[i].redBits;
			vm.gBits = glModes[i].greenBits;
			vm.bBits = glModes[i].blueBits;
			vm.refreshRate = glModes[i].refreshRate;
			videoModes.push_back(vm);
		}

		return videoModes;
	}
}}}
