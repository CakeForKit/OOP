#pragma once
#include "CarcasModel.h"
#include "ModelImpl.h"
#include "BaseCarcasModelReader.h"
#include "CenterStrategy.h"


class BaseCarcasModelBuilder {
    public:
        BaseCarcasModelBuilder(std::shared_ptr<BaseCarcasModelReader> reader);

        virtual ~BaseCarcasModelBuilder() = 0;

        virtual std::shared_ptr<CarcasModel> Get();
        virtual void ReadData();
        virtual void BuildPoints();
        virtual void BuildLinks();
        virtual void BuildCenter();
        virtual bool IsBuilt();
    protected:
        std::shared_ptr<BaseCarcasModelReader> _reader;
        std::shared_ptr<BaseCenterStrategy> _strategy;
        std::vector<Point> points;
        std::vector<Link> links;

        std::shared_ptr<ModelImpl> _model;
};