/*
 * components.h
 *
 *  Created on: May 31, 2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMPONENTS_C_
#define FRAMEWORK_COMPONENTS_C_

#include <fruit/fruit.h>

#include "framework/common/settingsLoader/SettingsLoader.h"
#include "framework/common/settingsLoader/SimpleSettingsLoader.h"

#include "framework/common/settingsWriter/SettingsWriter.h"
#include "framework/common/settingsWriter/SimpleSettingsWriter.h"

namespace NSComponents {

	inline fruit::Component<NSSettings::SettingsLoader> getSettingsLoaderComponent() {
		return fruit::createComponent().bind<NSSettings::SettingsLoader, NSSettings::SimpleSettingsLoader>();
	}

	inline fruit::Component<NSSettings::SettingsWriter> getSettingsWriterComponent() {
		return fruit::createComponent().bind<NSSettings::SettingsWriter, NSSettings::SimpleSettingsWriter>();
	}
}

#endif /* FRAMEWORK_COMPONENTS_C_ */
