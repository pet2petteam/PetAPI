#include "DataStruct/Message.h"
#include "DataStruct/DateTime.h"

namespace PetAPI {

//------- File Struct -------//

File::File() {
	fileSize = 0;
	fileName = "";
	fileData.clear();
}

ByteBuffer File::toByteBuffer() {
	ByteBuffer buffer;
	
	buffer.appendVariable<uint64_t>(fileName.size());
	buffer.append(fileName);
	
	buffer.appendVariable<uint64_t>(fileData.size());
	buffer.append(fileData);
	
	return buffer;
}

//------- Message Class -------//

Message::Message() {
	m_text = "";
	m_files.clear();
}

Message::Message(const ByteBuffer & bytesData) {
	uint64_t tLength = 0;
	uint64_t fNumber = 0;
	
	bytesData.parseVariable<uint64_t>(0, tLength);
	bytesData.parseVariable<uint64_t>(8, fNumber);
	
	bytesData.slice(m_text, 16, tLength);
	
	uint64_t offset = tLength + 16;
	uint64_t fSize = 0;
	for (uint64_t i = 0; i < fNumber; ++i) {
		File file;
		bytesData.parseVariable<uint64_t>(offset += 8, fSize);
		bytesData.slice(file.fileName, offset, offset + fSize);
		offset += fSize;
		bytesData.parseVariable<uint64_t>(offset += 8, fSize);
		bytesData.slice(file.fileData, offset, offset + fSize);
		m_files.push_back(file);
	}
	
}

Message Message::fromByteBuffer(const ByteBuffer & data) { return Message(data); }

ByteBuffer Message::toByteBuffer() {
	ByteBuffer messByteBuffer;
	
	messByteBuffer.appendVariable<uint64_t>(m_text.size());
	messByteBuffer.appendVariable<uint64_t>(m_files.size());
	messByteBuffer.append(m_text);
	
	for (size_t i = 0; i < m_files.size(); ++i)
		messByteBuffer.append(m_files.at(i).toByteBuffer());
	
	return messByteBuffer;
}

bool Message::hasText() const { return m_text.size() != 0; }

bool Message::hasFile() const { return m_files.size() != 0; }

size_t Message::getTextlength() const { return m_text.size(); }

size_t Message::getNumFiles() const { return m_files.size(); }

void Message::setText(const std::string & text) {
	if (text.empty()) return;
	m_text = text;
}

const std::string & Message::getText() const { return m_text; }

void Message::appendFile(const std::string & fileName, const ByteBuffer & fileData) {
	if (fileName.empty()) return;
	if (fileData.empty()) return;
	
	File f;
	f.fileSize = fileName.size();
	f.fileName = fileName;
	f.fileData = fileData;
	
	m_files.push_back(f);
}

const std::vector<File> & Message::getFiles() const { return m_files; }

const File & Message::getFile(size_t i) const { return m_files.at(i); }

}
