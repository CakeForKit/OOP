#pragma once

#include "BaseCarcasModelDirector.h"

class MatrixCarcasModelDirector : public BaseCarcasModelDirector {
    public:
        MatrixCarcasModelDirector(std::shared_ptr<BaseCarcasModelReader> reader);
        virtual ~MatrixCarcasModelDirector() = default;
};