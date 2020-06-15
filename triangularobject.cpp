#include "triangularobject.h"

TriangularObject::TriangularObject(): GeometryObject ()
{
    curType = Triangle;
    color = QColor(0, 0, 255);
}

TriangularObject::~TriangularObject()
{

}

std::vector<Point2D> TriangularObject::getCoordinates()
{
    std::vector<Point2D> res(3);
    double a = initSize*scale;
    double medLength = sqrt(3.0)/2.0*a;

    res[0] = center + Point2D(0, (2.0/3.0*medLength));
    res[1] = center + Point2D(-a/2.0, (-1.0/3.0*medLength));
    res[2] = center + Point2D(a/2.0, (-1.0/3.0*medLength));

    return res;
}

void TriangularObject::updateGeomSettings(const GeomSettings &newSett)
{
    scale = newSett.size1;
}

GeomSettings TriangularObject::getGeomSettings()
{
    GeomSettings res;
    res.size1 = scale;
    return res;
}
