
//==================================================================================\\
//FILE NAME:			XInput.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/01/2017													\\
//LAST MODIIFED:		04/05/2017													\\
//		  ęCopyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_INPUT_H
#define X_INPUT_H


struct GLFWwindow;


namespace X {	namespace Input {
	enum Key {
		KEY_UNKNOWN = -1,
		KEY_0 = 48,
		KEY_1 = 49,
		KEY_2 = 50,
		KEY_3 = 51,
		KEY_4 = 52,
		KEY_5 = 53,
		KEY_6 = 54,
		KEY_7 = 55,
		KEY_8 = 56,
		KEY_9 = 57,
		KEY_A = 65,
		KEY_B = 66,
		KEY_C = 67,
		KEY_D = 68,
		KEY_E = 69,
		KEY_F = 70,
		KEY_G = 71,
		KEY_H = 72,
		KEY_I = 73,
		KEY_J = 74,
		KEY_K = 75,
		KEY_L = 76,
		KEY_M = 77,
		KEY_N = 78,
		KEY_O = 79,
		KEY_P = 80,
		KEY_Q = 81,
		KEY_R = 82,
		KEY_S = 83,
		KEY_T = 84,
		KEY_U = 85,
		KEY_V = 86,
		KEY_W = 87,
		KEY_X = 88,
		KEY_Y = 89,
		KEY_Z = 90,
		KEY_ESC = 256,
		KEY_F1 = 290,
		KEY_F2 = 291,
		KEY_F3 = 292,
		KEY_F4 = 293,
		KEY_F5 = 294,
		KEY_F6 = 295,
		KEY_F7 = 296,
		KEY_F8 = 297,
		KEY_F9 = 298,
		KEY_F10 = 299,
		KEY_F11 = 300,
		KEY_F12 = 301,
		KEY_F13 = 302,
		KEY_F14 = 303,
		KEY_F15 = 304,
		KEY_F16 = 305,
		KEY_F17 = 306,
		KEY_F18 = 307,
		KEY_F19 = 308,
		KEY_F20 = 309,
		KEY_F21 = 310,
		KEY_F22 = 311,
		KEY_F23 = 312,
		KEY_F24 = 313,
		KEY_SPACE = 32,
		KEY_L_SHIFT = 340,
		KEY_R_SHIFT = 344,
		KEY_L_CTRL = 341,
		KEY_R_CTRL = 345,
		KEY_L_ALT = 342,
		KEY_R_ALT = 346,
		KEY_TAB = 258,
		KEY_GRAVE = 96,
		KEY_BACKSPACE = 259,
		KEY_ENTER = 257,
		KEY_MINUS = 45,
		KEY_EQUALS = 61,
		KEY_L_BRACKET = 91,
		KEY_R_BRACKET = 93,
		KEY_BACKSLASH = 92,
		KEY_SEMICOLON = 59,
		KEY_APOSTROPHE = 39,
		KEY_COMMA = 44,
		KEY_PERIOD = 46,
		KEY_FORWARDSLASH = 47,
		KEY_LEFT = 263,
		KEY_RIGHT = 262,
		KEY_DOWN = 264,
		KEY_UP = 265,
		KEY_L_SUPER = 343,
		KEY_R_SUPER = 347,
		KEY_PAGE_UP = 266,
		KEY_PAGE_DOWN = 267,
		KEY_HOME = 268,
		KEY_END = 269,
		KEY_CAPS_LOCK = 280,
		KEY_SCROLL_LOCK = 281,
		KEY_NUM_LOCK = 282,
		KEY_PRINT_SCREEN = 283,
		KEY_PAUSE = 284,
		KEY_KP_0 = 320,
		KEY_KP_1 = 321,
		KEY_KP_2 = 322,
		KEY_KP_3 = 323,
		KEY_KP_4 = 324,
		KEY_KP_5 = 325,
		KEY_KP_6 = 326,
		KEY_KP_7 = 327,
		KEY_KP_8 = 328,
		KEY_KP_9 = 329,
		KEY_KP_DECIMAL = 330,
		KEY_KP_DIVIDE = 331,
		KEY_KP_MULTIPLY = 332,
		KEY_KP_SUBTRACT = 333,
		KEY_KP_ADD = 334,
		KEY_KP_ENTER = 335,
		KEY_KP_EQUAL = 336,
		KEY_WORLD_1 = 161,
		KEY_WORLD_2 = 162,
	};
	enum MouseButton {
		MOUSE_LEFT = 0,
		MOUSE_RIGHT = 1,
		MOUSE_MIDDLE = 2,
		MOUSE_1 = 0,
		MOUSE_2 = 1,
		MOUSE_3 = 2,
		MOUSE_4 = 3,
		MOUSE_5 = 4,
		MOUSE_6 = 5,
		MOUSE_7 = 6,
		MOUSE_8 = 7,
	};

	namespace detail {

		extern bool keys[512];
		extern bool mouseButtons[16];
		extern double cursorX, cursorY;
		extern double lastCursorX, lastCursorY;
		extern double scrollX, scrollY;

		void glKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void glCursorPosCallback(GLFWwindow* window, double xpos, double ypos);
		void glScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		void glCursorEnterCallback(GLFWwindow* window, int entered);
		void glMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	}

	bool isKeyPressed(Key key);
	bool isMouseButtonPressed(MouseButton button);
	bool isLMBPressed();
	bool isRMBPressed();
	bool isMMBPressed();
	double getCursorX();
	double getCursorY();
	double getLastCursorX();
	double getLastCursorY();
	double getScrollXOffset();
	double getScrollYOffset();

	void updateLastCursorPosistions();
	void resetScrollValues();
	void updateInput();
}}

#endif // !X_INPUT_H
