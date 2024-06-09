#include "BaseCarcasModelBuilder.h"


BaseCarcasModelBuilder::BaseCarcasModelBuilder(std::shared_ptr<BaseCarcasModelReader> reader)
: _reader(reader), _strategy(std::make_shared<CenterStrategy>()) {}

BaseCarcasModelBuilder::~BaseCarcasModelBuilder() {}

void BaseCarcasModelBuilder::ReadData() {
    _reader->open();
    points = _reader->ReadPoints();
    links = _reader->ReadLinks();
    _reader->close();
}

void BaseCarcasModelBuilder::BuildPoints() {
    for (auto &p : points) {
        // std::cout << "Read points ---- " << p.GetX() << " " << p.GetY() << " " << p.GetZ() <<  std::endl;
        _model->AddPoint(p);
    }
}

void BaseCarcasModelBuilder::BuildLinks() {
    for (auto &e : links) {
        _model->AddLink(e);
    }
}

void BaseCarcasModelBuilder::BuildCenter() {
    _model->SetCenter(_strategy->CenterAlgorithm(points));
}

std::shared_ptr<CarcasModel> BaseCarcasModelBuilder::Get() {
    return std::make_shared<CarcasModel>(_model);
}

bool BaseCarcasModelBuilder::IsBuilt() {
    return _model->GetPoints().size() != 0;
}