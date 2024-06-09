#pragma once
#include "BaseReaderCreator.h"
#include "BaseCarcasModelReader.h"
#include "TxtCarcasModelReader.h"
#include "CsvCarcasModelReader.h"
#include "concept.h"
#include <memory>

template <typename TBase, typename T, typename... Args>
requires NotAbstract<T> && Derivative<T, TBase> && Constructible<T, Args...>
class ReaderCreator : public BaseReaderCreatorTemplate<TBase, Args...> {
    public:
        virtual ~ReaderCreator() = default;
        virtual std::shared_ptr<TBase> Create(Args&&... args);
};

using TxtCarcasModelReaderCreator = ReaderCreator<BaseCarcasModelReader, TxtCarcasModelReader, const char *>;
using CsvCarcasModelReaderCreator = ReaderCreator<BaseCarcasModelReader, CsvCarcasModelReader, const char *>;

#include "ReaderCreator.hpp"