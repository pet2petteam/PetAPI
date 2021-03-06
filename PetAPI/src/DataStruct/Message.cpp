#include "DataStruct/Message.h"
#include "DataStruct/DateTime.h"

namespace PetAPI {

Message::Message() {
	m_text = "";
	m_files.clear();
	
	m_date = Date::currentDate();
	m_time = Time::currentTime();
}

Message::Message(const ByteBuffer & bytesData) {
	uint64_t tLength = 0;
	uint64_t fNumber = 0;
	
	m_date = Date::fromByteBuffer(bytesData, 0);
	m_time=  Time::fromByteBuffer(bytesData, 12);
	
	bytesData.parseVariable<uint64_t>(24, tLength);
	bytesData.parseVariable<uint64_t>(32, fNumber);
	
	bytesData.slice(m_text, 40, tLength+=40);
	
	for (uint64_t i = 0; i < fNumber; ++i) {
		const File & file = File::fromByteBuffer(bytesData, tLength);
		m_files.push_back(file);
	}
}

Message Message::fromByteBuffer(const ByteBuffer & data) { return Message(data); }

ByteBuffer Message::toByteBuffer() {
	ByteBuffer messByteBuffer;
	
	Date::currentDate().toByteBuffer(messByteBuffer);
	Time::currentTime().toByteBuffer(messByteBuffer);
	
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

const Date & Message::getDate() { return m_date; }

const Time & Message::getTime() { return m_time; }

void Message::setText(const std::string & text) {
	if (text.empty()) return;
	m_text = text;
}

const std::string & Message::getText() const { return m_text; }

void Message::appendFile(const std::string & fileName, const ByteBuffer & fileData) {
	if (fileName.empty()) return;
	if (fileData.empty()) return;
	
	File f;
	f.fileName = fileName;
	f.fileData = fileData;
	f.fileSize = fileData.size();
	
	m_files.push_back(f);
}

const std::vector<File> & Message::getFiles() const { return m_files; }

const File & Message::getFile(size_t i) const { return m_files.at(i); }

void Message::clear() {
	m_text.clear();
	for (File & f : m_files)
		f.clear();
	m_files.clear();
}

}
