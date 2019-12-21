#include "Huffman.h"

bool Huffman::CharFreqSet::operator<(const CharFreqSet& o) const
{
	return tie(freq, char_set) > tie(o.freq, o.char_set);
}

std::map<char, std::string> Huffman::encode(const std::string& text)
{
	std::unordered_map<char, int> frequencies;
	for (auto c : text)
	{
		if (frequencies.find(c) != frequencies.end())
			++frequencies[c];
		else frequencies[c] = 1;
	}
	std::vector<CharFreqSet> freqses;
	for (auto c_freq : frequencies)
		freqses.push_back({std::string(1, c_freq.first), c_freq.second});
	std::map<char, std::string> res;
	if (freqses.size() == 1)
	{
		res[freqses[0].char_set[0]] = "0";
		return res;
	}
	std::priority_queue<CharFreqSet> queue(freqses.begin(), freqses.end());
	while (queue.size() >= 2)
	{
		auto e1 = queue.top();
		queue.pop();
		auto e2 = queue.top();
		queue.pop();
		for (auto c : e1.char_set)
			res[c] = "0" + res[c];
		for (auto c : e2.char_set)
			res[c] = "1" + res[c];
		queue.push({e1.char_set + e2.char_set, e1.freq + e2.freq});
	}
	return res;
}

void Huffman::read_dict(ifstream& dict_is, int dict_size, map<string, char>& dict)
{
	char let_buf;
	string code_buf;
	getline(dict_is, code_buf);
	for (auto i = 0; i < dict_size; ++i)
	{
		string str;
		getline(dict_is, str);
		let_buf = str[0];
		istringstream istr(str.c_str() + 1);
		istr >> code_buf;
		dict[code_buf] = let_buf;
	}
}

string Huffman::decode(ifstream& dict_is, ifstream& text_is)
{
	int size, dict_size;
	map<string, char> dict;
	string code_buf, buf = "", res = "";
	dict_is >> dict_size;
	read_dict(dict_is, dict_size, dict);
	dict_is >> size;
	bool_array arr(size);
	text_is >> arr;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		buf += arr[i] ? '1' : '0';
		if (dict.find(buf) != dict.end())
		{
			res += dict[buf];
			buf = "";
		}
	}
	return res;
}
