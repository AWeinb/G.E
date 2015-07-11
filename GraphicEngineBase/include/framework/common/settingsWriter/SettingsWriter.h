/*
 * ISettingsWriter.hxx
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMMON_SETTINGSWRITER_SETTINGSWRITER_H_
#define FRAMEWORK_COMMON_SETTINGSWRITER_SETTINGSWRITER_H_

#include <string>
#include <map>

#include "../SettingsCommon.h"

namespace NSSettings {

	class SettingsWriter {

		public:
			virtual ~SettingsWriter() {
			}

			virtual void write(settingsMap& d, std::string) = 0;
			virtual bool wasWritingSuccessful() = 0;
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSWRITER_SETTINGSWRITER_H_ */
