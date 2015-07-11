/*
 * SimpleSettingsLoader.h
 *
 *  Created on: 11.06.2015
 *      Author: axp
 */

#ifndef FRAMEWORK_COMMON_SETTINGSLOADER_SIMPLESETTINGSLOADER_H_
#define FRAMEWORK_COMMON_SETTINGSLOADER_SIMPLESETTINGSLOADER_H_

#include <framework/common/settingsLoader/SettingsLoader.h>
#include <fruit/fruit.h>

namespace NSSettings {

	class SimpleSettingsLoader: public SettingsLoader {

		public:
			INJECT(SimpleSettingsLoader());
			virtual ~SimpleSettingsLoader();

			virtual void load(settingsMap& settingsData, std::string file) override;
			virtual bool wasLoadingSuccessful() override;

		private:
			const std::string COMMENT = "#";
			const std::string CATEGORY_START = "[";
			const std::string CATEGORY_END = "]";
			const std::string ENTRY_DIVIDER = "=";

			bool loadSuccess;

			virtual bool isFileValid(std::string file);
			virtual void parseFile(settingsMap& settingsData, std::string file);
			virtual void parseLineInto(std::string& line, std::string& category, std::string& key, std::string& value);
			virtual void setSettingToMap(settingsMap& settingsData, std::string& category, std::string& key, std::string& value);
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSLOADER_SIMPLESETTINGSLOADER_H_ */
