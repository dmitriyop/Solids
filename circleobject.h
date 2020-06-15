#ifndef CIRCLEOBJECT_H
#define CIRCLEOBJECT_H

#include "geometryobject.h"

class CircleObject: public GeometryObject
{
public:
    CircleObject();
    ~CircleObject();
    std::vector<Point2D> getCoordinates();
    void updateGeomSettings(const GeomSettings &newSett);


    inline void setInitDiam(double mDiam)
    {
        initDiam = mDiam;
    }

    inline void setNPoints(std::size_t mnPoints)
    {
        nPoints = mnPoints;
    }
    GeomSettings getGeomSettings();
private:
    double initDiam = 0.5;
    std::size_t nPoints = 50;
};

#endif // CIRCLEOBJECT_H
