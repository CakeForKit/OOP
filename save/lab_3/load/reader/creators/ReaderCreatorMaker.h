#pragma once

#include "BaseReader.h"
#include "ReaderCreator.hpp"

class ReaderCreatorMaker
{
public:
    template <Derivative<BaseReader> TReader>
    static unique_ptr<BaseReaderCreator> createReaderCreator() requires NotAbstract<TReader>
    {
        return make_unique<ReaderCreator<TReader>>();
    }
};

