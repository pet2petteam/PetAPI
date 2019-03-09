#include "DataStruct/File.h"

namespace PetAPI {

File::File() {
	fileSize = 0;
	fileName = "";
	fileData.clear();
}

File File::fromByteBuffer(const ByteBuffer & buffer, size_t & from) {
	File file;
	
	uint64_t fSize;
	buffer.parseVariable<uint64_t>(from, fSize);
	from += sizeof(uint64_t);
	
	buffer.slice(file.fileName, from, from + fSize);
	from += fSize;
	
	buffer.parseVariable<uint64_t>(from, file.fileSize);
	from += sizeof(uint64_t);
	
	buffer.slice(file.fileData, from, from + file.fileSize);
	from += file.fileSize;
	
	return file;
}

ByteBuffer File::toByteBuffer() {
	ByteBuffer buffer;
	
	buffer.appendVariable<uint64_t>(fileName.size());
	buffer.append(fileName);
	
	buffer.appendVariable<uint64_t>(fileData.size());
	buffer.append(fileData);
	
	return buffer;
}

void File::clear() {
	fileSize = 0;
	fileName.clear();
	fileData.clear();
}

File & File::operator=(const File & file) {
	fileName.clear();
	fileData.clear();
	fileSize = file.fileSize;
	fileName = file.fileName;
	fileData = file.fileData;
	return *this;
}

bool File::operator==(const File & file) {
	if (file.fileSize != fileSize) return false;
	if (file.fileName != fileName) return false;
	if (file.fileData != fileData) return false;
	return true;
}

bool File::operator!=(const File & file) {
	if (file.fileSize != fileSize) return true;
	if (file.fileName != fileName) return true;
	if (file.fileData != fileData) return true;
	return false;
}

}
