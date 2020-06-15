#include "circleobject.h"

CircleObject::CircleObject(): GeometryObject ()
{
    curType = Circle;
    color = QColor(180, 54, 190);
}

CircleObject::~CircleObject()
{

}

std::vector<Point2D> CircleObject::getCoordinates()
{
    std::vector<Point2D> res(nPoints);
    if(nPoints < 5)
    {
        return res;
    }

    double alpha = 0;
    double x = 0;
    double y = 0;
    for(std::size_t i = 0; i < nPoints; ++i)
    {
        alpha = 2.0*3.1415*static_cast<double>(i)/static_cast<double>(nPoints);
        x = center.x() + initDiam*scale/2.0*cos(alpha);
        y = center.y() + initDiam*scale/2.0*sin(alpha);
        res[i] = Point2D(x, y);
    }
    return  res;
}

void CircleObject::updateGeomSettings(const GeomSettings &newSett)
{
    scale = newSett.size1;

}

GeomSettings CircleObject::getGeomSettings()
{
    GeomSettings res;
    res.size1 = scale;
    return res;
}


