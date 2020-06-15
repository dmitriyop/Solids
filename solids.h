#ifndef SOLIDS_H
#define SOLIDS_H

#include <QTreeWidget>
#include <map>

#include "mainwindow.h"
#include "squareobject.h"
#include "rectangleobject.h"
#include "triangularobject.h"
#include "circleobject.h"


//Main class, which stores all gui and objects
class Solids: public QObject
{
    Q_OBJECT
public:
    Solids(QObject *parent = nullptr);

    //method initializes main window
    void showMainWIndow();

    //method initialize conection between settings and geometry View
    void initializeConnections();

public slots:
    //figure changed method
    void handleObjectChanged(int nObject);

    //method for get figure color by id
    void handleGetObjectColor(int nObject);

    //method for change figure color in base
    void handleChangeObjectColor(int nObject, QColor newColor);

    //method which change center of figure
    void handleNewObjectCenter(int nObject, Point2D newCcoord);

    //methid which changes geometry settings of figure
    void handleSizeChanged(int nObj, GeomSettings newSett);

    //method ehich get geometry settings of figure by id
    //need if we switch to another figure
    void handleGetCurrentObjSett(int nObj);
signals:
    void sendCurObjColor(int nObject, QColor objColor);
    void sendObjData(const Point2D& curCenter, const GeomSettings &curGsett);
private:

    //pointer to main window
    MainWindow *mw;

    //pointer to objects tree
    QTreeWidget *objectsTree;

    //pointer to view
    View *viewWidget;

    //map of all objects
    std::map<int, std::shared_ptr<GeometryObject> > allObjects;

};

#endif // SOLIDS_H
