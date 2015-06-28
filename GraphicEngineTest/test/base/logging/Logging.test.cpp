/*
 * hello.test.cpp
 *
 *  Created on: 24.06.2015
 *      Author: axp
 */

#define BOOST_TEST_DYN_LINK

#include <boost/test/auto_unit_test.hpp>

#include "logging/Logging.h"

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE(Logging_Tests)

	BOOST_AUTO_TEST_CASE(shouldWriteIDAndMessageToConsole) {
		// Given
		Logging::LogLevel = Logging::LEVEL::TRACE;
		std::stringstream buffer;
		std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
		const std::string TEST_ID = "id";
		const std::string TEST_MESSAGE = "message";

		// When
		Logging::trace(TEST_ID, TEST_MESSAGE);
		std::string traceOutput = buffer.str();

		Logging::info(TEST_ID, TEST_MESSAGE);
		std::string infoOutput = buffer.str();

		Logging::debug(TEST_ID, TEST_MESSAGE);
		std::string debugOutput = buffer.str();

		Logging::warn(TEST_ID, TEST_MESSAGE);
		std::string warnOutput = buffer.str();

		Logging::error(TEST_ID, TEST_MESSAGE);
		std::string errorOutput = buffer.str();

		Logging::fatal(TEST_ID, TEST_MESSAGE);
		std::string fatalOutput = buffer.str();

		// Reset the stream before the checks to get valid results.
		std::cout.rdbuf(old);

		// Then
		BOOST_CHECK(traceOutput.find(TEST_ID) != std::string::npos);
		BOOST_CHECK(traceOutput.find(TEST_MESSAGE) != std::string::npos);

		BOOST_CHECK(infoOutput.find(TEST_ID) != std::string::npos);
		BOOST_CHECK(infoOutput.find(TEST_MESSAGE) != std::string::npos);

		BOOST_CHECK(debugOutput.find(TEST_ID) != std::string::npos);
		BOOST_CHECK(debugOutput.find(TEST_MESSAGE) != std::string::npos);

		BOOST_CHECK(warnOutput.find(TEST_ID) != std::string::npos);
		BOOST_CHECK(warnOutput.find(TEST_MESSAGE) != std::string::npos);

		BOOST_CHECK(errorOutput.find(TEST_ID) != std::string::npos);
		BOOST_CHECK(errorOutput.find(TEST_MESSAGE) != std::string::npos);

		BOOST_CHECK(fatalOutput.find(TEST_ID) != std::string::npos);
		BOOST_CHECK(fatalOutput.find(TEST_MESSAGE) != std::string::npos);
	}

	BOOST_AUTO_TEST_SUITE_END()

//____________________________________________________________________________//
