#include "io_func.h"

void io_func::write_dict(ofstream& out_dict, const map<char, string>& code)
{
	out_dict << code.size() << endl;
	for (auto c : code)
		out_dict << c.first << /*' ' << */ c.second << endl;
	out_dict << endl;
}

void io_func::write(const string& file_name, const string& text)
{
	ofstream out_mes(file_name, istream::binary);// , out_dict(dict);

	auto code = Huffman::encode(text);
	string coded_text;
	for (auto c : text)
		coded_text += code[c];
	write_dict(out_mes, code);
	bool_array s(coded_text);
	out_mes << endl << s.size();

	out_mes << s;
	out_mes.close();
	//out_dict.close();
}

//inline string io_func::read(const char* mes, const char* dict)
//{
//	ifstream in_mes(mes, istream::binary), in_dict(dict);
//	return Huffman::decode(in_dict, in_mes);
//}
