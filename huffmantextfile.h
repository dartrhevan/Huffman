#ifndef HUFFMANTEXTFILE_H
#define HUFFMANTEXTFILE_H

#include <string>
#include <fstream>
#include <QString>
#include "huffman.h"
#include "bool_array.h"

class HuffmanTextFile
{
public:
    HuffmanTextFile() = delete;
    static void write(const QString&, const QString&);
    static QString read(const QString&);
    void write_dict(std::ostream&, std::map<char, std::string>&);
};

#endif // HUFFMANTEXTFILE_H
