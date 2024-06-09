#pragma once
#include "BaseCarcasModelBuilderOfDotsLinks.h"
#include "CarcasModel.h"

class CarcasModelBuilderOfDotsLinks : public BaseCarcasModelBuilderOfDotsLinks
{
public:
    CarcasModelBuilderOfDotsLinks() {_model = make_shared<CarcasModelOfDotsLinks>(); };
    ~CarcasModelBuilderOfDotsLinks() = default;

    void build() override;
    void buildDot(const Dot &dot) override;
    void buildLink(const Link &link) override;
    bool isBuild() const override;

    std::shared_ptr<BaseModel> get() override;
};
