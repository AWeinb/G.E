/*
 * hello.test.cpp
 *
 *  Created on: 24.06.2015
 *      Author: axp
 */

#define BOOST_TEST_DYN_LINK
#include <boost/test/auto_unit_test.hpp>
#include <string>

#include "util/StringUtil.h"

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE(Util_Tests)

	BOOST_AUTO_TEST_CASE(shouldReturnStringForCommonTypes) {
		// Given some common data types ...
		const int SOME_INT = 2;
		const float SOME_FLOAT = 2.0f;
		const std::string SOME_STRING = "string";

		// When
		const std::string SOME_INT_STRING = Util::toString(SOME_INT);
		const std::string SOME_FLOAT_STRING = Util::toString(SOME_FLOAT);
		const std::string SOME_STRING_STRING = Util::toString(SOME_STRING);

		// Then
		BOOST_CHECK_EQUAL(std::stoi(SOME_INT_STRING), 2);
		BOOST_CHECK(std::stof(SOME_INT_STRING) - SOME_FLOAT < 0.01);
		BOOST_CHECK_EQUAL(SOME_STRING_STRING, SOME_STRING);
	}

	BOOST_AUTO_TEST_CASE(shouldTrimSpaces) {
		// Given
		std::string someString = "string   ";
		std::string someOtherString = "   string";

		// When
		std::string trimmedString = Util::trim(someString);
		Util::trim(&someOtherString);

		// Then
		const std::string RESULT_STRING = "string";
		BOOST_CHECK_EQUAL(trimmedString, RESULT_STRING);
		BOOST_CHECK_EQUAL(someOtherString, RESULT_STRING);
	}

	BOOST_AUTO_TEST_CASE(shouldTellIfStringHasOnlySpaces) {
		// Given
		std::string someString = "";
		std::string someOtherString = "   ";

		// When
		bool testOne = Util::isEmptyString(someString);
		bool testTwo = Util::isEmptyString(someOtherString);

		// Then
		BOOST_CHECK(testOne);
		BOOST_CHECK(testTwo);
	}

	BOOST_AUTO_TEST_CASE(shouldTellIfStringHasOnlySpacesOrIsNull) {
		// Given
		std::string someString = "";
		std::string* someOtherString = nullptr;

		// When
		bool testOne = Util::isNullOrEmptyString(&someString);
		bool testTwo = Util::isNullOrEmptyString(someOtherString);

		// Then
		BOOST_CHECK(testOne);
		BOOST_CHECK(testTwo);
	}

	BOOST_AUTO_TEST_CASE(shouldSplitStringOnOtherString) {
		// Given
		std::string someStringWithSpaces = "A B C";

		// When
		std::vector<std::string> fields;
		Util::split(fields, someStringWithSpaces, " ");

		// Then
		BOOST_CHECK_EQUAL(fields[0], "A");
		BOOST_CHECK_EQUAL(fields[1], "B");
		BOOST_CHECK_EQUAL(fields[2], "C");
	}

	BOOST_AUTO_TEST_SUITE_END()

//____________________________________________________________________________//
