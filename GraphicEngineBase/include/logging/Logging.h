/*
 * Logging.h
 *
 *  Created on: 10.05.2015
 *      Author: axp
 */

#ifndef LOGGING_LOGGING_H_
#define LOGGING_LOGGING_H_

#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime>

namespace Logging {

	enum LEVEL {
		TRACE, INFO, DEBUG, WARN, ERROR, FATAL
	};
	extern LEVEL LogLevel;

	template<typename T>
	void _log(T t) {
		std::cout << t << std::endl;
	}

	template<typename T, typename ... Args>
	void _log(T t, Args ... args) {
		std::cout << t << " ";
		_log(args...);
	}

	using std::string;

	inline string _getHeader(string level, string id) {
		auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		auto timeStr = string(std::ctime(&time));
		timeStr.erase(std::remove(timeStr.begin(), timeStr.end(), '\n'), timeStr.end());
		return "[" + level + "] " + timeStr + " - " + id + " -- ";
	}

	template<typename ... Args>
	static void trace(string id, Args ... args) {
		if (LogLevel > TRACE) return;
		std::cout << _getHeader("TRACE", id);
		_log(args...);
	}

	template<typename ... Args>
	static void info(string id, Args ... args) {
		if (LogLevel > INFO) return;
		std::cout << _getHeader("INFO ", id);
		_log(args...);
	}

	template<typename ... Args>
	static void debug(string id, Args ... args) {
		if (LogLevel > DEBUG) return;
		std::cout << _getHeader("DEBUG", id);
		_log(args...);
	}

	template<typename ... Args>
	static void warn(string id, Args ... args) {
		if (LogLevel > WARN) return;
		std::cout << _getHeader("WARN ", id);
		_log(args...);
	}

	template<typename ... Args>
	static void error(string id, Args ... args) {
		if (LogLevel > ERROR) return;
		std::cout << _getHeader("ERROR", id);
		_log(args...);
	}

	template<typename ... Args>
	static void fatal(string id, Args ... args) {
		if (LogLevel > FATAL) return;
		std::cout << _getHeader("FATAL", id);
		_log(args...);
	}
}

#endif /* LOGGING_LOGGING_H_ */
