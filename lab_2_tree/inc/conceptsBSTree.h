#pragma once 

#include <concepts>
using namespace std;


template <typename From, typename To>
concept Convertable = convertible_to<From, To>; // && TypeForMatrix<To>;

template <typename From, typename To>
concept Assignable = requires(From fm, To t)
{
    t = fm;
};

template <typename T>
concept Copyable = requires(T &t)
{
    T(t);
};

template <typename T>
concept Moveable = requires(T &&t)
{
    T(t);
};

template <typename T>
concept Comparable = requires(T a, T b)
{
    {a < b} -> convertible_to<bool>;
    {a > b} -> convertible_to<bool>;
    {a <= b} -> convertible_to<bool>;
    {a >= b} -> convertible_to<bool>;
    {a == b} -> convertible_to<bool>;
    {a != b} -> convertible_to<bool>;
};


// Концепт для типов которые может содержать деревом
// с этим типом можно выполнять те же операции что с деревом
template <typename T>
concept TypeForTree = Comparable<T> && Assignable<T, T> && 
    Copyable<T> && Moveable<T>;


template <typename container>  
concept Container = requires(container con)
{
    typename container::value_type;
    typename container::size_type;
    typename container::iterator;
    // typename container::const_iterator;

    { con.size() } noexcept -> same_as<typename container::size_type>;
    { con.end() } noexcept -> same_as<typename container::iterator>;
    { con.begin() } noexcept -> same_as<typename container::iterator>;
    // { con.rend() } noexcept -> same_as<typename C::reverse_iterator>;
    // { con.rbegin() } noexcept -> same_as<typename C::reverse_iterator>;
    // { con.cend() } noexcept -> same_as<typename C::const_iterator>;
    // { con.cbegin() } noexcept -> same_as<typename C::const_iterator>;
};

template <typename Con, typename T>
concept ContainerConvertableAssignable = Container<Con> && 
                        Convertable<typename Con::value_type, T> &&
                        Assignable<typename Con::value_type, T>; // && RandomAccessIterator<typename Con::iterator>;




