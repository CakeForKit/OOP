#pragma once
#include "BSTree.h"

template <TypeForTree T>
template <typename... Args>
std::shared_ptr<typename BSTree<T>::NodeTree> BSTree<T>::NodeTree::CreateNode(Args&&... params)
{
    struct Enable_make_shared : public BSTree<T>::NodeTree
    {
        Enable_make_shared(Args&&... params) : BSTree<T>::NodeTree(std::forward<Args>(params)...) {};
    };

    return std::make_shared<Enable_make_shared>(std::forward<Args>(params)...);
}

#include <iostream>

template <TypeForTree T>
BSTree<T>::NodeTree::NodeTree(const T &_data)
: data(_data), left(nullptr), right(nullptr) {};


template <TypeForTree T>
BSTree<T>::NodeTree::NodeTree(T &&_data)
: data(_data), left(nullptr), right(nullptr) {};

template <TypeForTree T>
void BSTree<T>::NodeTree::SetData(const T &_data) noexcept
{
    data = _data;
}

template <TypeForTree T>
void BSTree<T>::NodeTree::SetParant(const std::shared_ptr<NodeTree> node) noexcept
{
    parant = std::weak_ptr(node);
}


template <TypeForTree T>
void BSTree<T>::NodeTree::SetLeft(const std::shared_ptr<NodeTree> node) noexcept
{
    left = node;
}

template <TypeForTree T>
void BSTree<T>::NodeTree::SetRight(const std::shared_ptr<NodeTree> node) noexcept
{
    right = node;
}

template <TypeForTree T>
bool BSTree<T>::NodeTree::checkParant() noexcept
{
    return !parant.expired();
}

template <TypeForTree T>
bool BSTree<T>::NodeTree::operator ==(const std::shared_ptr<NodeTree> node) noexcept
{
    return data == node->GetData() && left == node->GetLeft() && right == node->GetRight() && parant == node->GetParant();
}

template <TypeForTree T>
int BSTree<T>::NodeTree::type_node_of_parant(const std::shared_ptr<typename BSTree<T>::NodeTree> node)
{
    std::weak_ptr<typename BSTree<T>::NodeTree> parant = node->GetParant();
    if (parant.expired())
        return 0;
    else if (parant->GetLeft() == node)
        return -1;
    else if (parant->GetRight() == node)
        return 1;
    else
    {
        time_t curTime = time(NULL);
        throw ParantPtrExcetion(ctime(&curTime), __FILE__, __LINE__, typeid(BSTree<T>::NodeTree).name(), __func__);
    }
}

// template <TypeForTree T>
// std::shared_ptr<typename BSTree<T>::NodeTree> BSTree<T>::NodeTree::deleteParant()
// {
//     std::shared_ptr<typename BSTree<T>::NodeTree> ptr = shared_from_this();
//     parant
// }

template <TypeForTree T>
void BSTree<T>::NodeTree::SetLeftNull() noexcept
{
    left = nullptr;
}


template <TypeForTree T>
void BSTree<T>::NodeTree::SetRightNull() noexcept
{
    right = nullptr;
}

template <TypeForTree T>
std::shared_ptr<T> BSTree<T>::NodeTree::GetData() noexcept
{
    auto tmp_ptr = this->shared_from_this();

    return {tmp_ptr, &tmp_ptr->data}; 
}

template <TypeForTree T>
std::weak_ptr<typename BSTree<T>::NodeTree> BSTree<T>::NodeTree::GetParant() noexcept
{   
    return parant;
}

template <TypeForTree T>
std::shared_ptr<typename BSTree<T>::NodeTree> BSTree<T>::NodeTree::GetLeft() noexcept
{
    return left;
}

template <TypeForTree T>
std::shared_ptr<typename BSTree<T>::NodeTree> BSTree<T>::NodeTree::GetRight() noexcept
{
    return right;
}
