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

			virtual void write(settingsMap& settingsData, std::string filepath) override;
			virtual bool wasWritingSuccessful() override;

		private:
			const std::string CATEGORY_START = "[";
			const std::string CATEGORY_END = "]";
			const std::string ENTRY_DIVIDER = "=";

			bool wasLastWriteSuccessful;

			inline bool isFileOperationPossible(std::string& filepath);
			std::string createSettingsString(settingsMap& settingsData);
			inline std::string createCategoryEntry(std::string category);
			inline std::string createDataEntry(std::string key, std::string value);
			inline void writeSettingsToFile(std::string& filepath, std::string& settingsAsString);
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSWRITER_SIMPLESETTINGSWRITER_H_ */
