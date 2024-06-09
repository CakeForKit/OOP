#pragma once

#include <string>
#include <vector>

#include "Dot.h"
#include "Link.h"


class BaseReader
{
public:
    BaseReader() = default;
    virtual ~BaseReader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t readCount() = 0;
    virtual Dot readDot() = 0;
    virtual std::vector<Dot> readDotes() = 0;
    virtual std::vector<Link> readLinks(size_t &dotNum) = 0;
};

