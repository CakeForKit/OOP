#pragma once

#include <memory>
#include <cstdlib>

#include "BSTree.hpp"
#include "conceptsIterator.h"
#include "Exceptions.h"

using namespace std;

template <TypeForTree T>
class BSTree;

template <TypeForTree T>
class BaseIterator
{
    using nodeTree = typename BSTree<T>::NodeTree;
public:
    operator bool() const noexcept;

	const T& operator*() const;
	const T* operator->() const;

    bool operator==(const BaseIterator<T> &other) const noexcept;
    bool operator!=(const BaseIterator<T> &other) const noexcept;

	virtual ~BaseIterator() = default;
protected:
    BaseIterator() noexcept = default;
    explicit BaseIterator(const BaseIterator &iterator) noexcept;
    
	weak_ptr<nodeTree> proot;
    weak_ptr<nodeTree> pcur;

	void expride_exeption(const size_t line) const;	
};


