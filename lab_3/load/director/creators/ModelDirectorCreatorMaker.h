#pragma once

#include "BaseDirector.h"
#include "ModelDirectorCreator.hpp"

class ModelDirectorCreatorMaker
{
public:
    template <Derivative<BaseDirector> TModelDirector>
    static unique_ptr<BaseModelDirectorCreator> createModelDirectorCreator() requires NotAbstract<TModelDirector>
    {
        return make_unique<ModelDirectorCreator<TModelDirector>>();
    }
};

