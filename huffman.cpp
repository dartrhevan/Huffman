#include "huffman.h"
#include "bool_array.h"

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
            freqses.push_back({ std::string(1, c_freq.first), c_freq.second });
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
            queue.push({ e1.char_set + e2.char_set, e1.freq + e2.freq });
        }
        return res;
    }


std::string Huffman::decode(std::ifstream& is)
{
    int size, dict_size;
    std::map<std::string, char> dict;
    std::string let_buf, code_buf, buf = "", res = "";
    is >> dict_size;
    for (auto i = 0; i < dict_size; ++i)
    {
        is >> let_buf >> code_buf;
        dict[code_buf] = let_buf[0];
    }
    is >> size;
    bool_array arr(size);
    is >> arr;
    for(auto i = 0; i < arr.size(); ++i)
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
