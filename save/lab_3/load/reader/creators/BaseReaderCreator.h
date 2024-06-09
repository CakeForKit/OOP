#pragma once

#include <memory>
#include "BaseReader.h"

using namespace std;

class BaseReaderCreator
{
public:
    virtual ~BaseReaderCreator() = default;
    shared_ptr<BaseReader> getReader();    // идиома невиртуального интерфейса пример 11.01.03

protected:
    virtual shared_ptr<BaseReader> create() = 0;

private:
    shared_ptr<BaseReader> reader{ nullptr };
};