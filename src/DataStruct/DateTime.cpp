#include "DataStruct/DateTime.h"

namespace PetAPI {

/*------------Date------------*/

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Date::Date(const Date & date) {
	year = date.year;
	month = date.month;
	day = date.day;
}

Date Date::currentDate() {
	Date ret;
#ifdef _WIN32
	SYSTEMTIME date;
	GetLocalTime(&date);
	ret.year = date.wYear;
	ret.month = date.wMonth;
	ret.day = date.wDay;
#else
	//TODO: get current date for linux
#endif
	return ret;
}

std::string Date::toString(DateFormat format, DTSeparator separator) {
	if (separator == DTSeparator::COLON) return "";
	switch (format) {
	case DateFormat::YYYYMMDD:
		return std::to_string(year) + static_cast<char>(separator) +
		        (month < 10 ? '0' + std::to_string(month) : std::to_string(month)) +
		        static_cast<char>(separator) +
		        (day < 10 ? '0' + std::to_string(day) : std::to_string(day));
	case DateFormat::YYYYDDMM:
		return std::to_string(year) + static_cast<char>(separator) +
		        (day < 10 ? '0' + std::to_string(day) : std::to_string(day)) +
		        static_cast<char>(separator) +
		        (month < 10 ? '0' + std::to_string(month) : std::to_string(month));
	case DateFormat::DDMMYYYY:
		return (day < 10 ? '0' + std::to_string(day) : std::to_string(day)) +
		        static_cast<char>(separator) +
		        (month < 10 ? '0' + std::to_string(month) : std::to_string(month)) +
		        static_cast<char>(separator) +
		        std::to_string(year);
	case DateFormat::DMYYYY:
		return std::to_string(day) + static_cast<char>(separator) +
		        std::to_string(month) + static_cast<char>(separator) +
		        std::to_string(year);
	case DateFormat::MDYYYY:
		return std::to_string(month) + static_cast<char>(separator) +
		        std::to_string(day) + static_cast<char>(separator) +
		        std::to_string(year);
	case DateFormat::YYYYMD:
		return std::to_string(year) + static_cast<char>(separator) +
		        std::to_string(month) + static_cast<char>(separator) +
		        std::to_string(day);
	}
}

/*------------Time------------*/

Time::Time(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

Time::Time(const Time & time) {
	hour = time.hour;
	minute = time.minute;
	second = time.second;
}

Time Time::currentTime() {
	Time ret;
#ifdef _WIN32
	SYSTEMTIME time;
	GetLocalTime(&time);
	ret.hour = time.wHour;
	ret.minute = time.wMinute;
	ret.second = time.wSecond;
#else
	//TODO: get current time for linux
#endif
	return ret;
}

std::string Time::toString(TimeFormat format) {
	switch (format) {
	case TimeFormat::Russia:
		return (hour < 10 ? "0" : "") + std::to_string(hour) + static_cast<char>(DTSeparator::COLON) +
		        (minute < 10 ? "0" : "") + std::to_string(minute) + static_cast<char>(DTSeparator::COLON) +
		        (second < 10 ? "0" : "") + std::to_string(second);
	case TimeFormat::USA: break;
		return (hour < 10 ? "0" : "") + std::to_string(hour > 12 ? hour - 12 : hour) + static_cast<char>(DTSeparator::COLON) +
		        (minute < 10 ? "0" : "") + std::to_string(minute) + static_cast<char>(DTSeparator::COLON) +
		        (second < 10 ? "0" : "") + std::to_string(second) + (hour > 12 ? " pm" : " am");
	}
}

}
