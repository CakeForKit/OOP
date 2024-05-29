#pragma once

#include "concepts.hpp"
#include "BaseReaderCreator.h"

template <Derivative<BaseReader> TReader>
requires NotAbstract<TReader> && DefaultConstructible<TReader>
class ReaderCreator : public BaseReaderCreator
{
protected:
    shared_ptr<BaseReader> create() override
    {
        return make_shared<TReader>();
    }
};