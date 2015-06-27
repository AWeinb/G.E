/*
 * Util.h
 *
 *  Created on: 11.05.2015
 *      Author: axp
 */

#ifndef UTIL_STRINGUTIL_H_
#define UTIL_STRINGUTIL_H_

#include <string>
#include <sstream>
#include <algorithm>

namespace Util {

	using std::string;

	template<class T>
	static inline string toString(T object) {
		std::stringstream sstream;
		sstream << object;
		return sstream.str();
	}

	static inline string* ltrim(string* input) {
		auto begin = input->begin();
		auto end = input->end();
		auto isNoSpaceFunc = std::not1(std::ptr_fun<int, int>(std::isspace));
		input->erase(begin, std::find_if(begin, end, isNoSpaceFunc));
		return input;
	}

	static inline string* rtrim(string* input) {
		auto rightBegin = input->rbegin();
		auto rightEnd = input->rend();
		auto isNoSpace = std::not1(std::ptr_fun<int, int>(std::isspace));
		input->erase(std::find_if(rightBegin, rightEnd, isNoSpace).base(), input->end());
		return input;
	}

	static inline string trim(string s) {
		return *ltrim(rtrim(&s));
	}

	static inline string* trim(string* s) {
		return ltrim(rtrim(s));
	}

	static inline bool isEmptyString(string str) {
		return trim(&str)->empty();
	}

	static inline bool isNullOrEmptyString(string* str) {
		return !str || (trim(str)->empty());
	}

	template<typename Container>
	Container& split(Container& resultContainer, string input, string delimiter) {
		resultContainer.clear();
		size_t currentIdx = 0;
		size_t nextIdx = -1;
		do {
			currentIdx = nextIdx + 1;
			nextIdx = input.find_first_of(delimiter, currentIdx);
			resultContainer.push_back(input.substr(currentIdx, nextIdx - currentIdx));
		} while (nextIdx != Container::value_type::npos);

		return resultContainer;
	}
}

#endif /* UTIL_STRINGUTIL_H_ */
