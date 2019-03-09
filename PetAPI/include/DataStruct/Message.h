#ifndef MESSAGE_H
#define MESSAGE_H

#include "PetAPI_global.h"
#include "DataStruct/DateTime.h"
#include "Container/ByteBuffer.h"

namespace PetAPI {

struct File {
	size_t fileSize;
	std::string fileName;
	ByteBuffer fileData;
	
	File();
	~File() = default;
	
	static File fromByteBuffer(const ByteBuffer & buffer, size_t & from);
	ByteBuffer toByteBuffer();
	
	void clear();
	
	File & operator=(const File & file);
	bool operator==(const File & file);
	bool operator!=(const File & file);
};

class PETAPI Message {
	
	std::string m_text;
	std::vector<File> m_files;
	
	Date m_date;
	Time m_time;
	
public:
	
	Message();
	Message(const ByteBuffer & bytesData);
	~Message() = default;
	
	static Message fromByteBuffer(const ByteBuffer & data);
	ByteBuffer toByteBuffer();
	
	bool hasText() const;
	bool hasFile() const;
	
	size_t getTextlength() const;
	size_t getNumFiles() const;
	
	const Date & getDate();
	const Time & getTime();
	
	void setText(const std::string & mess);
	const std::string & getText() const;
	
	void appendFile(const std::string & fileName, const ByteBuffer & fileData);
	const std::vector<File> & getFiles() const;
	const File & getFile(size_t i) const;
	
	void clear();
	
};

}

#endif // MESSAGE_H
