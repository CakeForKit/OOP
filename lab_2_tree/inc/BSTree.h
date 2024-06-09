#pragma once

#include <initializer_list>
#include "conceptsBSTree.h"
#include "BaseBSTree.h"
#include "Exceptions.h"
#include "Iterator.hpp"

// #include "iter"

template <TypeForTree T>
class BSTree : public BaseBSTree
{
    friend class Iterator<T>;
    friend class BaseIterator<T>;
public:
    ~BSTree() override = default;

    #pragma region Constructors
    BSTree() noexcept;
    explicit BSTree(const BSTree<T> &tree);
    BSTree(BSTree<T> &&tree) noexcept;
    BSTree(std::initializer_list<T> lst);

    // с преобразованием
    template <Convertable<T> U> // from U to T
    explicit BSTree(const BSTree<U> &tree);
    template <Convertable<T> U> 
    BSTree(std::initializer_list<U> lst);

    // из контейнера
    template <ContainerConvertableAssignable<T> U>  
    explicit BSTree(const U& con);

    // из input итератора
    template <std::input_iterator Iter>
    BSTree(const Iter &begin, const Iter &end);

    #pragma endregion Constructors

    #pragma region It_is_conteiner
    // using size_type = size_t; --> BaseBSTree
    // size_t size() const noexcept; --> BaseBSTree
    using value_type = T;
    using iterator = Iterator<T>;
    // using const_iterator = ConstIterator<T>;
    // using reverse_iterator = ReverseIterator<T>;
    // using const_reverse_iterator = ConstReverseIterator<T>;

    Iterator<T> begin() const noexcept;
	Iterator<T> end() const noexcept;
	// ReverseIterator<T> rbegin() const noexcept;
	// ReverseIterator<T> rend() const noexcept;
    // ConstIterator<T> cbegin() const noexcept;
	// ConstIterator<T> cend() const noexcept;
    // ConstReverseIterator<T> crbegin() const noexcept;
	// ConstReverseIterator<T> crend() const noexcept;
    #pragma endregion It_is_conteiner

    #pragma region Assignment
    BSTree<T>& operator=(const BSTree<T> &tree);
    BSTree<T>& operator=(BSTree<T> &&tree);

    template <Convertable<T> U>
    BSTree<T> &operator=(std::initializer_list<U> list);

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> &operator=(const C &container);
    #pragma endregion Assignment

    #pragma region Informating
    bool IsEmpty(const BSTree<T> &tree) const noexcept;
    bool IsEqual(const BSTree<T> &bstree) const noexcept;
    bool operator==(const BSTree<T> &bstree) const noexcept;
    bool operator!=(const BSTree<T> &bstree) const noexcept;
    #pragma endregion Informating


    #pragma region Add data
    template <Convertable<T> U>
    void Add(const U &data);
    void Add(T&& data);
    template <Convertable<T> U>
    BSTree<T> CopyAdd(const U &data) const;

    template <Convertable<T> U>
    BSTree<T> operator+(const U &data) const;
    BSTree<T>& operator+=(T&& data);

    template <Convertable<T> U>
    BSTree<T>& operator+=(const U &data);
    #pragma endregion Add data

    #pragma region Add container
    template <ContainerConvertableAssignable<T> C>
    void Add(const C &container);

    BSTree<T> CopyAdd(BSTree<T> &&bstree) const noexcept;

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> CopyAdd(const C &container) const;
    
    BSTree<T> operator+(BSTree<T> &&bstree) const noexcept;

    template <ContainerConvertableAssignable<T> C>
    BSTree<T>& operator+=(const C &container);

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> operator+(const C &container) const;
    #pragma endregion Add container

    #pragma region Remove
    void Clear() noexcept;

    // удаление одного элемента
    template <Convertable<T> U>
    void Remove(const U &data) noexcept;
    template <Convertable<T> U>
    BSTree<T> CopyRemove(const U &data) const;

    template <Convertable<T> U>
    BSTree<T>& operator-=(const U &data) noexcept;
    template <Convertable<T> U>
    BSTree<T> operator-(const U &data) const;

    // вычитание контейнера
    template <ContainerConvertableAssignable<T> C>
    void Remove(const C &container) noexcept;
    template <ContainerConvertableAssignable<T> C>
    BSTree<T> CopyRemove(const C &container) const;

    template <ContainerConvertableAssignable<T> C>
    BSTree<T>& operator-=(const C &container) noexcept;
    template <ContainerConvertableAssignable<T> C>
    BSTree<T> operator-(const C &container) const;
    #pragma endregion Remove

    #pragma region Find
    template <Convertable<T> U>
    bool Find(const U &data) const noexcept;
    #pragma endregion Find

    #pragma region Intersection
    template <ContainerConvertableAssignable<T> C>
    void Intersection(const C &container) noexcept;
    template <ContainerConvertableAssignable<T> C>
    BSTree<T> IntersectionCopy(const C &container) const;

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> &operator&=(const C &container) noexcept;
    template <ContainerConvertableAssignable<T> C>
    BSTree<T> operator&(const C &container) const;
    #pragma region Intersection

    #pragma region Symmetric Diff
    template <ContainerConvertableAssignable<T> C>
    void SymmetricDiff(const C &container);
    void SymmetricDiff(BSTree<T> &&bstree) noexcept;    // TODO

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> SymmetricDiffCopy(const C &container) const;
    BSTree<T> SymmetricDiffCopy(BSTree<T> &&bstree) const noexcept;

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> &operator^=(const C &container);
    BSTree<T> &operator^=(BSTree<T> &&bstree) noexcept;

    template <ContainerConvertableAssignable<T> C>
    BSTree<T> operator^(const C &container) const;
    BSTree<T> operator^(BSTree<T> &&bstree) const noexcept;
    #pragma region Symmetric Diff


protected:
    #pragma region NodeTree
    class NodeTree : public std::enable_shared_from_this<NodeTree>
    {
    public:
        ~NodeTree() = default;

        template <typename... Args>
        static std::shared_ptr<NodeTree> CreateNode(Args&&... params);

        void SetData(const T &data) noexcept;
        void SetParant(const std::shared_ptr<NodeTree> node) noexcept;
        void SetLeft(const std::shared_ptr<NodeTree> node) noexcept;
        void SetRight(const std::shared_ptr<NodeTree> node) noexcept;
        
        bool checkParant() noexcept;
        bool operator ==(const std::shared_ptr<NodeTree> node) noexcept;
        static int type_node_of_parant(const std::shared_ptr<NodeTree> node); // return -1 - left, 1 - right, 0 - parant == nullptr, else raise error

        void SetLeftNull() noexcept;
        void SetRightNull() noexcept;

        std::shared_ptr<T> GetData() noexcept;
        std::weak_ptr<NodeTree> GetParant() noexcept;
        std::shared_ptr<NodeTree> GetLeft() noexcept;
        std::shared_ptr<NodeTree> GetRight() noexcept;

        NodeTree() = delete;
        NodeTree(const NodeTree&) = delete;
        NodeTree(const NodeTree&&) = delete;
    
    protected:
        NodeTree(const T &data);
        NodeTree(T&& data);

    private:
        T data;
        std::weak_ptr<NodeTree> parant;
        std::shared_ptr<NodeTree> left;
        std::shared_ptr<NodeTree> right;
    };
    #pragma endregion NodeTree

protected:

    #pragma region Funcs_work_node
    void add(std::shared_ptr<NodeTree> node);
    void recursiveAdd(std::shared_ptr<NodeTree> root) noexcept;
    std::shared_ptr<NodeTree> remove(const T &data) noexcept;
    void SetNewRoot(std::shared_ptr<NodeTree> node) noexcept;

    template <ContainerConvertableAssignable<T> Con>
    void intersection(const Con &container) noexcept;

    template <ContainerConvertableAssignable<T> Con>
    void symmetricDiff(const Con &container);
    
    void recursiveSymmetricDiff(std::shared_ptr<NodeTree> root);
    #pragma endregion Funcs_work_node

private:
    std::shared_ptr<NodeTree> root;
};


// TODO a + b  b + a


#include "BSTreeNode.hpp"
