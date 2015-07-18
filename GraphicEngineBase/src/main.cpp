/*
 * main.cpp
 *
 *  Created on: 10.05.2015
 *      Author: axp
 */

#include <string>
#include <fruit/fruit.h>

#include "logging/Logging.h"
#include "framework/Components.hpp"
#include "framework/Framework.h"
#include "framework/Window.h"

using fruit::Injector;
using NSFramework::Window;
using NSFramework::Framework;

int main() {
	NSComponents::getWindowComponent();
	Injector<Window> injector(NSComponents::getWindowComponent());
	Window& window = injector.get<Window&>();
	Framework framework(window);
	framework.start();
	return 0;
}
