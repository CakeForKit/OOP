#include "DrawVisitor.h"
#include "CarcasModel.h"
#include "Camera.h"
#include "Composite.h"

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera) : _drawer(drawer), _camera(camera) {}

Point DrawVisitor::getCameraProjection(const Point& point) const {
    Point &cameraPoint = _camera->_self;
    return Point(point.GetX() - cameraPoint.GetX(), point.GetY() - cameraPoint.GetY(), point.GetZ() - cameraPoint.GetZ());
}

void DrawVisitor::visit(CarcasModel& model) const {
    auto points = model._model->GetPoints();
    auto Links = model._model->GetLinks();

    for (auto &Link : Links) {
        Point &p1 = points[Link.GetFirst()];
        Point &p2 = points[Link.GetSecond()];
        Point proj1(getCameraProjection(p1));
        Point proj2(getCameraProjection(p2));
        _drawer->DrawLine(proj1, proj2);
    }
}
void DrawVisitor::visit(Camera& camera) const {
    (void) camera;
}
void DrawVisitor::visit(Composite& composite) const {
    for (auto &child : composite) {
        child->accept(*this);
    }
}