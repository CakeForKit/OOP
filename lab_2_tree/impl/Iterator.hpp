#pragma once

#include "Iterator.h"

template <TypeForTree T>
Iterator<T>::Iterator(Iterator<T>&& iter) noexcept //: BaseIterator<T>::BaseIterator(iter) 
{
    this->proot = iter.proot;
    this->pcur = iter.pcur;
}

template <TypeForTree T>
Iterator<T>::Iterator(const Iterator<T>& iter) noexcept : BaseIterator<T>::BaseIterator(iter) 
{
    this->proot = iter.proot;
    this->pcur = iter.pcur;
}

template <TypeForTree T>
Iterator<T>::Iterator(const BSTree<T> &tree) noexcept : BaseIterator<T>::BaseIterator()
{
    std::weak_ptr<nodeTree> ptr = tree.root;
    this->proot = ptr;
    this->pcur = ptr;
}

template <TypeForTree T>
Iterator<T>::reference Iterator<T>::operator*() const
{
    this->expride_exeption(__LINE__);

    const shared_ptr<nodeTree> a = this->pcur.lock();
    const shared_ptr<T> d = a->GetData();
    return *d;
}


template <TypeForTree T>
Iterator<T>::pointer Iterator<T>::operator->() const
{
    const shared_ptr<nodeTree> a = this->pcur.lock();
    return *(this->pcur->GetData());
}

template <TypeForTree T>
Iterator<T>& Iterator<T>::operator++()
{
    this->expride_exeption(__LINE__);

    auto ptr = this->pcur.lock();
    // auto next = next->GetLeft();
    if (ptr->GetLeft() == nullptr) {
        auto next = ptr->GetRight();    // if right == nullptr -> return expired
        this->pcur = next;
    }
    else{
        auto next = ptr->GetLeft();
        this->pcur = next;
    }
    return *this;
}

template <TypeForTree T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> tmp(*this);
    
    auto ptr = this->pcur.lock();
    // auto next = next->GetLeft();
    if (ptr->GetLeft() == nullptr) {
        auto next = ptr->GetRight();    // if right == nullptr -> return expired
        this->pcur = next;
    }
    else{
        auto next = ptr->GetLeft();
        this->pcur = next;
    }
    

    return tmp;
}

template <TypeForTree T>
Iterator<T>& Iterator<T>::operator--()
{
    this->expride_exeption(__LINE__);

    int typeNode;
    bool endLoop = false;

    while (!endLoop)
    {
        typeNode = type_node_of_parant(this->pcur);
        if (typeNode == 0)
        {
            this->pcur = nullptr;
            endLoop = true;
        }
        else
        {
            std::weak_ptr<nodeTree> parant = this->pcur->getParant();
            if (typeNode == -1)
            {
                this->pcur = parant.getRight();
                endLoop = true;
            }
            else
                this->pcur = parant;
        }
    }
    return *this;
}

template <TypeForTree T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator<T> tmp(*this);
    --(*this);
    return tmp;
}