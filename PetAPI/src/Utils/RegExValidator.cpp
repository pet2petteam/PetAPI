#include "Utils/RegExValidator.h"

#include <regex>

namespace PetAPI::Utils {

RegExValidator::RegExValidator(const std::string & data,
                               const std::string & pattern) : m_data(data), m_patern(pattern) {}

void RegExValidator::setData(const std::string & data) { m_data = data; }

void RegExValidator::setPattern(const std::string & pattern) { m_patern = pattern; }

bool RegExValidator::isDataValid() const {
	if (m_patern.empty()) return false;
	if (m_data.empty()) return false;
	
	std::regex regex(m_patern);
	return std::regex_match(m_data, regex);
}

bool RegExValidator::isDataValid(const std::string & data,
                                 const std::string & pattern) {
	RegExValidator validator(data,pattern);
	return validator.isDataValid();
}

}
