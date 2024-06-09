#pragma once
#include <cstddef>

class Link {
    public:
        Link() = default;
        Link(size_t first, size_t second);
        explicit Link(const Link& other) = default;
        Link(Link&& other) = default;

        Link& operator=(const Link& other) = default;
        Link& operator=(Link&& other) = default;

        size_t GetFirst() const;
        size_t GetSecond() const;
        void SetFirst(size_t first);
        void SetSecond(size_t second);
        void Set(const Link& other);
        void Set(size_t first, size_t second);

        bool operator==(const Link& other) const;
        bool operator!=(const Link& other) const;
        bool IsEqual(const Link& other) const;
        bool IsNotEqual(const Link& other) const;

    private:
        size_t _first;
        size_t _second;
};