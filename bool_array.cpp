#include "bool_array.h"
#include <cassert>

bool_array::bool_array(size_t size): int_size(size / INTBITS + 1), size_(size), data_(new int[int_size])
{
}

bool_array::bool_array(const std::string& str) : bool_array(str.size())
{	
	for (auto i = 0; i < str.size(); ++i)
		this->set(i, str[i] == '1');
}

bool bool_array::operator[](size_t i) const
{
	return data_[i / INTBITS] & (1 << (i % INTBITS));
}

bool_array::~bool_array()
{
	delete[] data_;
}

inline void bool_array::set(size_t i, bool val)
{
	data_[i / INTBITS] = val ? data_[i / INTBITS] | (1 << (i % INTBITS)) : data_[i / INTBITS] & ~(1 << (i % INTBITS));
}


inline int& bool_array::get_int(int i) const
{
	assert(i >= 0 && i < int_size);
	return data_[i];
}

inline size_t bool_array::get_int_size() const
{
	return int_size;
}

inline const char* bool_array::get_data_ptr() const
{
	return reinterpret_cast<const char *>(data_);
}

std::istream& operator>>(std::istream& is, const bool_array& arr)
{
	char buf[sizeof(int)];
	for (size_t i = 0; i < arr.get_int_size(); ++i)
	{
		is.read(buf, sizeof(int)); // !!!read & get некорректно работают с некоторыми спецсимволами!!!!!
		auto i1 = (reinterpret_cast<int*>(buf))[0];
		arr.get_int(i) = i1;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const bool_array& ar)
{
	auto ptr = ar.get_data_ptr();
	auto size = ar.size();
	for (size_t i = 0; i < ar.get_int_size() * sizeof(int); ++i)
		os << ptr[i];
	return os;
}
