
//==================================================================================\\
//FILE NAME:			XWindow.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/19/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_WINDOW_H
#define X_WINDOW_H


#include <map>
#include "core\math\XMath.h"
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"


struct GLFWwindow;

namespace X {	namespace Graphics {	namespace Display {
	
	class Monitor;
	struct VideoMode;

	void windowHint(int hint, int value);
	void resetWindowHints();

	class Window {
	private:
		GLFWwindow *glWindow;
		
		static std::map<GLFWwindow*, Window*> windowMap;

		friend class Monitor;
		
	protected:
		const char *title;

	public:
		enum Hint {
			RESIZABLE = GLFW_RESIZABLE,
			VISIBLE = GLFW_VISIBLE,
			DECORATED = GLFW_DECORATED,
			FOCUSED = GLFW_FOCUSED,
			AUTO_MINIMIZE = GLFW_AUTO_ICONIFY,
			ALWAYS_ON_TOP = GLFW_FLOATING,
			MAXIMIZE = GLFW_MAXIMIZED,
			RED_BITS = GLFW_RED_BITS,
			GREEN_BITS = GLFW_GREEN_BITS,
			BLUE_BITS = GLFW_BLUE_BITS,
			ALPHA_BITS = GLFW_ALPHA_BITS,
			DEPTH_BITS = GLFW_DEPTH_BITS,
			STENCIL_BITS = GLFW_STENCIL_BITS,
			SAMPLES = GLFW_SAMPLES,
			DOUBLEBUFFER = GLFW_DOUBLEBUFFER,
			SRGB_CAPABLE = GLFW_SRGB_CAPABLE,
			STEREOSCOPIC_RENDERING = GLFW_STEREO,
			REFRESH_RATE = GLFW_REFRESH_RATE
		};

		Window();
		Window(const unsigned int& width, const unsigned int& height, const char *title, Monitor *monitor, Window *share);
		~Window();

		Math::Vector2i getClientSize() const;
		int getClientWidth() const;
		int getClientHeight() const;
		Math::Vector2i getClientPosition() const;
		int getClientXPos() const;
		int getClientYPos() const;
		Math::Vector2i getPosition() const;
		int getXPos() const;
		int getYPos() const;
		Math::Vector2i getSize() const;
		int getWidth() const;
		int getHeight() const;
		Math::Vector2i getFrameBufferSize() const;
		int getFrameBufferWidth() const;
		int getFrameBufferHeight() const;
		int getDecorationsLeftSize() const;
		int getDecorationsTopSize() const;
		int getDecorationsBottomSize() const;
		int getDecorationsRightSize() const;
		bool isInFocus() const;
		bool isResizable() const;
		bool isMinimized() const;
		bool isMaximized() const;
		bool isFullScreen() const;
		bool isVisible() const;
		bool isDecorated() const;
		bool isAlwaysOnTop() const;
		const char * getTitle() const;
		bool requestedClose() const;
		Monitor *getMonitor() const;
		
		void setClientSize(const Math::Vector2i &size);
		void setClientSize(const int &width, const int &height);
		void setClientWidth(const int& width);
		void setClientHeight(const int& height);
		void setClientPosition(const Math::Vector2i &pos);
		void setClientPosition(const int &xPos, const int &yPos);
		void setClientXPos(const int &xPos);
		void setClientYPos(const int &yPos);
		void setPosition(const Math::Vector2i &pos);
		void setPosition(const int &xPos, int &yPos);
		void setXPos(const int& xPos);
		void setYPos(const int& yPos);
		void setSize(const Math::Vector2i &size);
		void setSize(const int &width, const int &height);
		void setWidth(const int &width);
		void setHeight(const int &height);
		void setTitle(const char* title);
		void setShouldClose(const bool& b);
		void maintainAspectRatio(const int &num, const int &denom);
		void releaseMaintainedAspectRatio();
		void setSizeLimits(const int& minWidth, const int &minHeight, const int &maxWidth, const int maxHeight);
		void releaseSizeLimits();
		void setFullscreen(Monitor *monitor, const VideoMode &vidMode);
		void setFullscreen(Monitor *monitor, const Math::Vector2i &size, const int &refreshRate);
		void setFullscreen(Monitor *monitor, const int &width, const int &height, const int &refreshRate);
		void setWindowed(const Math::Vector2i &pos, const Math::Vector2i &size);
		void setWindowed(const int &xPos, const int &yPos, const int &width, const int &height);
		void setMinimized(const bool &minimize);
		void minimize();
		void setMaximized(const bool &maximize);
		void maximize();
		void restore();
		void setVisiblity(const bool &visible);
		void hide();
		void show();
		void focus();
		void processEvents();
		void swapBuffers();
		void setShowCursor(const bool& b);
		void showCursor();
		void hideCursor();
	};
}}}

#endif // !X_WINDOW_H
