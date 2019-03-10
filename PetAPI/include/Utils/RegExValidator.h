#ifndef REGEXVALIDATOR_H
#define REGEXVALIDATOR_H

#include "PetAPI_global.h"

namespace PetAPI::Utils {

const std::string LOGIN_DEF_VALIDATION_PATTERN = "^[a-zA-Z0-9]([._](?![._])|[a-zA-Z0-9]){6,18}[a-zA-Z0-9]$";
const std::string PASSWORD_DEF_VALIDATION_PATTERN = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,10}$";
const std::string EMAIL_DEF_VALIDATION_PATTERN = "^([a-zA-Z0-9_\\-\\.]+)@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.)|(([a-zA-Z0-9\\-]+\\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\\]?)$";

class PETAPI RegExValidator {
	
	std::string m_data;
	std::string m_patern;
	
public:
	
	RegExValidator(const std::string & data,
	               const std::string & pattern);
	virtual ~RegExValidator() = default;
	
	void setData(const std::string & data);
	void setPattern(const std::string & pattern);
	
	bool isDataValid() const;
	static bool isDataValid(const std::string & data,
	                        const std::string & pattern);
	
};

}

#endif // REGEXVALIDATOR_H
