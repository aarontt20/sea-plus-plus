
//==================================================================================\\
//FILE NAME:			XInput.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/02/2017													\\
//LAST MODIIFED:		04/05/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "core\input\XInput.h"
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <iostream>


namespace X {	namespace Input {

	namespace detail {

		bool keys[512];
		bool mouseButtons[16];
		double cursorX, cursorY;
		double lastCursorX, lastCursorY;
		double scrollX, scrollY;

		void glKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key >= 0 && key < 512) {
				if (action == GLFW_PRESS) { //Pressed
					keys[key] = true;
				}
				else if (action == GLFW_RELEASE) { //Resleased
					keys[key] = false;
				}
			}
		}
		void glMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			if (button >= 0 && button < 16) {
				if (action == 1) { //Pressed
					mouseButtons[button] = true;
				}
				else if (action == 0) { //Resleased
					mouseButtons[button] = false;
				}
			}
		}
		void glCursorPosCallback(GLFWwindow* window, double xPos, double yPos) {
			cursorX = xPos;
			cursorY = yPos;
		}
		void glScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
			scrollX += xOffset;
			scrollY += yOffset;
		}
		void glCursorEnterCallback(GLFWwindow* window, int entered);
	}
	
	bool isKeyPressed(Key key) {
		if (key >= 0 && key < 512) {
			return detail::keys[key];
		}
		return false;
	}
	bool isMouseButtonPressed(MouseButton button) {
		if (button >= 0 && button < 16) {
			return detail::mouseButtons[button];
		}
		return false;
	}
	bool isLMBPressed() {
		return isMouseButtonPressed(MOUSE_LEFT);
	}
	bool isRMBPressed() {
		return isMouseButtonPressed(MOUSE_RIGHT);
	}
	bool isMMBPressed() {
		return isMouseButtonPressed(MOUSE_MIDDLE);
	}
	double getCursorX() {
		return detail::cursorX;
	}
	double getCursorY() {
		return detail::cursorY;
	}
	double getLastCursorX() {
		return detail::lastCursorX;
	}
	double getLastCursorY() {
		return detail::lastCursorY;
	}
	double getScrollXOffset() {
		return detail::scrollX;
	}
	double getScrollYOffset() {
		return detail::scrollY;
	}

	void updateLastCursorPosistions() {
		detail::lastCursorX = detail::cursorX;
		detail::lastCursorY = detail::cursorY;
	}
	void resetScrollValues() {
		detail::scrollX = 0;
		detail::scrollY = 0;
	}
	void updateInput() {
		updateLastCursorPosistions();
		resetScrollValues();
	}
}}