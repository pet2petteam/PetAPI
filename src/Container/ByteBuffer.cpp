#include "Container/ByteBuffer.h"

namespace PetAPI {

ByteBuffer::ByteBuffer() { m_data.clear(); }

ByteBuffer::ByteBuffer(const std::string & string) { append(string); }

ByteBuffer::ByteBuffer(const ByteBuffer & buffer) { append(buffer); }

size_t ByteBuffer::size() const { return m_data.size(); }

bool ByteBuffer::empty() const { return m_data.empty(); }

byte ByteBuffer::at(size_t i) const {
	if (i >= m_data.size()) return *(m_data.end());
	return m_data.at(i);
}

void ByteBuffer::clear() { m_data.clear(); }

void ByteBuffer::append(const byte & b) { m_data.push_back(b); }

#if __cplusplus >= 201103L
void ByteBuffer::append(byte && b) { m_data.push_back(b); }
#endif

bool ByteBuffer::append(const ByteBuffer & buffer) {
	if (buffer.empty()) return false;
	
	for (size_t i = 0; i < buffer.size(); ++i)
		m_data.push_back(buffer.m_data.at(i));
	return true;
}

bool ByteBuffer::append(const std::string & string) {
	if (string.empty()) return false;
	
	for (size_t i = 0; i < string.size(); ++i)
		m_data.push_back(string.at(i));
	return true;
}

bool ByteBuffer::slice(ByteBuffer & dest, size_t from, size_t to) const {
	if (m_data.empty()) return false;
	if (from == to) return false;
	if (from > to) std::swap(from, to);
	if (to > m_data.size()) to = m_data.size();
	
	while (from < to) {
		dest.append(m_data.at(from));
		++from;
	}
	return true;
}

bool ByteBuffer::slice(std::string & dest, size_t from, size_t to) const {
	if (m_data.empty()) return false;
	if (from == to) return false;
	if (from > to) std::swap(from, to);
	if (to > m_data.size()) to = m_data.size();
	
	while (from < to) {
		dest.push_back(m_data.at(from));
		++from;
	}
	return true;
}

ByteBuffer & ByteBuffer::operator+(const std::string & string) {
	if (string.empty()) return *this;
	append(string);
	return *this;
}

ByteBuffer & ByteBuffer::operator+(const ByteBuffer & buffer) {
	if (&buffer == this) return *this;
	if (buffer.empty()) return *this;
	append(buffer);
	return *this;
}

ByteBuffer & ByteBuffer::operator+=(const std::string & string) {
	if (string.empty()) return *this;
	append(string);
	return *this;
}

ByteBuffer & ByteBuffer::operator+=(const ByteBuffer & buffer) {
	if (&buffer == this) return *this;
	if (buffer.empty()) return *this;
	append(buffer);
	return *this;
}

ByteBuffer & ByteBuffer::operator=(const std::string & string) {
	m_data.clear();
	append(string);
	return *this;
}

ByteBuffer & ByteBuffer::operator=(const ByteBuffer & buffer) {
	if(&buffer == this) return *this;
	m_data.clear();
	append(buffer);
	return *this;
}

bool ByteBuffer::operator==(const std::string & string) const {
	return std::equal(m_data.begin(), m_data.end(), string.begin());
}

bool ByteBuffer::operator==(const ByteBuffer & buffer) const {
	return std::equal(m_data.begin(), m_data.end(), buffer.m_data.begin());
}

bool ByteBuffer::operator!=(const std::string & string) const {
	return !std::equal(m_data.begin(), m_data.end(), string.begin());
}

bool ByteBuffer::operator!=(const ByteBuffer & buffer) const {
	return !std::equal(m_data.begin(), m_data.end(), buffer.m_data.begin());
}

}
