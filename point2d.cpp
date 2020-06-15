#include "point2d.h"

Point2D::Point2D()
{

}

Point2D::Point2D(double _x, double _y): xcoord(_x), ycoord(_y)
{

}

double Point2D::scalarProd(const Point2D &v2) const
{
    double res = this->x()*v2.x() + this->y()*v2.y();
    return res;
}

Point2D Point2D::getNormalP()
{
    double eps = 1.0e-5;
    double px = this->x();
    double py = this->y();

    double a = 0;
    double b = 0;

    if(fabs(px) < eps)
    {
        a = 1.0;
        b = 0.0;
    }
    else if(fabs(py) < eps)
    {
        a = 0.0;
        b = 1.0;
    }
    else
    {
        a = 1.0;
        b = -px/py;
    }

    Point2D res(a, b);
    return res;

}

const Point2D operator+(const Point2D &v1, const Point2D &v2)
{
    return Point2D(v1.x() + v2.x(), v1.y() + v2.y());
}

const Point2D operator-(const Point2D &v1, const Point2D &v2)
{
    return Point2D(v1.x() - v2.x(), v1.y() - v2.y());
}

Point2D& operator+=(Point2D &v1, const Point2D &v2)
{
    v1.setX(v1.x() + v2.x());
    v1.setY(v1.y() + v2.y());

    return v1;
}

Point2D& operator-=(Point2D &v1, const Point2D &v2)
{
    v1.setX(v1.x() - v2.x());
    v1.setY(v1.y() - v2.y());

    return v1;
}

const Point2D& operator*(double a, Point2D &v)
{
    v.setX(a*v.x());
    v.setY(a*v.y());
    return v;
}

const Point2D& operator*(Point2D &v, double a)
{
    v.setX(a*v.x());
    v.setY(a*v.y());
    return v;
}

const Point2D& operator/(Point2D &v, double a)
{
    if(fabs(a) < std::numeric_limits<double>::epsilon())
    {
        return v;
    }
    else
    {
        v.setX(v.x()/a);
        v.setY(v.y()/a);
        return v;
    }
}

const Point2D& operator+(const Point2D &v)
{
    return v;
}

const Point2D operator-(const Point2D &v)
{
    return Point2D(-v.x(), -v.y());
}

void Point2D::rotateZ(const Point2D &zero, double azimut)
{
    Point2D v = *this - zero;
    double xnew = v.x()*cos(azimut) - v.y()*sin(azimut);
    double ynew = v.x()*sin(azimut) + v.y()*cos(azimut);
    this->setX(xnew);
    this->setY(ynew);
}

double Point2D::length() const
{
    double res = pow(xcoord, 2.0) + pow(ycoord, 2.0);
    res = sqrt(res);
    return res;
}

