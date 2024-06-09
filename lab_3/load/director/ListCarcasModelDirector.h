#pragma once
#include "BaseCarcasModelDirector.h"


class ListCarcasModelDirector : public BaseCarcasModelDirector {
    public:
        ListCarcasModelDirector(std::shared_ptr<BaseCarcasModelReader> reader);
        virtual ~ListCarcasModelDirector() = default;
};