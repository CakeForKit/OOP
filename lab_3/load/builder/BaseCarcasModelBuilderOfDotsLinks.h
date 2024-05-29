#pragma once

#include "BaseModel.h"
#include "CarcasModelOfDotsLink.h"

class BaseCarcasModelBuilderOfDotsLinks
{
public:
    BaseCarcasModelBuilderOfDotsLinks() = default;
    ~BaseCarcasModelBuilderOfDotsLinks() = default;

    virtual void build() = 0;
    virtual void buildDot(const Dot &dot) = 0;
    virtual void buildLink(const Link &link) = 0;
    virtual bool isBuild() const = 0;

    virtual std::shared_ptr<BaseModel> get() = 0;

protected:
    std::shared_ptr<CarcasModelOfDotsLinks> _model;
};
