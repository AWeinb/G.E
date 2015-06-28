/*
 * ISettingsLoader.hxx
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMMON_SETTINGSLOADER_SETTINGSLOADER_H_
#define FRAMEWORK_COMMON_SETTINGSLOADER_SETTINGSLOADER_H_

#include <string>

namespace NSSettings {

	class Settings;
	class SettingsLoader {

		public:
			virtual ~SettingsLoader() {
			}

			virtual void load(Settings*, std::string) = 0;
			virtual bool wasLoadingSuccessful() = 0;
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSLOADER_SETTINGSLOADER_H_ */
