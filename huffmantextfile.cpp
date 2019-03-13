#include "huffmantextfile.h"

void HuffmanTextFile::write(const QString& path, const QString& text)
{

}

QString HuffmanTextFile::read(const QString& path)
{

}

void HuffmanTextFile::write_dict(std::ostream& out_dict, std::map<char, std::string>& code)
{
    out_dict << code.size() << std::endl;
    for (auto c : code)
        out_dict << c.first << ' ' << c.second << std::endl;
}
