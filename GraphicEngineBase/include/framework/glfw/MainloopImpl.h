/*
 * MainloopImpl.h
 *
 *  Created on: 14.07.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_GLFW_MAINLOOPIMPL_H_
#define FRAMEWORK_GLFW_MAINLOOPIMPL_H_

#include <fruit/fruit.h>

#include "../Mainloop.h"

namespace NSFramework {

	class MainloopImpl : public Mainloop {

		public:
			INJECT(MainloopImpl());
			virtual ~MainloopImpl();

			virtual void runOnce() override;
	};

} /* namespace NSFramework */

#endif /* FRAMEWORK_GLFW_MAINLOOPIMPL_H_ */
