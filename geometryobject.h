#ifndef GEOMETRYOBJECT_H
#define GEOMETRYOBJECT_H

#include <QColor>

#include "point2d.h"
#include "geomsettings.h"

// Base class for geometry objects
class GeometryObject
{
public:
    enum ObjectTypes{Square, Rectangle, Triangle, Circle};

    GeometryObject();

    virtual ~GeometryObject();

    //Method for get coordinates of points, which describe polygon of figure
    virtual std::vector<Point2D> getCoordinates() = 0;

    //Method to update geom settings (we have some diference in child classes
    //So, to correctly connect GUI we have virtual set, which pass a structure of all settings
    virtual void updateGeomSettings(const GeomSettings &newSett) = 0;

    //get geom settings (overall setting for each child)
    virtual GeomSettings getGeomSettings() = 0;

    //method changes color of figure
    inline void changeColor(const QColor &newColor)
    {
        color = newColor;
    }

    //method set center of figure
    inline void setCenter(const Point2D &newCenter)
    {
        center = newCenter;
    }

    //get center method
    inline const Point2D &getCenter()
    {
        return center;
    }

    //setting scale (0 to 1)
    inline void setScale(double newScale)
    {
        scale = newScale;
    }

    //get geometry type
    inline ObjectTypes getCurrentType()
    {
        return  curType;
    }

    //set cur type
    inline void setCurType(const ObjectTypes &mCurType)
    {
        curType = mCurType;
    }

    //get color of figure
    inline const QColor &getCurColor()
    {
        return color;
    }


protected:
    //object center
    Point2D center;

    //object color
    QColor color = QColor(0, 255, 0);

    //object scale
    double scale = 0.5;

    //type of object
    ObjectTypes curType;

};

#endif // GEOMETRYOBJECT_H
