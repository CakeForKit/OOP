#include "BaseReaderCreator.h"


shared_ptr<BaseReader> BaseReaderCreator::getReader()
{
    if (!reader)
    {
        reader = create();
    }
    return reader;
}