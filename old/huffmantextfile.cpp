#include "huffmantextfile.h"


void HuffmanTextFile::write(const QString& path, const QString& text)
{
    auto code = Huffman::encode(std::move(text.toStdString()));
    std::ofstream output(std::move(path.toStdString()));
    HuffmanTextFile::write_dict(output, code);
    std::string coded_text;
    //QChar::to
    for (auto c : text)
        coded_text += code[c.toLatin1()];
    bool_array arr(std::move(coded_text));
    output << " " << arr;
}

QString HuffmanTextFile::read(const QString& path)
{
    auto ifstr = std::ifstream(std::move(path.toStdString()));
    auto text = Huffman::decode(ifstr);
    return QString::fromStdString(std::move(text));

}

void HuffmanTextFile::write_dict(std::ostream& out_dict, const std::map<char, std::string>& code)
{
    out_dict << code.size() << std::endl;
    for (auto c : code)
        out_dict << c.first << ' ' << c.second << std::endl;
}
