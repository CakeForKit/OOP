#pragma once

#include "MatrixImpl.hpp"

class Dot
{
public:
    Dot() = default;
    Dot(const double x, const double y, const double z);

    Dot(const Dot &dot) = default;
    Dot(const Dot &&dot) noexcept;

    Dot &operator=(const Dot &dot) = default;
    Dot &operator=(Dot &&dot) noexcept;

    ~Dot() = default;

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double const x);
    void setY(double const y);
    void setZ(double const z);

    bool operator==(const Dot &dot) const noexcept;
    bool isEqual(const Dot &dot) const noexcept;

    bool operator!=(const Dot &dot) const noexcept;
    bool isNotEqual(const Dot &dot) const noexcept;

    Dot operator+(const Dot &dot)  const;
    Dot operator-(const Dot &dot)  const;

    Dot getAbsDot(const Dot &center);

    Dot getCenter() const;
    void transform(const Matrix<double> &mtr);

private:
    double _x;
    double _y;
    double _z;
};

