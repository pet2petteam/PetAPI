#include "DataStruct/DateTime.h"

namespace PetAPI {

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

}
