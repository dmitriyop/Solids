#include "squareobject.h"

SquareObject::SquareObject(): GeometryObject ()
{
    curType = Square;
    color = QColor(0, 255, 0);
}

SquareObject::~SquareObject()
{

}

std::vector<Point2D> SquareObject::getCoordinates()
{
    std::vector<Point2D> res(4);
    double curSize = initialSize*scale*0.5;
    res[0] = center + Point2D(curSize, curSize);
    res[1] = center + Point2D(-curSize, curSize);
    res[2] = center + Point2D(-curSize, -curSize);
    res[3] = center + Point2D(curSize, -curSize);

    return  res;
}

void SquareObject::updateGeomSettings(const GeomSettings &newSett)
{
    scale = newSett.size1;
}

GeomSettings SquareObject::getGeomSettings()
{
    GeomSettings res;
    res.size1 = scale;
    return res;
}
