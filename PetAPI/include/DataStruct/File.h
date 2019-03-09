#ifndef FILE_H
#define FILE_H

#include <PetAPI_global.h>
#include <Container/ByteBuffer.h>

namespace PetAPI {

struct PETAPI File {
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

}

#endif // FILE_H
