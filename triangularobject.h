#ifndef TRIANGULAROBJECT_H
#define TRIANGULAROBJECT_H

#include "geometryobject.h"

class TriangularObject: public GeometryObject
{
public:
    TriangularObject();
    ~TriangularObject();
    std::vector<Point2D> getCoordinates();
    void updateGeomSettings(const GeomSettings &newSett);

    GeomSettings getGeomSettings();
private:
    double initSize = 0.5;
};

#endif // TRIANGULAROBJECT_H
