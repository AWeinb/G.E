/*
 * Settings.h
 *
 *  Created on: 09.06.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMMON_SETTINGS_H_
#define FRAMEWORK_COMMON_SETTINGS_H_

#include <fruit/fruit.h>
#include <string>
#include <map>

#include "framework/common/settingsLoader/SettingsLoader.h"
#include "framework/common/settingsWriter/SettingsWriter.h"

namespace NSSettings {

	struct SettingEntry {

			std::string CATEGORY;
			std::string KEY;

			SettingEntry(std::string category, std::string name) {
				CATEGORY = category;
				KEY = name;
			}

			~SettingEntry() {
				CATEGORY = nullptr;
				KEY = nullptr;
			}
	};

	class Settings {

		public:
			Settings();
			virtual ~Settings();

			virtual void load(std::string path);
			virtual void store(std::string path);
			virtual bool isLoadedSuccessfully();
			virtual bool wasJustStoredSuccessfully();

			virtual void set(SettingEntry setting, std::string value);
			virtual std::string get(SettingEntry setting);

		private:
			fruit::Injector<SettingsLoader>* loaderInjector;
			fruit::Injector<SettingsWriter>* writerInjector;
			SettingsLoader* settingsLoader;
			SettingsWriter* settingsWriter;

			std::map<std::string, std::map<std::string, std::string>>* settingsMap;
			bool isLoaded;
			bool isStored;
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGS_H_ */
