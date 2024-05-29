#pragma once

#include <map>
#include "BaseModelDirectorCreator.h"
#include "ModelDirectorCreatorMaker.h"
#include "CarcasModelDirectorOfDotsLinks.h"

enum class IdModelDirectorCreator
{
    DOTS_LINKS = 0,
    MATRIX = 1
};

class ModelDirectorSolution
{
public:
    using CreatorPtr = unique_ptr<BaseModelDirectorCreator>(&)();
    using CallBackMap = map<IdModelDirectorCreator, CreatorPtr>;

public:
    ModelDirectorSolution() = default;
    ModelDirectorSolution(initializer_list<pair<IdModelDirectorCreator, CreatorPtr>> list);

    bool registrate(IdModelDirectorCreator id, CreatorPtr createfun);
    bool check(IdModelDirectorCreator id) 
    { 
        return callbacks.erase(id) == 1; 
    }

    unique_ptr<BaseModelDirectorCreator> create(IdModelDirectorCreator id);

private:
    CallBackMap callbacks;
};

shared_ptr<ModelDirectorSolution> make_solution_director(
    initializer_list<pair<IdModelDirectorCreator, ModelDirectorSolution::CreatorPtr>> list);

shared_ptr<ModelDirectorSolution> make_full_solution_director();
