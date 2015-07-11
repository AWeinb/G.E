/*
 * SimpleSettingsWriter.cpp
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#include <iostream>
#include <fstream>

#include "framework/common/settingsWriter/SimpleSettingsWriter.h"

namespace NSSettings {

	SimpleSettingsWriter::SimpleSettingsWriter() {
		wasLastWriteSuccessful = false;
	}

	SimpleSettingsWriter::~SimpleSettingsWriter() {
	}

	void SimpleSettingsWriter::write(settingsMap& settingsData, std::string filepath) {
		wasLastWriteSuccessful = false;
		if (isFileOperationPossible(filepath)) {
			std::string settingsString = createSettingsString(settingsData);
			writeSettingsToFile(filepath, settingsString);
			wasLastWriteSuccessful = true;
		}
	}

	bool SimpleSettingsWriter::isFileOperationPossible(std::string& filepath) {
		std::ofstream ofile(filepath);
		if (ofile.is_open()) {
			ofile.close();
			return true;
		}
		return false;
	}

	std::string SimpleSettingsWriter::createSettingsString(settingsMap& settingsData) {
		std::string settingsString = "# Comment \n";
		std::string key;
		std::string value;
		for (auto const &it1 : settingsData) {
			settingsString += createCategoryEntry(it1.first);
			for (auto const &it2 : it1.second) {
				settingsString += createDataEntry(it2.first, it2.second);
			}
		}
		return settingsString;
	}

	std::string SimpleSettingsWriter::createCategoryEntry(std::string category) {
		return "\n" + CATEGORY_START + category + CATEGORY_END + "\n";
	}

	std::string SimpleSettingsWriter::createDataEntry(std::string key, std::string value) {
		return "\t" + key + ENTRY_DIVIDER + value + "\n";
	}

	void SimpleSettingsWriter::writeSettingsToFile(std::string& filepath, std::string& settingsAsString) {
		std::ofstream ofile(filepath);
		if (ofile.is_open()) {
			ofile << settingsAsString;
			ofile.close();
		}
	}

	bool SimpleSettingsWriter::wasWritingSuccessful() {
		return wasLastWriteSuccessful;
	}

} /* namespace NSSettings */
