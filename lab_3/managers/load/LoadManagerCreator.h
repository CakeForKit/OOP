#pragma once

#include <memory>

#include <LoadManager.h>

class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> create();

private:
    void createInstance();

    std::shared_ptr<LoadManager> _manager;
};


