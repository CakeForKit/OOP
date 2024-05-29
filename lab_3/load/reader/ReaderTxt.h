#pragma once

#include <fstream>
#include "BaseReader.h"


class ReaderTxt : public BaseReader
{
public:
    ReaderTxt();
    ReaderTxt(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t readCount() override;
    virtual Dot readDot() override;
    virtual std::vector<Dot> readDotes() override;
    virtual std::vector<Link> readLinks(size_t &dotNum) override;

private:
    std::shared_ptr<std::ifstream> _file;
};