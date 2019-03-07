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

enum class TimeFormat : short {
	//TODO: make TimeFormat like DateFormat
	Russia = 0,
	USA = 1
};

enum class DTSeparator : char {
	DOT = '.',
	HYPHEN = '-',
	SLASH = '/',
	COLON = ':'
};

struct Date {
	
	int year;
	int month;
	int day;
	
	Date(int y = 0, int m = 0, int d = 0);
	Date(const Date & date);
	~Date() = default;
	
	static Date currentDate();
	std::string toString(DateFormat format, DTSeparator separator = DTSeparator::DOT);
	
};

struct Time {
	
	int hour;
	int minute;
	int second;
	
	Time(int h = 0, int m = 0, int s = 0);
	Time(const Time & time);
	~Time() = default;
	
	static Time currentTime();
	std::string toString(TimeFormat format);
	
};

//TODO: write time struct

}

#endif // DATETIME_H
