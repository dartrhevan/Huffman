#include "bool_array.h"

bool_array::bool_array(size_t size)
        :  int_size(size / INTBITS + 1), size_(size), data_(new int[int_size])
    {}

bool bool_array::operator [](size_t i) const
{
    return data_[i / INTBITS] & (1 << (i % INTBITS));
}

bool_array::~bool_array()
{
    delete[] data_;
}

void bool_array::set(size_t i, bool val)
{
    data_[i / INTBITS] = val ? data_[i / INTBITS] | (1 << (i % INTBITS)) :
    data_[i / INTBITS] & ~(1 << (i % INTBITS));
}

int& bool_array::get_int(int i) const
{
    //std::assert(i >= 0 && i < int_size);
    return data_[i];
}

std::ostream& operator<<(std::ostream& os, const bool_array& ar)
{
    auto ptr = ar.get_data_ptr();
    auto size = ar.size();
    os << size << " ";
    for (size_t i = 0; i < ar.get_int_size() * sizeof(int); ++i)
        os << ptr[i];
    return os;
}

std::istream& operator>> (std::istream& is, const bool_array& arr)
{
    char* buf = new char[4];
    for(auto i = 0; i < arr.get_int_size(); ++i)
    {
        //is.read(buf, sizeof(int));// !!!read & get некорректно работают с некоторыми спецсимволами!!!!!
        for(auto j = 0; j < 4; ++j)
            buf[j] = is.get();// !!!read & get некорректно работают с некоторыми спецсимволами!!!!!
        auto i1 = (reinterpret_cast<int*>(buf))[0];
        arr.get_int(i) = i1;
    }
    delete[] buf;
    return is;
}

bool_array::bool_array(const std::string &str)
    :bool_array(str.size())
{
    for (auto i = 0; i < str.size(); ++i)
        set(i, str[i] == '1');
}

bool_array::bool_array(bool_array &&arr)
    :data_(arr.data_), size_(arr.size_)
{
    arr.data_ = nullptr;
    arr.size_ = 0;
}
