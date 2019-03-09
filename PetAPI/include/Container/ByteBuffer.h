#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include "PetAPI_global.h"

namespace PetAPI {

using byte = int8_t;

class PETAPI ByteBuffer {
	
	std::vector<byte> m_data;
	
public:
	
	ByteBuffer();
	explicit ByteBuffer(const std::string & data);
	ByteBuffer(const ByteBuffer & data);
	~ByteBuffer() = default;
	
	size_t size() const;
	
	bool empty() const;
	
	byte at(size_t pos) const;
	
	void clear();
	
	void append(const byte & b);
#if __cplusplus >= 201103L
	void append(byte && b);
#endif
	bool append(const ByteBuffer & data);
	bool append(const std::string & data);
	
	bool slice(ByteBuffer & dest, size_t from, size_t to) const;
	bool slice(std::string & dest, size_t from, size_t to) const;
	
	template <typename type>
	void appendVariable(type var) {
		constexpr size_t size = sizeof(type);
		size_t count = size;
		int mask = 0xFF;
		int offset = 0;
		byte tmp[size];
		while(count--) {
			tmp[count] = (var >> offset) & mask;
			offset += 8;
		}
		for (int i = 0; i < size; i++)
			m_data.push_back(tmp[i]);
	}
	
	template <typename type>
	bool parseVariable(size_t fromPos, type & outResult) const {
		constexpr size_t sizeT = sizeof(type);
		const size_t size = (fromPos + sizeT <= m_data.size()) ? (fromPos >= m_data.size()) ? 0 : sizeT : 0;
		outResult = 0;
		for (size_t i = 0; i < size; ++i) {
			outResult = outResult << 8;
			outResult |= static_cast<uint8_t>(m_data[fromPos + i]);
		}
		return (size == sizeT);
	}
	
	ByteBuffer & operator+(const std::string & string);
	ByteBuffer & operator+(const ByteBuffer & buffer);
	
	ByteBuffer & operator+=(const std::string & string);
	ByteBuffer & operator+=(const ByteBuffer & buffer);
	
	ByteBuffer & operator=(const std::string & string);
	ByteBuffer & operator=(const ByteBuffer & buffer);
	
	bool operator==(const std::string & string) const;
	bool operator==(const ByteBuffer & buffer) const;
	
	bool operator!=(const std::string & string) const;
	bool operator!=(const ByteBuffer & buffer) const;
	
};

}

#endif // BYTEBUFFER_H
