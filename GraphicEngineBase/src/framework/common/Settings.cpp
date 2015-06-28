/*
 * Settings.cpp
 *
 *  Created on: 09.06.2015
 *      Author: axp
 */

#include "framework/common/Settings.h"

#include "../components.cpp"

namespace NSSettings {

	/*-------------------------------------------------------------*/
	/* SETTING IDS                                                 */
	/*_____________________________________________________________*/

	auto TEST = SettingEntry("", "");

	/*_____________________________________________________________*/

	Settings::Settings() {
		loaderInjector = new fruit::Injector<SettingsLoader>(NSComponents::getSettingsLoaderComponent());
		settingsLoader = loaderInjector->get<SettingsLoader*>();
		writerInjector = new fruit::Injector<SettingsWriter>(NSComponents::getSettingsWriterComponent());
		settingsWriter = writerInjector->get<SettingsWriter*>();

		settingsMap = new std::map<std::string, std::map<std::string, std::string>>();
		isLoaded = false;
		isStored = true;
	}

	Settings::~Settings() {
		delete loaderInjector;
		delete writerInjector;
		settingsLoader = nullptr;
		settingsWriter = nullptr;
		for (auto& entry : *settingsMap) {
			delete &entry.second;
		}
		delete settingsMap;
		settingsMap = nullptr;
	}

	void Settings::load(std::string file) {
		settingsLoader->load(this, file);
		isLoaded = settingsLoader->wasLoadingSuccessful();
		isStored = !isLoaded;
	}

	void Settings::store(std::string file) {
		settingsWriter->write(settingsMap, file);
		isStored = false;
	}

	bool Settings::isLoadedSuccessfully() {
		return isLoaded;
	}

	bool Settings::wasJustStoredSuccessfully() {
		return isStored;
	}

	void Settings::set(SettingEntry setting, std::string value) {
		auto category = setting.CATEGORY;
		auto key = setting.KEY;
		if (settingsMap->find(category) != settingsMap->end()) {
			(*settingsMap)[category] = *(new std::map<std::string, std::string>());
		}
		(*settingsMap)[category][key] = value;
	}
	std::string Settings::get(SettingEntry setting) {
		auto category = setting.CATEGORY;
		auto key = setting.KEY;
		return (*settingsMap)[category][key];
	}

} /* namespace NSSettings */
