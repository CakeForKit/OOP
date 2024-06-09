#pragma once
#include "BaseModel.h"
#include "ModelImpl.h"
#include "TransformAction.h"
#include <memory>
#include "DrawVisitor.h"


class Visitor;

class CarcasModel : public BaseModel {
    friend class DrawVisitor;
    public:
        CarcasModel();
        explicit CarcasModel(std::shared_ptr<ModelImpl>);
        explicit CarcasModel(const CarcasModel& other);
        ~CarcasModel() = default;

        virtual void accept(const Visitor& visitor);
        virtual void Transform(const TransformAction& action);
        virtual Point GetCenter() const;

    protected:
        std::shared_ptr<ModelImpl> _model;

};