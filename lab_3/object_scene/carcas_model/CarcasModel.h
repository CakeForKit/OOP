#pragma once

#include <BaseCarcasModel.h>
#include <CarcasModelImpl.h>

using namespace std;

class CarcasModel : public BaseCarcasModel
{
public:
    using BaseCarcasModel::BaseCarcasModel;
    // explicit CarcasModel(const shared_ptr<CarcasModelImpl> modelImpl): _modelImpl(modelImpl) { }
    // CarcasModel(const CarcasModel &model);

    ~CarcasModel() override = default;
};

