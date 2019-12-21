#ifndef IO_FUNC
#define IO_FUNC

#include "Huffman.h"


struct io_func
{

    void static write(const string& file_name, const string& text);

    static string read(const string& file_name)
	{
        ifstream in_mes(file_name, istream::binary);// , in_dict(dict);
		return Huffman::decode(in_mes, in_mes);
    }
private:
    void static write_dict(ofstream& out_dict, const map<char, string>& code);

};

#endif
