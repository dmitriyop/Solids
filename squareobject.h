#ifndef SQUAREOBJECT_H
#define SQUAREOBJECT_H

#include "geometryobject.h"

class SquareObject: public GeometryObject
{
public:
    SquareObject();
    ~SquareObject();

    std::vector<Point2D> getCoordinates();

    void updateGeomSettings(const GeomSettings &newSett);

    GeomSettings getGeomSettings();

    inline void setInitialSize(double mInitSize)
    {
        initialSize = mInitSize;
    }

    inline double getInitialSize()
    {
        return initialSize;
    }
private:
    double initialSize = 0.5;
};

#endif // SQUAREOBJECT_H
