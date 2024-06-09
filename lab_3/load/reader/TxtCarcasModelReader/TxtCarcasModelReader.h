#pragma once
#include "BaseCarcasModelReader.h"
#include "CenterStrategy.h"
#include <fstream>
#include <memory>

class TxtCarcasModelReader : public BaseCarcasModelReader {
    public:
        TxtCarcasModelReader(const char* filename);
        virtual ~TxtCarcasModelReader();


        virtual void open();
        virtual void close();
        virtual bool is_open();

        virtual std::vector<Point> ReadPoints();
        virtual std::vector<Link> ReadLinks();
        virtual Point ReadCenter();

    protected:
        const char* _fname;
        std::ifstream _file;
        std::shared_ptr<BaseCenterStrategy> _centerStrategy;

};