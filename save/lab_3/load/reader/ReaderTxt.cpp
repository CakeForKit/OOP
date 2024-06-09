#include <cerrno>
#include <cstring>

#include "ReaderTxt.h"
#include "LoadException.h"


ReaderTxt::ReaderTxt()
{
    _file = std::make_shared<std::ifstream>();
}

ReaderTxt::ReaderTxt(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void ReaderTxt::open(std::string &fileName)
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

void ReaderTxt::close()
{
    if (!_file)
    {
        time_t tm = time(NULL);
        throw FileException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    _file->close();
}

std::size_t ReaderTxt::readCount()
{
    int count;

    if (!(*_file >> count) || count <= 0)
    {
        time_t tm = time(NULL);
        throw FileReadCountException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    return count;
}

Dot ReaderTxt::readDot()
{
    double x, y, z;

    if (!(*_file >> x >> y >> z))
    {
        time_t tm = time(NULL);
        throw FileReadDotException(ctime(&tm), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    return Dot(x, y, z);
}

std::vector<Dot> ReaderTxt::readDotes()
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

std::vector<Link> ReaderTxt::readLinks(size_t &dotNum)
{
    std::vector<Link> links;

    size_t linksNum = readCount();

    int dot1Index, dot2Index;

    for (size_t i = 0; i < linksNum; i++)
    {
        if (!(*_file >> dot1Index >> dot2Index))
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
