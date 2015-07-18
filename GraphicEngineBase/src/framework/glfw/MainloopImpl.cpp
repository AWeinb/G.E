/*
 * MainloopImpl.cpp
 *
 *  Created on: 14.07.2015
 *      Author: axp
 */

#include <framework/glfw/MainloopImpl.h>
#include <chrono>
#include <thread>

namespace NSFramework {

	MainloopImpl::MainloopImpl() {
	}

	MainloopImpl::~MainloopImpl() {
	}

	void MainloopImpl::runOnce() {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

} /* namespace NSFramework */
