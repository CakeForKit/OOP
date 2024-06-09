#pragma once

#include <memory>

#include "conceptsBSTree.h"
#include "BaseIterator.hpp"


template <TypeForTree T>
class Iterator: public BaseIterator<T>
{
	using nodeTree = typename BSTree<T>::NodeTree;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*; 
    using reference = T&;

	Iterator() noexcept = default;
	Iterator(Iterator<T>&& iter) noexcept;
    explicit Iterator(const Iterator<T>& iter) noexcept; // if make it explicit (std::vector<int>(m1.begin(), tt);) wouldn't work
	explicit Iterator(const BSTree<T> &tree) noexcept;

	reference operator*() const;
	// const T& operator*() const;

	pointer operator->() const;
	// const T* operator->() const;

	Iterator<T>& operator++();
	Iterator<T> operator++(int);

    Iterator<T>& operator--();
	Iterator<T> operator--(int);

};




