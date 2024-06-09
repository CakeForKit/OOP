#pragma once
#include "TransformAction.h"
#include "Link.h"
#include "Point.h"
#include "ModelImpl.h"
#include <vector>



class ListModelImpl : public ModelImpl {
    public:
        ListModelImpl();
        
        ~ListModelImpl() = default;
        virtual void Transform(const TransformAction& action);
        virtual std::vector<Point> GetPoints() const;
        virtual std::vector<Link> GetLinks() const;
        virtual void AddPoint(const Point& point);
        virtual void AddLink(const Link& Link);
        virtual Point GetCenter() const;
        virtual void SetCenter(const Point& center);
        virtual std::shared_ptr<ModelImpl> Clone() const;
    
    protected:
        Point _center;

        std::vector<Point> _points;
        std::vector<Link> _Links;
};