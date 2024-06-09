#include "DirectorSolution.h"
#include "solutionexception.h"


DirectorSolution::DirectorSolution() : _creators(std::map<IdDirectorCreator, std::shared_ptr<BaseDirectorCreator>>()) {}

DirectorSolution::~DirectorSolution() {}

DirectorSolution::DirectorSolution(std::initializer_list<std::pair<IdDirectorCreator, std::shared_ptr<BaseDirectorCreator>>> list) {
    for (const auto& pair : list) {
        _creators[pair.first] = pair.second;
    }
}


bool DirectorSolution::Check(IdDirectorCreator index) {
    return _creators.find(index)!= _creators.end();
}

std::shared_ptr<BaseDirectorCreator> DirectorSolution::Create(IdDirectorCreator index) {
    if (Check(index)) {
        return _creators[index];
    }
    time_t now = time(nullptr);
    throw SolutionNotFoundException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
}


void DirectorSolution::Register(IdDirectorCreator index, std::shared_ptr<BaseDirectorCreator> creator) {
    if (Check(index)) {
        time_t now = time(nullptr);
        throw SolutionAlreadyInException(ctime(&now), __FILE__, __LINE__, typeid(*this).name(), __FUNCTION__);
    }
    _creators[index] = creator;
}