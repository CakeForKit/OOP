#include <cmath>

#include "Dot.h"

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

Dot::Dot(const double x, const double y, const double z)
{
    setX(x);
    setY(y);
    setZ(z);
}


Dot::Dot(const Dot &&dot) noexcept
{
    setX(dot._x);
    setY(dot._y);
    setZ(dot._z);

    dot.~Dot();
}


Dot &Dot::operator=(Dot &&dot) noexcept
{
    setX(dot._x);
    setY(dot._y);
    setZ(dot._z);

    dot.~Dot();

    return *this;
}

double Dot::getX() const
{
    return _x;
}

double Dot::getY() const
{
    return _y;
}

double Dot::getZ() const
{
    return _z;
}

void Dot::setX(const double x)
{
    _x = x;
}

void Dot::setY(const double y)
{
    _y = y;
}

void Dot::setZ(const double z)
{
    _z = z;
}

bool Dot::operator==(const Dot &dot) const noexcept
{
    return (dot._x == _x) && (dot._y == _y) && (dot._z == _z);
}

bool Dot::isEqual(const Dot &dot) const noexcept
{
    return *this == dot;
}

bool Dot::operator!=(const Dot &dot) const noexcept
{
    return !(*this == dot);
}

bool Dot::isNotEqual(const Dot &dot) const noexcept
{
    return !(*this == dot);
}

Dot Dot::operator+(const Dot &dot) const
{
    Dot d{*this};

    d.setX(d._x + dot._x);
    d.setY(d._y + dot._y);
    d.setZ(d._z + dot._z);

    return d;
}

Dot Dot::operator-(const Dot &dot) const
{
    Dot d{*this};

    d.setX(d._x - dot._x);
    d.setY(d._y - dot._y);
    d.setZ(d._z - dot._z);

    return d;
}


void Dot::transform(const Matrix<double> &mtr)
{
    Matrix<double> cur_location = {{_x, _y, _z, 1}};
    Matrix<double> new_location = cur_location * mtr;

    _x = new_location[0][0];
    _y = new_location[0][1];
    _z = new_location[0][2];
}

Dot Dot::getCenter() const
{
    return *this;
}

Dot Dot::getAbsDot(const Dot &center)
{
    return (*this) + center;
}
