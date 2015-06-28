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

			virtual void load(Settings* settings, std::string file) override;
			virtual bool wasLoadingSuccessful() override;

		private:
			const std::string COMMENT_STR = "#";
			const std::string CATEGORY_STR = "=";
			const std::string EQUALS_STR = "=";

			bool loadSuccess;
	};

} /* namespace NSSettings */

#endif /* FRAMEWORK_COMMON_SETTINGSLOADER_SIMPLESETTINGSLOADER_H_ */
