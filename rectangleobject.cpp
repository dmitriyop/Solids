#include "rectangleobject.h"

RectangleObject::RectangleObject(): GeometryObject()
{
    curType = Rectangle;
    color = QColor(255, 0, 0);
}

RectangleObject::~RectangleObject()
{

}

std::vector<Point2D> RectangleObject::getCoordinates()
{
    std::vector<Point2D> res(4);
    double ax = xInitSize*scale*(1.0 - scale2);
    double ay = yInitSize*scale*scale2;

    res[0] = center + Point2D(ax, ay);
    res[1] = center + Point2D(-ax, ay);
    res[2] = center + Point2D(-ax, -ay);
    res[3] = center + Point2D(ax, -ay);
    return res;
}

void RectangleObject::updateGeomSettings(const GeomSettings &newSett)
{
    scale = newSett.size1;
    scale2 = newSett.size2;
}

GeomSettings RectangleObject::getGeomSettings()
{
    GeomSettings res;
    res.size1 = scale;
    res.size2 = scale2;
    return res;
}

