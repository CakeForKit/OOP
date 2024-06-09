#pragma once
#include "BaseDirectorCreator.h"
#include "DirectorCreator.h"
#include <map>

enum class IdDirectorCreator
{
    LIST = 0,
    MATRIX = 1
};


class DirectorSolution {
    using CreatorPtr = std::shared_ptr<BaseDirectorCreator>;

    public:
        DirectorSolution();
        DirectorSolution(std::initializer_list<std::pair<IdDirectorCreator, CreatorPtr>> list);

        void Register(IdDirectorCreator index, CreatorPtr creator);
        bool Check(IdDirectorCreator index);
        CreatorPtr Create(IdDirectorCreator index);

        ~DirectorSolution();

    private:
        std::map<IdDirectorCreator, CreatorPtr> _creators;
};