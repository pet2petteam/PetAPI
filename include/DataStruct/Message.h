#ifndef MESSAGE_H
#define MESSAGE_H

#include "PetAPI_global.h"
#include "Container/ByteBuffer.h"

namespace PetAPI {

struct File {
	size_t fileSize;
	std::string fileName;
	ByteBuffer fileData;
	
	File();
	~File() = default;
	
	ByteBuffer toByteBuffer();
};

class PETAPI Message {
	
	std::string m_text;
	std::vector<File> m_files;
	
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
	
	void setText(const std::string & mess);
	const std::string & getText() const;
	
	void appendFile(const std::string & fileName, const ByteBuffer & fileData);
	const std::vector<File> & getFiles() const;
	const File & getFile(size_t i) const;
	
};

}

#endif // MESSAGE_H
