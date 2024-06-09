#include "CarcasModel.h"
#include "Visitor.h"


CarcasModel::CarcasModel() : _model(nullptr) {}

CarcasModel::CarcasModel(std::shared_ptr<ModelImpl> model) : _model(model) {}

CarcasModel::CarcasModel(const CarcasModel &model) : _model(model._model) {}

void CarcasModel::accept(const Visitor& v) {
    v.visit(*this);
}

void CarcasModel::Transform(const TransformAction& action) {
    _model->Transform(action);
}

Point CarcasModel::GetCenter() const {
    return _model->GetCenter();
}