#ifndef DATETIME_H
#define DATETIME_H

#include <string>

#ifdef _WIN32
	#include <windows.h>
#else
#endif

namespace PetAPI {

enum class DateFormat : short {
	YYYYMMDD = 0,
	YYYYDDMM = 1,
	DDMMYYYY = 2,
	DMYYYY = 3,
	MDYYYY = 4,
	YYYYMD = 5
};

enum class DTSeparator : char {
	DOT = '.',
	HYPHEN = '-',
	SLASH = '/'
};

struct Date {
	
	int year;
	int month;
	int day;
	
public:
	
	Date(int y = 0, int m = 0, int d = 0);
	Date(const Date & date);
	~Date() = default;
	
	static Date currentDate();
	std::string toString(DateFormat format, DTSeparator separator = DTSeparator::DOT);
	
};

//TODO: write time struct

}

#endif // DATETIME_H
