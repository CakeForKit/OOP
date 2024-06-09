#pragma once
#include "BaseReader.h"
#include "Point.h"
#include "Link.h"
#include <vector>

class BaseCarcasModelReader : public BaseReader {
    public:
        BaseCarcasModelReader() = default;

        virtual ~BaseCarcasModelReader() = 0;

        virtual void open() = 0;
        virtual void close() = 0;
        virtual bool is_open() = 0;

        virtual std::vector<Point> ReadPoints() = 0;
        virtual std::vector<Link> ReadLinks() = 0;
        virtual Point ReadCenter() = 0;
}; 