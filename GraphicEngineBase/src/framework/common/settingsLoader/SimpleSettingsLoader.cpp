/*
 * SimpleSettingsLoader.cpp
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#include <string>
#include <fstream>

#include "framework/common/settingsLoader/SimpleSettingsLoader.h"
#include "framework/common/Settings.h"
#include "util/StringUtil.h"

namespace NSSettings {

	SimpleSettingsLoader::SimpleSettingsLoader() {
		loadSuccess = false;
	}

	SimpleSettingsLoader::~SimpleSettingsLoader() {
	}

	void SimpleSettingsLoader::load(settingsMap& settingsData, std::string file) {
		loadSuccess = false;
		if (isFileValid(file)) {
			parseFile(settingsData, file);
			loadSuccess = true;
		}
	}

	bool SimpleSettingsLoader::isFileValid(std::string file) {
		if (file.empty()) {
			return false;
		}
		std::ifstream ifile(file.c_str());
		if (ifile.is_open()) {
			ifile.close();
			return true;
		}
		return false;
	}

	void SimpleSettingsLoader::parseFile(settingsMap& settingsData, std::string file) {
		std::string category = "";
		std::string key = "";
		std::string value = "";
		std::string line;
		std::ifstream infile(file);
		while (std::getline(infile, line)) {
			parseLineInto(line, category, key, value);
			setSettingToMap(settingsData, category, key, value);
			key = "";
			value = "";
		}
	}

	void SimpleSettingsLoader::parseLineInto(std::string& line, std::string& category, std::string& key, std::string& value) {
		line = Util::trim(line);
		if (!line.empty() && line.substr(0, COMMENT.size()) != COMMENT) {
			if (line.substr(0, CATEGORY_START.size()) == CATEGORY_START) {
				std::size_t posStart = line.find(CATEGORY_START) + 1;
				std::size_t posEnd = line.find(CATEGORY_END) - 1;
				category = line.substr(posStart, posEnd);

			} else {
				std::vector<std::string> tokens;
				Util::split(tokens, line, ENTRY_DIVIDER);
				if (tokens.size() == 2) {
					key = Util::trim(tokens[0]);
					value = Util::trim(tokens[1]);
				}
			}
		}
	}

	void SimpleSettingsLoader::setSettingToMap(settingsMap& settingsData, std::string& category, std::string& key,
	        std::string& value) {
		if (!category.empty() && !key.empty() && !value.empty()) {
			if (settingsData.find(category) == settingsData.end()) {
				settingsData[category] = std::map<std::string, std::string>();
			}
			settingsData[category][key] = value;
		}
	}

	bool SimpleSettingsLoader::wasLoadingSuccessful() {
		return loadSuccess;
	}

} /* namespace NSSettings */
