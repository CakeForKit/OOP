#pragma once

#include "CarcasModelImpl.h"
#include <vector>
#include "Dot.h"
#include "Link.h"

class CarcasModelOfDotsLinks : public CarcasModelImpl
{
public:
    CarcasModelOfDotsLinks() = default;
    CarcasModelOfDotsLinks(std::vector<Dot> &dotes, std::vector<Link> &links);
    CarcasModelOfDotsLinks(std::vector<Dot> &dotes, std::vector<Link> &links, Dot &center);

    ~CarcasModelOfDotsLinks() override = default;

    const std::vector<Dot> &getDotes() const;
    const std::vector<Link> &getLinks() const;
    const Dot getCenter() const;

    void addDot(const Dot &dot);
    void addLink(const Link &link);
    void updateCenter();

    void moveDotesToOrigin(const Dot &center);
    void moveDotesToCenter(const Dot &center);
    void transformDotes(const Matrix<double> &mtr);
    void transform(const Matrix<double> &mtr, const Dot &center);

private:
    Dot _center;

    std::vector<Dot> _dotes;
    std::vector<Link> _links;
};