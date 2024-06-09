#pragma once
#include "ModelImpl.h"
#include "Point.h"
#include <vector>


class MatrixModelImpl : public ModelImpl {
    public:
        MatrixModelImpl();
        
        ~MatrixModelImpl() = default;
        virtual void Transform(const TransformAction& action);
        virtual std::vector<Point> GetPoints() const;
        virtual std::vector<Link> GetLinks() const;
        virtual void AddPoint(const Point& point);
        virtual void AddLink(const Link& Link);
        virtual Point GetCenter() const;
        virtual void SetCenter(const Point& center);
        virtual std::shared_ptr<ModelImpl> Clone() const;
    
    private:
        Point _center;

        std::vector<Point> _points;
        SquareMatrix<int> _LinkMatrix;
};