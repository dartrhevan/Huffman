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
    static void write(const QString& path, const QString& text);
    static QString read(const QString&);
    static void write_dict(std::ostream&, const std::map<char, std::string> &);
};

#endif // HUFFMANTEXTFILE_H
