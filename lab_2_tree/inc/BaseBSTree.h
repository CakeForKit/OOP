#pragma once


#include <cstddef>
#include <memory>
using namespace std;

class BaseBSTree
{
public:
    using size_type = size_t;

    explicit BaseBSTree(size_type size) noexcept;
    virtual ~BaseBSTree() = 0;

    size_type size() const noexcept;
    bool is_empty() const noexcept;
    operator bool() const noexcept;

protected:
    size_type countNodes = 0;
};
