#include "BaseModelDirectorCreator.h"


shared_ptr<BaseDirector> BaseModelDirectorCreator::getModelDirector()
{
    if (!director)
    {
        director = create();
    }
    return director;
}