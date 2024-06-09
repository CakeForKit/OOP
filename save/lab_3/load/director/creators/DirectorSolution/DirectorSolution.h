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

class DirectorSolution
{
public:
    using CreatorPtr = unique_ptr<BaseModelDirectorCreator>(&)();
    using CallBackMap = map<IdModelDirectorCreator, CreatorPtr>;

public:
    DirectorSolution() = default;
    DirectorSolution(initializer_list<pair<IdModelDirectorCreator, CreatorPtr>> list);

    bool registrate(IdModelDirectorCreator id, CreatorPtr createfun);
    bool check(IdModelDirectorCreator id) 
    { 
        return callbacks.erase(id) == 1; 
    }

    unique_ptr<BaseModelDirectorCreator> create(IdModelDirectorCreator id);

private:
    CallBackMap callbacks;
};

shared_ptr<DirectorSolution> make_solution_director(
    initializer_list<pair<IdModelDirectorCreator, DirectorSolution::CreatorPtr>> list);

shared_ptr<DirectorSolution> make_full_solution_director();
