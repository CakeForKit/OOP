#pragma once

#include "BaseIterator.h"


template <TypeForTree T>
BaseIterator<T>::BaseIterator(const BaseIterator<T> &iterator) noexcept
{
    proot = iterator.proot;
    pcur = iterator.pcur;
}

template <TypeForTree T>
BaseIterator<T>::operator bool() const noexcept
{
    return !proot.expired() && !pcur.expired();
}

template <TypeForTree T>
const T& BaseIterator<T>::operator*() const
{
    expride_exeption(__LINE__);

    const shared_ptr<nodeTree> a = proot.lock();
    return proot->GetData().get();
}

template <TypeForTree T>
const T* BaseIterator<T>::operator->() const
{
    const shared_ptr<nodeTree> a = proot.lock();
    return *(proot->GetData());
}

template <TypeForTree T>
bool BaseIterator<T>::operator==(const BaseIterator<T> &other) const noexcept
{
    return proot.lock().get() == other.proot.lock().get();
}

template <TypeForTree T>
bool BaseIterator<T>::operator!=(const BaseIterator<T> &other) const noexcept
{
    return proot.lock().get() != other.proot.lock().get();
}


template <TypeForTree T>
void BaseIterator<T>::expride_exeption(const size_t line) const
{
    if (proot.expired() || pcur.expired())
    {
        time_t curTime = time(NULL);
        throw ExpiredException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __func__);
    }
}