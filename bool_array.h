#ifndef BOOL_ARRAY_H
#define BOOL_ARRAY_H

#include <string>
#include <fstream>
#include <cassert>

class bool_array
{
    size_t int_size;
    size_t size_;
    int * data_;
public:
    bool_array(bool_array&& arr);
    static int const INTBITS = 8 * sizeof(int);
    explicit bool_array(size_t size);
    bool_array(const std::string&);
    //bool_array(int * arr, size_t s);
    bool operator [](size_t i) const;
    ~bool_array();
    void set(size_t i, bool val);
    int& get_int(int i) const;
    inline size_t size() const
    {
        return size_;
    }
    inline size_t get_int_size() const
    {
        return int_size;
    }
    inline const char* get_data_ptr() const
    {
        return reinterpret_cast<const char *>(data_);
    }
};

std::istream& operator>> (std::istream& is, const bool_array& arr);
std::ostream& operator<<(std::ostream& os, const bool_array& ar);

#endif // BOOL_ARRAY_H
