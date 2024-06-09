#pragma once
#include "ReaderCreator.h"

template <typename TBase, typename T, typename... Args>
requires NotAbstract<T> && Derivative<T, TBase> && Constructible<T, Args...>
std::shared_ptr<TBase> ReaderCreator<TBase, T, Args...>::Create(Args&&... args) {
    return std::make_shared<T>(args...);
}