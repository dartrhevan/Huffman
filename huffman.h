#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <map>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>

class Huffman
{
    struct CharFreqSet
    {
        std::string char_set;
        int freq;
        bool operator< (const CharFreqSet &o) const
        {
            return std::tie(freq, char_set) > std::tie(o.freq, o.char_set);
        }
    };

public:
    static std::map<char, std::string> encode(const std::string& text);
    Huffman() = delete;
    static std::string decode(std::ifstream& id);
};

#endif // HUFFMAN_H
