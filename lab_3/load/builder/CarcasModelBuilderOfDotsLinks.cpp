#include "CarcasModelBuilderOfDotsLinks.h"

void CarcasModelBuilderOfDotsLinks::build()
{
    _model = std::make_shared<CarcasModelOfDotsLinks>();
}


void CarcasModelBuilderOfDotsLinks::buildDot(const Dot &dot)
{
    if (!isBuild()) { }

    _model->addDot(dot);
}


void CarcasModelBuilderOfDotsLinks::buildLink(const Link &link)
{
    if (!isBuild()) { }

    _model->addLink(link);
}


bool CarcasModelBuilderOfDotsLinks::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<BaseModel> CarcasModelBuilderOfDotsLinks::get()
{
    return std::make_shared<CarcasModel>(_model);
}
