/*
 * Framework.h
 *
 *  Created on: 11.07.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_FRAMEWORK_H_
#define FRAMEWORK_FRAMEWORK_H_

#include <fruit/fruit.h>

#include "Window.h"
#include "Mainloop.h"

namespace NSFramework {

	class Framework {

		public:
			INJECT(Framework(Window &window));
			virtual ~Framework();

			virtual void start();

		private:
			Window &window;
	};

} /* namespace NSFramework */

#endif /* FRAMEWORK_FRAMEWORK_H_ */
