/*
 * WindowImpl.h
 *
 *  Created on: 11.07.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_GLFW_WINDOWIMPL_H_
#define FRAMEWORK_GLFW_WINDOWIMPL_H_

#include <GLFW/glfw3.h>
#include <fruit/fruit.h>

#include "../Window.h"

namespace NSFramework {

	struct CloseCallback: public Callback {
			GLFWwindowclosefun callback;
	};

	struct ResizeCallback: public Callback {
			GLFWwindowsizefun callback;
	};

	struct FramebufferResizeCallback: public Callback {
			GLFWframebuffersizefun callback;
	};

	struct PositionCallback: public Callback {
			GLFWwindowposfun callback;
	};

	struct MinimizeCallback: public Callback {
			GLFWwindowiconifyfun callback;
	};

	struct FocusCallback: public Callback {
			GLFWwindowfocusfun callback;
	};

	struct DirtyCallback: public Callback {
			GLFWwindowrefreshfun callback;
	};

	struct GLFWMonitor: public Monitor {
	};

	class WindowImpl: public Window {

		public:
			INJECT(WindowImpl(Mainloop& loop));
			virtual ~WindowImpl();

			virtual void create() override;
			virtual void destroy() override;
			virtual void startLooping() override;

			virtual void setCreationHint(int hint, int value) override;

			virtual void show() override;
			virtual bool isShown() override;

			virtual void hide() override;
			virtual bool isHidden() override;

			virtual void setMonitor(Monitor monitor) override;
			virtual std::vector<Monitor> getMonitors() override;
			virtual Monitor getMonitor() override;

			virtual void setBounds(int x, int y, int width, int height) override;
			virtual void setSize(int width, int height) override;
			virtual size getSize() override;

			virtual void setPosition(int x, int y) override;
			virtual position getPosition() override;

			virtual void setFullscreen(bool fullscreen) override;
			virtual bool isFullscreen() override;

			virtual void setMinimized(bool minimized) override;
			virtual bool isMinimized() override;

			virtual void setTitle(std::string title) override;

			virtual void setCloseRequested(bool close) override;
			virtual bool isCloseRequested() override;

			virtual void setSwapInterval(int interval) override;
			virtual void swapBuffers() override;

			virtual bool isFocused() override;
			virtual int getWindowAttribute(int id) override;

			virtual void setCloseCallback(Callback& callback) override;
			virtual void setResizeCallback(Callback callback) override;
			virtual void setFramebufferResizeCallback(Callback callback) override;
			virtual void setPositionCallback(Callback callback) override;
			virtual void setMinimizeCallback(Callback callback) override;
			virtual void setFocusCallback(Callback callback) override;
			virtual void setDirtyCallback(Callback callback) override;

		private:
			GLFWwindow* window;
			Mainloop& loop;

			size windowSize;
			size framebufferSize;
			position windowPosition;

	};

} /* namespace NSFramework */

#endif /* FRAMEWORK_GLFW_WINDOWIMPL_H_ */
