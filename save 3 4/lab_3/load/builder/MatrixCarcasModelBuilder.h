#pragma once
#include "BaseCarcasModelBuilder.h"


class MatrixCarcasModelBuilder : public BaseCarcasModelBuilder {
    public:
        MatrixCarcasModelBuilder(std::shared_ptr<BaseCarcasModelReader> reader);
        virtual ~MatrixCarcasModelBuilder() = default;
};