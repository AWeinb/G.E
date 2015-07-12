/*
 * WindowImpl.cpp
 *
 *  Created on: 11.07.2015
 *      Author: axp
 */

#include <framework/glfw/WindowImpl.h>

namespace NSFramework {

	WindowImpl::WindowImpl() {
	}

	WindowImpl::~WindowImpl() {
	}

	void WindowImpl::create() {
	}
	void WindowImpl::setCreationHint(int hint, int value) {
	}

	void WindowImpl::show() {
	}
	bool WindowImpl::isShown() {
		return false;
	}

	void WindowImpl::hide() {
	}
	bool WindowImpl::isHidden() {
		return false;
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
	}
	void WindowImpl::setSize(int width, int height) {
	}
	size WindowImpl::getSize() {
		return size(0,0);
	}

	void WindowImpl::setPosition(int x, int y) {
	}
	position WindowImpl::getPosition() {
		return position(0,0);
	}

	void WindowImpl::setFramebufferSize(int width, int height) {
	}
	size WindowImpl::getFramebufferSize() {
		return size(0,0);
	}

	void WindowImpl::setFullscreen(bool fullscreen) {
	}
	bool WindowImpl::isFullscreen() {
		return false;
	}

	void WindowImpl::setMinimized(bool minimized) {
	}
	bool WindowImpl::isMinimized() {
		return false;
	}

	void WindowImpl::setTitle(std::string title) {
	}
	std::string WindowImpl::getTitle() {
		return "";
	}

	void WindowImpl::setCloseRequested(bool closed) {
	}
	bool WindowImpl::isCloseRequested() {
		return false;
	}

	void WindowImpl::setSwapInterval(int interval) {
	}
	int WindowImpl::getSwapInterval() {
		return 0;
	}
	void WindowImpl::swapBuffers() {
	}

	bool WindowImpl::isFocused() {
		return false;
	}
	int WindowImpl::getWindowAttribute(int id) {
		return 0;
	}

	void WindowImpl::setCloseCallback(Callback callback) {
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
