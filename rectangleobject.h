#ifndef RECTANGLEOBJECT_H
#define RECTANGLEOBJECT_H

#include "geometryobject.h"

class RectangleObject: public GeometryObject
{
public:
    RectangleObject();
    ~RectangleObject();
    std::vector<Point2D> getCoordinates();
    void updateGeomSettings(const GeomSettings &newSett);
    GeomSettings getGeomSettings();
private:
    double xInitSize = 1.0;
    double yInitSize = 0.5;

    double scale2 = 0.5;
};

#endif // RECTANGLEOBJECT_H
