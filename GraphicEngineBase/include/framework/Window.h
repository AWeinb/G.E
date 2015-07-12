/*
 * Window.h
 *
 *  Created on: 11.07.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_WINDOW_H_
#define FRAMEWORK_WINDOW_H_

#include <vector>
#include <tuple>
#include <string>

namespace NSFramework {

	typedef std::tuple<int, int> size;
	typedef std::tuple<int, int> position;

	struct Callback {
	};

	struct Monitor {
	};

	class Window {

		public:
			virtual ~Window() {
			}

			virtual void create() = 0;
			virtual void setCreationHint(int hint, int value) = 0;

			virtual void show() = 0;
			virtual bool isShown() = 0;

			virtual void hide() = 0;
			virtual bool isHidden() = 0;

			virtual void setMonitor(Monitor monitor) = 0;
			virtual std::vector<Monitor> getMonitors() = 0;
			virtual Monitor getMonitor() = 0;

			virtual void setBounds(int x, int y, int width, int height) = 0;
			virtual void setSize(int width, int height) = 0;
			virtual size getSize() = 0;

			virtual void setPosition(int x, int y) = 0;
			virtual position getPosition() = 0;

			virtual void setFramebufferSize(int width, int height) = 0;
			virtual size getFramebufferSize() = 0;

			virtual void setFullscreen(bool fullscreen) = 0;
			virtual bool isFullscreen() = 0;

			virtual void setMinimized(bool minimized) = 0;
			virtual bool isMinimized() = 0;

			virtual void setTitle(std::string title) = 0;
			virtual std::string getTitle() = 0;

			virtual void setCloseRequested(bool closed) = 0;
			virtual bool isCloseRequested() = 0;

			virtual void setSwapInterval(int interval) = 0;
			virtual int getSwapInterval() = 0;
			virtual void swapBuffers() = 0;

			virtual bool isFocused() = 0;
			virtual int getWindowAttribute(int id) = 0;

			virtual void setCloseCallback(Callback callback) = 0;
			virtual void setResizeCallback(Callback callback) = 0;
			virtual void setFramebufferResizeCallback(Callback callback) = 0;
			virtual void setPositionCallback(Callback callback) = 0;
			virtual void setMinimizeCallback(Callback callback) = 0;
			virtual void setFocusCallback(Callback callback) = 0;
			virtual void setDirtyCallback(Callback callback) = 0;

	};

} /* namespace NSFramework */

#endif /* FRAMEWORK_WINDOW_H_ */
