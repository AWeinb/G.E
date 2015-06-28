/*
 * SimpleSettingsLoader.cpp
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#include <iostream>
#include <fstream>
#include <string>

#include "framework/common/settingsLoader/SimpleSettingsLoader.h"
#include "framework/common/Settings.h"
#include "util/StringUtil.h"

namespace NSSettings {

	SimpleSettingsLoader::SimpleSettingsLoader() {
		loadSuccess = false;
	}

	SimpleSettingsLoader::~SimpleSettingsLoader() {
	}

	void SimpleSettingsLoader::load(Settings* settings, std::string file) {
		loadSuccess = false;
	}

	bool SimpleSettingsLoader::wasLoadingSuccessful() {
		return loadSuccess;
	}

} /* namespace NSSettings */
