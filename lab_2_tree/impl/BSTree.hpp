#pragma once
#include "BSTree.h"

#pragma region Constructors
template <TypeForTree T>
BSTree<T>::BSTree() noexcept
: BaseBSTree(0), root(nullptr) {}


template <TypeForTree T>
BSTree<T>::BSTree(const BSTree<T> &tree)
: BaseBSTree(0), root(nullptr)
{
    std::cout << "erwr";
    for (auto it = tree.begin(); it != tree.end(); ++it)
        Add(*it);
}


template <TypeForTree T>
BSTree<T>::BSTree(BSTree<T> &&tree) noexcept
: BaseBSTree(tree.countNodes), root(tree.root)
{
    tree.root = nullptr;
    tree.countNodes = 0;
}


template <TypeForTree T>
BSTree<T>::BSTree(std::initializer_list<T> lst)
: BaseBSTree(0), root(nullptr)
{
    for (auto it = lst.begin(); it!= lst.end(); ++it)
        Add(*it);
}

 // с преобразованием
template <TypeForTree T>
template <Convertable<T> U> // from U to T
BSTree<T>::BSTree(const BSTree<U> &tree)
: BaseBSTree(0), root(nullptr)
{
    for (auto it = tree.begin(); it != tree.end(); ++it)
        Add(*it);
}

template <TypeForTree T>
template <Convertable<T> U> 
BSTree<T>::BSTree(std::initializer_list<U> list)
: BaseBSTree(0), root(nullptr)
{
    for (auto it = list.begin(); it!= list.end(); ++it)
        Add(*it);
}

// из контейнера
template <TypeForTree T>
template <ContainerConvertableAssignable<T> U>  
BSTree<T>::BSTree(const U& container)
: BaseBSTree(0), root(nullptr)
{
    for (auto it = container.begin(); it!= container.end(); ++it)
        Add(*it);
}

// из input итератора
template <TypeForTree T>
template <std::input_iterator Iter>
BSTree<T>::BSTree(const Iter &begin, const Iter &end)
: BaseBSTree(0), root(nullptr)
{
    for (auto it = begin; it!= end; ++it)
        Add(*it);
}
#pragma endregion Constructors

#pragma region It_is_conteiner

template <TypeForTree T>
Iterator<T> BSTree<T>::begin() const noexcept
{
    Iterator<T> tmp(*this);
    return tmp;
}

template <TypeForTree T>
Iterator<T> BSTree<T>::end() const noexcept
{
    // BSTree<T> tree(*this);
    std::cout << "qweqwe" << std::endl;
    while (root->GetRight() != nullptr)
    {
        tree.SetNewRoot(tree.root->GetRight());
    }
    // auto rt = tree.root->GetRight();
    // bool endLoop = false;
    // while (!endLoop)
    // {
    //     tree.SetNewRoot(rt);
    //     rt = tree.root->GetRight();
    //     if (rt == nullptr)
    //         endLoop = true;
    // }
    Iterator<T> tmp(tree);
    return tmp;
}
// ReverseIterator<T> rbegin() const noexcept;
// ReverseIterator<T> rend() const noexcept;
// ConstIterator<T> cbegin() const noexcept;
// ConstIterator<T> cend() const noexcept;
// ConstReverseIterator<T> crbegin() const noexcept;
// ConstReverseIterator<T> crend() const noexcept;
#pragma endregion It_is_conteiner

#pragma region Assignment
template <TypeForTree T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T> &tree)
{
    if (this!= &tree) {
        Clear();
        for (auto it = tree.begin(); it!= tree.end(); ++it) {
            Add(*it);
        }
    }
    return *this;
}

template <TypeForTree T>
BSTree<T>& BSTree<T>::operator=(BSTree<T> &&tree)
{
    if (this!= &tree) {
        root = tree.root;
        countNodes = tree.countNodes;
        tree.root = nullptr;
        tree.countNodes = 0;
    }
    return *this;
}

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T> &BSTree<T>::operator=(std::initializer_list<U> list)
{
    Clear();
    for (auto it = list.begin(); it!= list.end(); ++it) {
        Add(*it);
    }
    return *this;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> &BSTree<T>::operator=(const C &container)
{
    Clear();
    for (auto it = container.begin(); it!= container.end(); ++it)
        Add(*it);
    
    return *this;
}
#pragma endregion Assignment

#pragma region Informating
template <TypeForTree T>
bool BSTree<T>::IsEmpty(const BSTree<T> &tree) const noexcept
{
    return size() == 0;
}

template <TypeForTree T>
bool BSTree<T>::IsEqual(const BSTree<T> &tree) const noexcept
{
    if (size()!= tree.size()) {
        return false;
    }
    auto it1 = begin();
    auto it2 = tree.begin();
    for (; it1!= end(); ++it1, ++it2) {
        if (*it1!= *it2) {
            return false;
        }
    }
    return true;
}

template <TypeForTree T>
bool BSTree<T>::operator==(const BSTree<T> &tree) const noexcept
{
    return IsEqual(tree);
}

template <TypeForTree T>
bool BSTree<T>::operator!=(const BSTree<T> &tree) const noexcept
{
    return !IsEqual(tree);
}
#pragma endregion Informating

#pragma region Add data
template <TypeForTree T>
template <Convertable<T> U>
void BSTree<T>::Add(const U &data)
{
    auto node = BSTree<T>::NodeTree::CreateNode(data);
    add(node);
}

template <TypeForTree T>
void BSTree<T>::Add(T&& data)
{
    auto node = BSTree<T>::NodeTree::CreateNode(std::forward<T>(data));
    add(node);
}

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T> BSTree<T>::CopyAdd(const U &data) const
{
    BSTree<T> copy(*this);
    copy.Add(data);
    return copy;
}

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T>& BSTree<T>::operator+=(const U &data)
{
    Add(data);
    return *this;
}

// template <TypeForTree T>
// BSTree<T> BSTree<T>::operator+(T&& data) const
// {
//     return CopyAdd(data);
// }

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T> BSTree<T>::operator+(const U &data) const
{
    return CopyAdd(data);
}

template <TypeForTree T>
BSTree<T>& BSTree<T>::operator+=(T&& data)
{
    Add(std::forward<T>(data));
    return (*this);
}
#pragma endregion Add data

#pragma region Add container
template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
void BSTree<T>::Add(const C &container)
{
    for (auto it = container.begin(); it != container.end(); ++it) {
        auto node = BSTree<T>::NodeTree::CreateNode(*it);
        add(node);
    }
}

template <TypeForTree T>
BSTree<T> BSTree<T>::CopyAdd(BSTree<T> &&tree) const noexcept
{
    BSTree<T> copy(*this);
    copy.Add(data);
    return copy;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::CopyAdd(const C &container) const
{
    BSTree<T> copy(*this);
    copy.Add(data);
    return copy;
}

template <TypeForTree T>
BSTree<T> BSTree<T>::operator+(BSTree<T> &&tree) const noexcept
{
    return CopyAdd(std::forward<BSTree<T> >(tree));
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T>& BSTree<T>::operator+=(const C &container)
{
    Add(container);
    return (*this);
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::operator+(const C &container) const
{
    return CopyAdd(container);
}
#pragma endregion Add container

#pragma region Remove
template <TypeForTree T>
void BSTree<T>::Clear() noexcept {
    root = nullptr;
    countNodes = 0;
}

// удаление одного элемента
template <TypeForTree T>
template <Convertable<T> U>
void BSTree<T>::Remove(const U &data) noexcept
{
    T dataT = data;
    remove(dataT);
}

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T> BSTree<T>::CopyRemove(const U &data) const
{
    BSTree<T> copy(*this);
    copy.Remove(data);
    return copy;
}

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T>& BSTree<T>::operator-=(const U &data) noexcept
{
    Remove(data);
    return *this;
}

template <TypeForTree T>
template <Convertable<T> U>
BSTree<T> BSTree<T>::operator-(const U &data) const
{
    return CopyRemove(data);
}

// удаление всех элементов из контейнера
template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
void BSTree<T>::Remove(const C &container) noexcept
{
    for (auto it = container.begin(); it!= container.end(); ++it) 
    {
        T dataT = *it;
        remove(dataT);
    }
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::CopyRemove(const C &container) const
{
    BSTree<T> copy(*this);
    copy.Remove(container);
    return copy;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T>& BSTree<T>::operator-=(const C &container) noexcept
{
    Remove(container);
    return *this;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::operator-(const C &container) const
{
    return CopyRemove(container);
}
#pragma endregion Remove

#pragma region Find
template <TypeForTree T>
template <Convertable<T> U>
bool BSTree<T>::Find(const U &data) const noexcept
{
    std::shared_ptr<BSTree<T>::NodeTree> now = root;
    bool end_loop = false;
    while (now != nullptr && !end_loop)
    {
        if (data < *now->GetData())
            now = now->GetLeft();
        else if (data > *now->GetData())
            now = now->GetRight();
        else
            end_loop = true;
    }
    return now->getData();
}
#pragma endregion Find

#pragma region Intersection

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
void BSTree<T>::Intersection(const C &container) noexcept
{
    intersection(container);
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> &BSTree<T>::operator&=(const C &container) noexcept
{
    Intersection(container);
    return *this;
}


template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::IntersectionCopy(const C &container) const
{
    BSTree<T> copy(*this);
    copy.Intersection(container);
    return copy;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::operator&(const C &container) const
{
    return IntersectionCopy(container);
}
#pragma region Intersection

#pragma region Symmetric Diff

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
void BSTree<T>::SymmetricDiff(const C &container)
{
    symmetricDiff(container);
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> &BSTree<T>::operator^=(const C &container)
{
    SymmetricDiff(container);
    return *this;
}


template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::SymmetricDiffCopy(const C &container) const
{
    BSTree<T> copy(*this);
    copy.SymmetricDiff(container);
    return copy;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
BSTree<T> BSTree<T>::operator^(const C &container) const
{
    return SymmetricDiffCopy(container);
}


template <TypeForTree T>
void BSTree<T>::SymmetricDiff(BSTree<T> &&tree) noexcept
{
    recursiveSymmetricDiff(tree.root);
    tree.Clear();
}

template <TypeForTree T>
BSTree<T> &BSTree<T>::operator^=(BSTree<T> &&tree) noexcept
{
    SymmetricDiff(std::forward<BSTree<T>>(tree));
    return *this;
}

template <TypeForTree T>
BSTree<T> BSTree<T>::SymmetricDiffCopy(BSTree<T> &&tree) const noexcept
{
     BSTree<T> copy(*this);
    copy.SymmetricDiff(std::forward<BSTree<T>>(tree));
    return copy;
}

template <TypeForTree T>
BSTree<T> BSTree<T>::operator^(BSTree<T> &&tree) const noexcept
{
    return SymmetricDiffCopy(std::forward<BSTree<T>>(tree));
}
#pragma region Symmetric Diff

#pragma region Funcs_work_node
template <TypeForTree T>
void BSTree<T>::add(std::shared_ptr<BSTree<T>::NodeTree> node) 
{
    if (node->checkParant())
    {
        time_t curTime = time(NULL);
        throw AddNodeWithParantExcetion(ctime(&curTime), __FILE__, __LINE__, typeid(*this).name(), __func__);
    }

    if ( root == nullptr) 
    {
        root = node;
        countNodes++;
        return;
    }

    auto now = root;
    while (true) {
        if (*node->GetData() < *now->GetData()) {
            if (now->GetLeft() == nullptr) {
                now->SetLeft(node);
                countNodes++;
                return;
            }
            now = now->GetLeft();
        } else if (*node->GetData() > *now->GetData()) {
            if (now->GetRight() == nullptr) {
                now->SetRight(node);
                countNodes++;
                return;
            }
            now = now->GetRight();
        } else {
            return;
        }
    }
}

template <TypeForTree T>
void BSTree<T>::recursiveAdd(std::shared_ptr<typename BSTree<T>::NodeTree> _root) noexcept 
{
    if (root == nullptr)
        return;

    auto left = _root->GetLeft();
    auto right = _root->GetRight();
    _root->SetLeftNull();
    _root->SetRightNull();

    add(root);
    recursiveAdd(left);
    recursiveAdd(right);
}


// template <TypeForTree T>
// std::shared_ptr<typename BSTree<T>::NodeTree> BSTree<T>::find(const T &data) const noexcept 
// {
//     auto now =  root;
//     bool end_loop = false;
//     while (now != nullptr && !end_loop)
//     {
//         if (data < *now->GetData())
//             now = now->GetLeft();
//         else if (data > *now->GetData())
//             now = now->GetRight();
//         else
//             end_loop = true;
//     }
//     return now;
// }

template <TypeForTree T>
std::shared_ptr<typename BSTree<T>::NodeTree> BSTree<T>::remove(const T &data) noexcept 
{
    auto now =  root;
    bool end_loop = false;
    while (!end_loop && now != nullptr && *now->GetData() != data) 
    {
        if (now->GetLeft() != nullptr && *now->GetLeft()->GetData() == data) 
        {
            auto tmp = now->GetLeft();
            now->SetLeftNull();
            now = tmp;
            end_loop = true;
        } else if (now->GetRight() != nullptr && *now->GetRight()->GetData() == data) 
        {
            auto tmp = now->GetRight();
            now->SetRightNull();
            now = tmp;
            end_loop = true;
        }

        if (!end_loop)
        {
            if (data < *now->GetData())
                now = now->GetLeft();
            else
                now = now->GetRight();
        }
        
    }
    if (now == nullptr)
        return now;

    auto left = now->GetLeft();
    auto right = now->GetRight();
    now->SetLeftNull();
    now->SetRightNull();
    if (now ==  root)
         root = nullptr;
    
    countNodes--;
    if (left != nullptr)
    {
        countNodes--;
        add(left);
    }
    
    if (right != nullptr)
    {
        countNodes--;
        add(right);
    }
    
    return now;
}

template <TypeForTree T>
void BSTree<T>::SetNewRoot(std::shared_ptr<typename BSTree<T>::NodeTree> node) noexcept
{
    root.reset();
    root = node;
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> Con>
void BSTree<T>::intersection(const Con &container) noexcept 
{
    BSTree<T> tmp;
    std::cout << "BSTree<T>::intersection" << std::endl;
    for (auto it = container.begin(); it!= container.end(); ++it) 
    {
        std::cout << "1" << std::endl;
        auto node = remove(*it);
        if (node!= nullptr)
            tmp.add(node);
    }
    *this = std::move(tmp);
}

template <TypeForTree T>
template <ContainerConvertableAssignable<T> C>
void BSTree<T>::symmetricDiff(const C &container) 
{
    BSTree<T> tmp;
    for (auto it = container.begin(); it!= container.end(); ++it) 
    {
        auto node = remove(*it);
        if (node == nullptr)
            tmp.Add(*it);
    }
    tmp.recursiveAdd( root);
    Clear();
    *this = std::move(tmp);
}

template <TypeForTree T>
void BSTree<T>::recursiveSymmetricDiff(std::shared_ptr<NodeTree> _root) 
{
    if (root == nullptr)
        return;

    auto left = _root->GetLeft();
    auto right = _root->GetRight();
    _root->SetLeftNull();
    _root->SetRigthNull();
    if (remove(*root->GetData()) == nullptr)
        add(root);

    recursiveSymmetricDiff(left);
    recursiveSymmetricDiff(right);
}
#pragma endregion Funcs_work_node