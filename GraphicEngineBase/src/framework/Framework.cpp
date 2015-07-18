/*
 * Framework.cpp
 *
 *  Created on: 14.07.2015
 *      Author: axp
 */

#include <framework/Framework.h>
#include <chrono>
#include <thread>
#include <iostream>

#include "logging/Logging.h"

namespace NSFramework {

	Framework::Framework(Window &window) :
			window(window) {
	}

	Framework::~Framework() {
	}

	void Framework::start() {
		window.create();
		std::cout << "A" << std::endl;
		window.startLooping();
		std::cout << "B" << std::endl;
		window.destroy();
	}

} /* namespace NSFramework */
