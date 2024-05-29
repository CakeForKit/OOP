#include <cerrno>
#include <cstring>

#include "ReaderCsv.h"
#include "LoadException.h"


ReaderCsv::ReaderCsv()
{
    _file = std::make_shared<std::ifstream>();
}

ReaderCsv::ReaderCsv(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void ReaderCsv::open(std::string &fileName)
{
    if (!_file)
    {
        time_t tm = time(NULL);
        throw FileException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    _file->open(fileName);

    if (!_file->is_open())
    {
        time_t tm = time(NULL);
        throw FileOpenException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__, std::strerror(errno));
    }
}

void ReaderCsv::close()
{
    if (!_file)
    {
        time_t tm = time(NULL);
        throw FileException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    _file->close();
}

std::size_t ReaderCsv::readCount()
{
    int count;

    if (!(*_file >> count) || count <= 0)
    {
        time_t tm = time(NULL);
        throw FileReadCountException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    return count;
}

#include <iostream>
#include <string>

Dot ReaderCsv::readDot()
{
    char tmp;
    double x, y, z;
    if (!(*_file >> x) || !(*_file >> tmp) || !(*_file >> y) || !(*_file >> tmp) || !(*_file >> z))
    {
        time_t tm = time(NULL);
        throw FileReadDotException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    return Dot(x, y, z);
}

std::vector<Dot> ReaderCsv::readDotes()
{
    std::vector<Dot> dotes;

    size_t dotNum = readCount();

    Dot dot;
    for (size_t i = 0; i < dotNum; i++)
    {
        dot = readDot();
       dotes.push_back(dot);
    }

    return dotes;
}

std::vector<Link> ReaderCsv::readLinks(size_t &dotNum)
{
    std::vector<Link> links;
    size_t linksNum = readCount();

    char tmp;
    int dot1Index, dot2Index;

    for (size_t i = 0; i < linksNum; i++)
    {
        if (!(*_file >> dot1Index) || !(*_file >> tmp) || !(*_file >> dot2Index))
        {
            time_t tm = time(NULL);
            throw FileReadLinkException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }

        if (dot1Index < 0 or dot2Index < 0 or
            static_cast<size_t>(dot1Index) > dotNum or static_cast<size_t>(dot2Index) > dotNum)
        {
            time_t tm = time(NULL);
            throw LinkDataException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
        }

        links.push_back(Link(dot1Index, dot2Index));
    }

    return links;
}
