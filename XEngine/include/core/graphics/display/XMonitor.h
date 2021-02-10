
//==================================================================================\\
//FILE NAME:			XMonitor.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#ifndef X_MONITOR_H
#define X_MONITOR_H


#include <vector>
#include <map>
#include "core\math\XMath.h"
#include <memory>


struct GLFWmonitor;


namespace X {

	bool initilize();
	void terminate();
	
	namespace Graphics {	namespace Display {


		class Monitor;
		class Window;
		struct VideoMode;
		struct GammaRamp;

		namespace detail {
			class MonitorDeleter final {
			public:
				void operator()(Monitor *m);
			};

			void monitor_callback(GLFWmonitor* monitor, int event);
		}


		struct VideoMode {
			int width, height;
			int rBits, gBits, bBits;
			int refreshRate;

			VideoMode();
			VideoMode(const int & width, const int & height, const int & rBits, const int & gBits, const int & bBits, const int & refreshRate);
		};


		struct GammaRamp {
			unsigned int size;
			unsigned short *red, *green, *blue;

			GammaRamp();
			GammaRamp(unsigned int &size, unsigned short *red, unsigned short *green, unsigned short *blue);
		};


		class Monitor final {
		private:
			GLFWmonitor *glMonitor;

			static std::vector<std::unique_ptr<Monitor, detail::MonitorDeleter>> availableMonitors;
			static std::map<GLFWmonitor *, std::unique_ptr<Monitor, detail::MonitorDeleter> *> monitorMap;

			Monitor(GLFWmonitor * glMonitor);
			Monitor(const Monitor& monitor);
			~Monitor();

			Monitor &operator=(const Monitor& monitor);

			static Monitor *primaryMonitor;

			static bool init();

			friend Window;
			friend detail::MonitorDeleter;
			//friend void detail::monitorCallback(GLFWmonitor* monitor, int event);
			friend bool X::initilize();
			friend void X::terminate();

		public:
			static Monitor *getPrimaryMonitor();
			static std::vector<Monitor *> getAvailalbeMonitors();


			const char *getName() const;
			Math::Vector2i getPhysicalSize() const;
			int getPhysicalWidth() const;
			int getPhysicalHeight() const;
			Math::Vector2i getPosition() const;
			int getXPos() const;
			int getYPos() const;
			VideoMode getCurrentVideoMode() const;
			std::vector<VideoMode> getAvailalbeVideoModes() const;
			GammaRamp getCurrentGammaRamp() const;

			void setGamma(const float & gamma);
			void setGammaRamp(const GammaRamp& gammaRamp);
		};
	}
}}

#endif // !X_MONITOR_H
