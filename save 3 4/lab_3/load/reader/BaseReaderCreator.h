#pragma once
#include "BaseReader.h"
#include "BaseCarcasModelReader.h"
#include <memory>
#include <concepts>

class BaseReaderCreator {
    public:
        virtual ~BaseReaderCreator() = default;
};

template <typename Reader, typename... Args>
class BaseReaderCreatorTemplate : public BaseReaderCreator {
    public:
        virtual ~BaseReaderCreatorTemplate() = default;

        virtual std::shared_ptr<Reader> Create(Args&&... args) = 0;

};

using CarcasModelReaderCreator_t = BaseReaderCreatorTemplate<BaseCarcasModelReader, const char*>;
