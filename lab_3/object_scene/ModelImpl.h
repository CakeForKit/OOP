#pragma once
#include "TransformAction.h"
#include "Link.h"
#include "Point.h"
#include <vector>
#include <memory>


class ModelImpl {
    public:
        ModelImpl() = default;
        ModelImpl(const ModelImpl& other) = delete;
        ModelImpl(ModelImpl&& other) = delete;
        virtual ~ModelImpl() = 0;

        virtual void Transform(const TransformAction& action) = 0;
        virtual std::vector<Point> GetPoints() const = 0;
        virtual std::vector<Link> GetLinks() const = 0;
        virtual void AddPoint(const Point& point) = 0;
        virtual void AddLink(const Link& Link) = 0;
        virtual Point GetCenter() const = 0;
        virtual void SetCenter(const Point& center) = 0;
        virtual std::shared_ptr<ModelImpl> Clone() const = 0;
};