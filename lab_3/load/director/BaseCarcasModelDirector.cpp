#include "BaseCarcasModelDirector.h"
#include "directorexception.h"
#include <iostream>


BaseCarcasModelDirector::~BaseCarcasModelDirector() {}

BaseCarcasModelDirector::BaseCarcasModelDirector(std::shared_ptr<BaseCarcasModelReader> reader) { (void) reader; }

void BaseCarcasModelDirector::Create() {

    _builder->ReadData();
    _builder->BuildPoints();
    _builder->BuildLinks();
    _builder->BuildCenter();
}

std::shared_ptr<Object> BaseCarcasModelDirector::Get() {
    if (!_builder->IsBuilt()){
        Create();
        std::cout << "Create Object " << std::endl;
    }
    
    return _builder->Get();
}