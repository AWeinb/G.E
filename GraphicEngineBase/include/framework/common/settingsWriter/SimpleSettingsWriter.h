/*
 * SimpleSettingsWriter.h
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMMON_SETTINGSWRITER_SIMPLESETTINGSWRITER_H_
#define FRAMEWORK_COMMON_SETTINGSWRITER_SIMPLESETTINGSWRITER_H_

#include <fruit/fruit.h>

#include "SettingsWriter.h"

namespace NSSettings {

	class SimpleSettingsWriter: public SettingsWriter {

		public:
			INJECT(SimpleSettingsWriter());
			virtual ~SimpleSettingsWriter();

			virtual bool write(std::map<std::string, std::map<std::string, std::string>>* settings, std::string path)
			        override;
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSWRITER_SIMPLESETTINGSWRITER_H_ */
