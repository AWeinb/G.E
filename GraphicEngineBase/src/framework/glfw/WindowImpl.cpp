/*
 * WindowImpl.cpp
 *
 *  Created on: 11.07.2015
 *      Author: axp
 */

#include <framework/glfw/WindowImpl.h>
#include <exception>

namespace NSFramework {

	WindowImpl::WindowImpl(Mainloop& loop) :
			loop(loop) {
		window = nullptr;
		if (!glfwInit()) {
			throw std::exception();
		}
	}

	WindowImpl::~WindowImpl() {
		destroy();
		glfwTerminate();
	}

	void WindowImpl::create() {
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
		auto windowTmp = glfwCreateWindow(mode->width, mode->height, "", glfwGetPrimaryMonitor(), window);
		glfwDestroyWindow(window);
		window = windowTmp;
		if (!window) {
			throw std::exception();
		}
		glfwMakeContextCurrent(window);
	}

	void WindowImpl::destroy() {
		glfwDestroyWindow(window);
		window = nullptr;
	}

	void WindowImpl::startLooping() {
		while (!isCloseRequested()) {
			this->loop.runOnce();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void WindowImpl::setCreationHint(int hint, int value) {
	}

	void WindowImpl::show() {
		glfwShowWindow(window);
	}

	bool WindowImpl::isShown() {
		return getWindowAttribute(GLFW_VISIBLE);
	}

	void WindowImpl::hide() {
		glfwHideWindow(window);
	}

	bool WindowImpl::isHidden() {
		return !getWindowAttribute(GLFW_VISIBLE);
	}

	void WindowImpl::setMonitor(Monitor monitor) {
	}
	std::vector<Monitor> WindowImpl::getMonitors() {
		return std::vector<Monitor>();
	}
	Monitor WindowImpl::getMonitor() {
		return Monitor();
	}

	void WindowImpl::setBounds(int x, int y, int width, int height) {
		setSize(width, height);
		setPosition(x, y);
	}

	void WindowImpl::setSize(int width, int height) {
		glfwSetWindowSize(window, width, height);
	}

	size WindowImpl::getSize() {
		int w, h;
		glfwGetWindowSize(window, &w, &h);
		windowSize = size(w, h);
		return windowSize;
	}

	void WindowImpl::setPosition(int x, int y) {
		glfwSetWindowPos(window, x, y);
	}

	position WindowImpl::getPosition() {
		int x, y;
		glfwGetWindowPos(window, &x, &y);
		windowPosition = position(x, y);
		return windowPosition;
	}

	void WindowImpl::setFullscreen(bool fullscreen) {
	}

	bool WindowImpl::isFullscreen() {
		return false;
	}

	void WindowImpl::setMinimized(bool minimized) {
		if (minimized) {
			glfwIconifyWindow(window);
		} else {
			glfwRestoreWindow(window);
		}
	}

	bool WindowImpl::isMinimized() {
		return getWindowAttribute(GLFW_ICONIFIED);
	}

	void WindowImpl::setTitle(std::string title) {
		glfwSetWindowTitle(window, title.c_str());
	}

	void WindowImpl::setCloseRequested(bool close) {
		glfwSetWindowShouldClose(window, close);
	}

	bool WindowImpl::isCloseRequested() {
		return glfwWindowShouldClose(window);
	}

	void WindowImpl::setSwapInterval(int interval) {
		glfwSwapInterval(interval);
	}

	void WindowImpl::swapBuffers() {
		glfwSwapBuffers(window);
	}

	bool WindowImpl::isFocused() {
		return getWindowAttribute(GLFW_FOCUSED);
	}

	int WindowImpl::getWindowAttribute(int id) {
		return glfwGetWindowAttrib(window, id);
	}

	void WindowImpl::setCloseCallback(Callback& callback) {
		auto cb = static_cast<CloseCallback&>(callback);
		glfwSetWindowCloseCallback(window, cb.callback);
	}

	void WindowImpl::setResizeCallback(Callback callback) {
	}
	void WindowImpl::setFramebufferResizeCallback(Callback callback) {
	}
	void WindowImpl::setPositionCallback(Callback callback) {
	}
	void WindowImpl::setMinimizeCallback(Callback callback) {
	}
	void WindowImpl::setFocusCallback(Callback callback) {
	}
	void WindowImpl::setDirtyCallback(Callback callback) {
	}

} /* namespace NSFramework */
