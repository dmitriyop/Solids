#ifndef POINT2D_H
#define POINT2D_H

#include <algorithm>
#include <math.h>
#include <vector>

//Point in 2D class
class Point2D
{
public:
    Point2D();
    Point2D(double _x, double _y);

    double scalarProd(const Point2D &v2) const;

    inline double x() const
    {
        return xcoord;
    }

    inline double y() const
    {
        return ycoord;
    }

    inline void setX(double _x)
    {
        xcoord = _x;
    }

    inline void setY(double _y)
    {
        ycoord = _y;
    }

    friend const Point2D operator+(const Point2D &v1, const Point2D &v2);

    friend const Point2D operator-(const Point2D &v1, const Point2D &v2);

    friend Point2D& operator+=(Point2D &v1, const Point2D &v2);

    friend Point2D& operator-=(Point2D &v1, const Point2D &v2);

    Point2D& operator=(const Point2D &right)
    {
        if(this == &right)
        {
            return *this;
        }

        this->setX(right.x());
        this->setY(right.y());
        return *this;
    }

    Point2D getNormalP();

    friend const Point2D& operator*(double a, Point2D &v);

    friend const Point2D& operator*(Point2D &v, double a);

    friend const Point2D& operator/(Point2D &v, double a);

    friend const Point2D& operator+(const Point2D &v);

    friend const Point2D operator-(const Point2D &v);

    void rotateZ(const Point2D &zero, double azimut);

    double length() const;


private:
    double xcoord = 0;
    double ycoord = 0;
};


#endif // POINT_H
