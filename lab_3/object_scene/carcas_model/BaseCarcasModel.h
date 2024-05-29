#pragma once

#include <BaseModel.h>
#include <CarcasModelImpl.h>

using namespace std;

class BaseCarcasModel : public BaseModel
{
public:
    explicit BaseCarcasModel(const shared_ptr<CarcasModelImpl> &modelImpl): _modelImpl(modelImpl) { }

    ~BaseCarcasModel() = 0;

protected:
    shared_ptr<CarcasModelImpl> _modelImpl;
};


