/*
 * Settings.h
 *
 *  Created on: 09.06.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMMON_SETTINGS_H_
#define FRAMEWORK_COMMON_SETTINGS_H_

#include <string>
#include <map>

#include "SettingsCommon.h"
#include "settingsLoader/SettingsLoader.h"
#include "settingsWriter/SettingsWriter.h"

namespace NSSettings {

	struct SettingsEntry {

			std::string CATEGORY;
			std::string KEY;

			SettingsEntry(std::string category, std::string name) {
				CATEGORY = category;
				KEY = name;
			}
	};

	class Settings {

		public:
			Settings(SettingsLoader& settingsLoader, SettingsWriter& settingsWriter);
			virtual ~Settings();

			virtual void load(std::string path);
			virtual void store(std::string path);
			virtual bool isLoadedSuccessfully();
			virtual bool wasJustStoredSuccessfully();
			virtual void clear();

			virtual void set(SettingsEntry& setting, std::string value);
			virtual std::string get(SettingsEntry& setting);

		private:
			SettingsLoader& settingsLoader;
			SettingsWriter& settingsWriter;
			settingsMap settingsData;
			bool isLoaded;
			bool isStored;

			void set(std::string category, std::string key, std::string value);
			std::string get(std::string category, std::string key);
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGS_H_ */
