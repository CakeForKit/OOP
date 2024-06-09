#pragma once
#include "Point.h"
#include <vector>


class BaseCenterStrategy {
    public:
        BaseCenterStrategy() = default;

        virtual ~BaseCenterStrategy() = 0;
        virtual Point CenterAlgorithm(std::vector<Point> points) const = 0;
};

class CenterStrategy : public BaseCenterStrategy {
    public:
        CenterStrategy() = default;

        virtual ~CenterStrategy() = default;
        virtual Point CenterAlgorithm(std::vector<Point> points) const;

};