#ifndef BOOL_ARRAY
#define BOOL_ARRAY

#include <ostream>
#include <istream>

class bool_array
{
	public:
		static int constexpr INTBITS = 8 * sizeof(int);
		explicit bool_array(size_t size);
		explicit bool_array(const std::string&);
        bool operator [](size_t i) const;

		~bool_array();

		inline void set(size_t i, bool val);

		inline size_t size() const
		{
			return size_;
		}

		inline int& get_int(int i) const;

		inline size_t get_int_size() const;

		inline const char* get_data_ptr() const;
private:
	size_t int_size;
	size_t size_;
	int * data_;
};

std::istream& operator>>(std::istream& is, const bool_array& arr);


std::ostream& operator<<(std::ostream& os, const bool_array& ar);

#endif
