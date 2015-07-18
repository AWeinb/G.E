/*
 * Mainloop.h
 *
 *  Created on: 14.07.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_MAINLOOP_H_
#define FRAMEWORK_MAINLOOP_H_

namespace NSFramework {

	class Mainloop {

		public:
			virtual ~Mainloop() {
			}

			virtual void runOnce() = 0;
	};

} /* namespace NSFramework */

#endif /* FRAMEWORK_MAINLOOP_H_ */
