#ifndef HUFMAN
#define HUFMAN

#include <string>
#include <sstream>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
#include "bool_array.h"
#include <fstream>

using namespace std;

class Huffman
{
	struct CharFreqSet
	{
		std::string char_set;
		int freq;
		bool operator<(const CharFreqSet& o) const;
	};

public:
	static std::map<char, std::string> encode(const std::string& text);

	static void read_dict(ifstream& dict_is, int dict_size, map<string, char>& dict);

	static string decode(ifstream& dict_is, ifstream& text_is);
};

#endif
