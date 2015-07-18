/*
 * components.h
 *
 *  Created on: May 31, 2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMPONENTS_C_
#define FRAMEWORK_COMPONENTS_C_

#include <fruit/fruit.h>

#include "framework/Mainloop.h"
#include "framework/glfw/MainloopImpl.h"

#include "framework/Window.h"
#include "framework/glfw/WindowImpl.h"

namespace NSComponents {

	inline fruit::Component<NSFramework::Window> getWindowComponent() {
		return fruit::createComponent().bind<NSFramework::Window, NSFramework::WindowImpl>().bind<NSFramework::Mainloop,
		        NSFramework::MainloopImpl>();
	}
}

#endif /* FRAMEWORK_COMPONENTS_C_ */
