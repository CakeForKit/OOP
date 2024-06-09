#include "Link.h"


Link::Link(size_t first, size_t second) : _first(first), _second(second) {};

size_t Link::GetFirst() const { return _first; }

size_t Link::GetSecond() const { return _second; }

void Link::SetFirst(size_t first) { _first = first; }

void Link::SetSecond(size_t second) { _second = second; }

void Link::Set(size_t first, size_t second) { _first = first; _second = second; }

void Link::Set(const Link& other) { _first = other._first; _second = other._second; }

bool Link::IsEqual(const Link& other) const {
    return (_first == other._first && _second == other._second) || (_first == other._second && _second == other._first);
}

bool Link::operator==(const Link& other) const { return IsEqual(other); }

bool Link::IsNotEqual(const Link &other) const { return !IsEqual(other); }

bool Link::operator!=(const Link& other) const { return IsNotEqual(other); }


