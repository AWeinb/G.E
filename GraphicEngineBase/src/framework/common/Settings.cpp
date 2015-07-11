/*
 * Settings.cpp
 *
 *  Created on: 09.06.2015
 *      Author: axp
 */

#include "framework/common/Settings.h"

namespace NSSettings {

	/*-------------------------------------------------------------*/
	/* SETTING IDS                                                 */
	/*_____________________________________________________________*/

	auto TEST = SettingsEntry("", "");

	/*_____________________________________________________________*/

	Settings::Settings(SettingsLoader& settingsLoader, SettingsWriter& settingsWriter) :
			settingsLoader(settingsLoader), settingsWriter(settingsWriter) {
		settingsData = settingsMap();
		isLoaded = false;
		isStored = true;
	}

	Settings::~Settings() {
	}

	void Settings::load(std::string file) {
		settingsLoader.load(settingsData, file);
		isLoaded = settingsLoader.wasLoadingSuccessful();
		isStored = !isLoaded;
	}

	void Settings::store(std::string file) {
		settingsWriter.write(settingsData, file);
		isStored = settingsWriter.wasWritingSuccessful();
	}

	bool Settings::isLoadedSuccessfully() {
		return isLoaded;
	}

	bool Settings::wasJustStoredSuccessfully() {
		return isStored;
	}

	void Settings::clear() {
		settingsData.clear();
	}

	void Settings::set(SettingsEntry& setting, std::string value) {
		auto category = setting.CATEGORY;
		auto key = setting.KEY;
		set(category, key, value);
	}

	std::string Settings::get(SettingsEntry& setting) {
		auto category = setting.CATEGORY;
		auto key = setting.KEY;
		return get(category, key);
	}

	void Settings::set(std::string category, std::string key, std::string value) {
		if (settingsData.find(category) == settingsData.end()) {
			settingsData[category] = std::map<std::string, std::string>();
		}
		settingsData[category][key] = value;
	}

	std::string Settings::get(std::string category, std::string key) {
		return settingsData[category][key];
	}

} /* namespace NSSettings */
