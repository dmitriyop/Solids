#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QGLWidget>
#include <QVector4D>
#include <memory>

#include "geometryobject.h"


//class for objects view
class View : public QGLWidget
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);

    ~View();

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

public slots:
    void changeCurObject(std::shared_ptr<GeometryObject> newObject);
private:
    //current object in View data
    std::shared_ptr<GeometryObject> curObjectData;

    //backGround
    QVector4D colorBackground = QVector4D(0.2, 0.2, 0.23, 1);


};

#endif // VIEW_H
