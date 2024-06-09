#pragma once
#include "CarcasModel.h"
#include "BaseCarcasModelBuilder.h"
#include "ListModelImpl.h"


class ListCarcasModelBuilder : public BaseCarcasModelBuilder {
    public:
        ListCarcasModelBuilder(std::shared_ptr<BaseCarcasModelReader> reader);
        
        virtual ~ListCarcasModelBuilder() = default;
};  