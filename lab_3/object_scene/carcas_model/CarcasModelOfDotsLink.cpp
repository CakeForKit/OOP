#include "CarcasModelOfDotsLink.h"

CarcasModelOfDotsLinks::CarcasModelOfDotsLinks(std::vector<Dot> &dotes, std::vector<Link> &links) :
    _center{ }, _dotes(dotes), _links(links) { }


CarcasModelOfDotsLinks::CarcasModelOfDotsLinks(std::vector<Dot> &dotes, std::vector<Link> &links,
                               Dot &center):
    _center(center), _dotes(dotes), _links(links) { }

const std::vector<Dot> &CarcasModelOfDotsLinks::getDotes() const
{
    return _dotes;
}

const std::vector<Link> &CarcasModelOfDotsLinks::getLinks() const
{
    return _links;
}

const Dot CarcasModelOfDotsLinks::getCenter() const
{
    return _center;
}

void CarcasModelOfDotsLinks::addDot(const Dot &dot)
{
    _dotes.push_back(dot);
    updateCenter();
}

void CarcasModelOfDotsLinks::addLink(const Link &link)
{
    _links.push_back(link);
}

void CarcasModelOfDotsLinks::updateCenter()
{
    _center = Dot(0, 0, 0);
    size_t count = 0;

    for (const auto &element : _dotes)
    {
        _center = _center + element.getCenter();
        count++;
    }

    _center = Dot(_center.getX() / count,
                     _center.getY() / count,
                     _center.getZ() / count);
}

void CarcasModelOfDotsLinks::moveDotesToOrigin(const Dot &center)
{
    Dot diff = Dot(0, 0, 0) - center;

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformDotes(mtr);
    updateCenter();
}

void CarcasModelOfDotsLinks::moveDotesToCenter(const Dot &center)
{
    Dot diff = center - Dot(0, 0, 0);

    Matrix<double> mtr = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformDotes(mtr);
    updateCenter();
}

void CarcasModelOfDotsLinks::transformDotes(const Matrix<double> &mtr)
{
    for (auto &dot : _dotes)
        dot.transform(mtr);
}

void CarcasModelOfDotsLinks::transform(const Matrix<double> &mtr, const Dot &center)
{
    updateCenter();

    moveDotesToOrigin(center);
    transformDotes(mtr);
    moveDotesToCenter(center);
}
