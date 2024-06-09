#include "ListModelImpl.h"


ListModelImpl::ListModelImpl() : _center(Point()), _points(std::vector<Point>()), _Links(std::vector<Link>()) {};

void ListModelImpl::Transform(const TransformAction& action) {
    for (Point& point : _points) {
        action.TransformPoint(point);
    }
}

std::vector<Point> ListModelImpl::GetPoints() const {
    return _points;
}

std::vector<Link> ListModelImpl::GetLinks() const {
    return _Links;
}

Point ListModelImpl::GetCenter() const {
    Point copy(_center);
    return copy;
}

void ListModelImpl::SetCenter(const Point& center) {
    _center = center;
}

void ListModelImpl::AddPoint(const Point& point) {
    _points.push_back(point);
}

void ListModelImpl::AddLink(const Link& Link) {
    _Links.push_back(Link);
}

std::shared_ptr<ModelImpl> ListModelImpl::Clone() const {
    auto cloned = std::make_shared<ListModelImpl>();
    cloned->SetCenter(_center);
    for (const Point& point : _points) {
        cloned->AddPoint(point);
    }
    
    for (const Link& Link : _Links) {
        cloned->AddLink(Link);
    }

    return cloned;
}
