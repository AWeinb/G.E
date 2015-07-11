/*
 * settings.test.cpp
 *
 *  Created on: 02.07.2015
 *      Author: axp
 */

#define BOOST_TEST_DYN_LINK

#include <boost/test/auto_unit_test.hpp>
#include <string>
#include <stdio.h>

#include "framework/common/Settings.h"
#include "framework/common/settingsLoader/SettingsLoader.h"
#include "framework/common/settingsWriter/SettingsWriter.h"
#include "framework/common/settingsLoader/SimpleSettingsLoader.h"
#include "framework/common/settingsWriter/SimpleSettingsWriter.h"

using namespace NSSettings;

const std::string SETTINGS_1_PATH = "program/assets/settings/settings.ini";

BOOST_AUTO_TEST_SUITE (Settings_Tests)

	BOOST_AUTO_TEST_CASE(testSettingLoading) {
		// Given
		auto settingsLoader = SimpleSettingsLoader();
		auto settingsWriter = SimpleSettingsWriter();
		auto settings = new Settings(settingsLoader, settingsWriter);

		SettingsEntry testEntry1 = SettingsEntry("category1", "name1");
		SettingsEntry testEntry2 = SettingsEntry("category2", "name2");
		SettingsEntry testEntry3 = SettingsEntry("category3", "name3");
		SettingsEntry testEntry4 = SettingsEntry("category4", "name4");

		remove(SETTINGS_1_PATH.c_str());

		// When
		settings->set(testEntry1, "1");
		settings->set(testEntry2, "2");
		settings->set(testEntry3, "3");
		settings->set(testEntry4, "4");

		settings->store(SETTINGS_1_PATH);
		settings->clear();
		settings->load(SETTINGS_1_PATH);

		// Then
		BOOST_CHECK_EQUAL(settings->get(testEntry1), "1");
		BOOST_CHECK_EQUAL(settings->get(testEntry2), "2");
		BOOST_CHECK_EQUAL(settings->get(testEntry3), "3");
		BOOST_CHECK_EQUAL(settings->get(testEntry4), "4");

		delete settings;
	}

	BOOST_AUTO_TEST_SUITE_END()

