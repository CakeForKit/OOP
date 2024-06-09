#pragma once

#include <memory>
#include "BaseDirector.h"
#include "CarcasModel.h"
#include "BaseBuilder.h"

class BaseCarcasModelDirector : public BaseDirector
{
public:
    BaseCarcasModelDirector() = default;
    virtual ~BaseCarcasModelDirector() = 0;
};

