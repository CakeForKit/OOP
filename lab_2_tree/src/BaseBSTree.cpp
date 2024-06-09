#include "BaseBSTree.h"

BaseBSTree::~BaseBSTree() = default;

BaseBSTree::BaseBSTree(BaseBSTree::size_type size) noexcept
{
    countNodes = size;
}

BaseBSTree::size_type BaseBSTree::size() const noexcept
{
    return countNodes;
}

bool BaseBSTree::is_empty() const noexcept
{
    return countNodes == 0;
}

BaseBSTree::operator bool() const noexcept
{
    return !is_empty();
}