#pragma once

#include "concepts.hpp"
#include "BaseModelDirectorCreator.h"

template <typename TBase, typename T, typename... Args>
requires NotAbstract<T> && Derivative<T, TBase> && Constructible<T, Args...>
class ModelDirectorCreator : public BaseModelDirectorTemplate<TBase, Args...> {
    public:
        virtual ~ModelDirectorCreator() = default;
        virtual std::shared_ptr<TBase> create(Args&&... args);
};


