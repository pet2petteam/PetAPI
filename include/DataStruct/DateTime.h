#ifndef DATETIME_H
#define DATETIME_H

#include <PetAPI_global.h>

#ifdef _WIN32
	#include <windows.h>
#else
#endif

#include "Container/ByteBuffer.h"

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

struct PETAPI Date {
	
	int year;
	int month;
	int day;
	
	Date(int y = 0, int m = 0, int d = 0);
	Date(const Date & date);
	~Date() = default;
	
	static Date currentDate();
	
	///
	/// \brief fromByteBuffer - Parse date from valid byteBuffer. Read 12 bytes from buffer
	/// \param byteBuffer - ByteBuffer object with date data
	/// \param from - Position to start reading
	/// \return - Date object
	///
	static Date fromByteBuffer(const ByteBuffer & buffer, size_t from = 0);
	
	///
	/// \brief toString - Convert date to string
	/// \param format - Date format. See the DateFormat enum for more
	/// \param separator - Symbol which separate data apart
	/// \return - Date string
	///
	std::string toString(DateFormat format, DTSeparator separator = DTSeparator::DOT);
	
	///
	/// \brief toByteBuffer - Convert date to byteBuffer. Append 12 bytes to buffer
	/// \return - Buffer with date data
	///
	ByteBuffer toByteBuffer();
	
	///
	/// \brief toByteBuffer - Convert date to byteBuffer. Append 12 bytes to buffer
	/// \param buffer - Dest buffer
	/// \return - Written bytes number
	///
	size_t toByteBuffer(ByteBuffer & buffer);
	
};

struct PETAPI Time {
	
	int hour;
	int minute;
	int second;
	
	Time(int h = 0, int m = 0, int s = 0);
	Time(const Time & time);
	~Time() = default;
	
	static Time currentTime();
	
	///
	/// \brief fromByteBuffer - parse time from valid byteBuffer. Read 12 bytes from buffer
	/// \param buffer - ByteBuffer object with time data
	/// \param from - Position to start reading
	/// \return - Time object
	///
	static Time fromByteBuffer(const ByteBuffer & buffer, size_t from = 0);
	
	///
	/// \brief toString - Convert time to string
	/// \param format - Time format. See the TimeFormat for more
	/// \return - time string
	///
	std::string toString(TimeFormat format);
	
	///
	/// \brief toByteBuffer - Convert time to byteBuffer. Append 12 bytes to buffer
	/// \return - Buffer with time data
	///
	ByteBuffer toByteBuffer();
	
	///
	/// \brief toByteBuffer - Convert time to byteBuffer. Append 12 bytes to buffer
	/// \param buffer - Dest buffer
	/// \return - Written bytes number
	///
	size_t toByteBuffer(ByteBuffer & buffer);
	
};

}

#endif // DATETIME_H
