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

namespace NSSettings {

	class SettingsWriter {

		public:
			virtual ~SettingsWriter() {
			}

			virtual bool write(std::map<std::string, std::map<std::string, std::string>>*, std::string) = 0;
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSWRITER_SETTINGSWRITER_H_ */
