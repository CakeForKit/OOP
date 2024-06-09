#include "MatrixModelImpl.h"
#include "modelexception.h"
#include <iostream>


MatrixModelImpl::MatrixModelImpl() : _center(Point()), _points(std::vector<Point>()), _LinkMatrix(SquareMatrix<int>()) {};

void MatrixModelImpl::Transform(const TransformAction& action) {
    for (Point& point : _points) {
        action.TransformPoint(point);
    }
}

std::vector<Point> MatrixModelImpl::GetPoints() const {
    return _points;
}

std::vector<Link> MatrixModelImpl::GetLinks() const {
    std::vector<Link> _Links;

    for (size_t i = 0; i < _LinkMatrix.size(); ++i) {
        for (auto it = _LinkMatrix[i].cbegin() + i; it != _LinkMatrix[i].cend(); ++it) {
            if (*it) {
                _Links.push_back(Link(i, std::distance(_LinkMatrix[i].cbegin(), it)));
            }
        }
    }

    return _Links;
}

Point MatrixModelImpl::GetCenter() const {
    Point copy(_center);
    return copy;
}

void MatrixModelImpl::SetCenter(const Point& center) {
    _center = center;
}

void MatrixModelImpl::AddPoint(const Point& point) {
    _points.push_back(point);
    _LinkMatrix.Resize(_points.size(), false);
}

void MatrixModelImpl::AddLink(const Link& Link) {
    if (Link.GetFirst() >= _points.size() || Link.GetSecond() >= _points.size()) {
        time_t now = time(nullptr);
        throw LinkOutOfPointsException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    *(_LinkMatrix[Link.GetFirst()].begin() + Link.GetSecond()) = true;
    *(_LinkMatrix[Link.GetSecond()].begin() + Link.GetFirst()) = true;

    // for (size_t i = 0; i < _LinkMatrix.size(); i++ ) {
    //     for (auto it = _LinkMatrix[i].begin(); it != _LinkMatrix[i].end(); ++it) {
    //         std::cout << *it << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}

std::shared_ptr<ModelImpl> MatrixModelImpl::Clone() const {
    auto cloned = std::make_shared<MatrixModelImpl>();
    cloned->SetCenter(_center);
    for (const Point& point : _points) {
        cloned->AddPoint(point);
    }
    cloned->_LinkMatrix = _LinkMatrix;
    std::cout << "Cloned" << std::endl;

    return cloned;
}
