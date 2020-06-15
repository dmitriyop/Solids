#include "solids.h"

Solids::Solids(QObject *parent): QObject(parent)
{
    mw = new MainWindow();

    allObjects[0] = std::make_shared<SquareObject>();
    allObjects[1] = std::make_shared<RectangleObject>();
    allObjects[2] = std::make_shared<TriangularObject>();
    allObjects[3] = std::make_shared<CircleObject>();

    objectsTree = mw->getObjectsTreePointer();
    viewWidget = mw->getViewPointer();

    initializeConnections();
}

void Solids::showMainWIndow()
{

    viewWidget->changeCurObject(allObjects[0]);

    mw->showMaximized();
    mw->show();
}

void Solids::initializeConnections()
{
    connect(mw, &MainWindow::objectChanged, this, &Solids::handleObjectChanged);
    connect(mw, &MainWindow::requestCurObjColor, this, &Solids::handleGetObjectColor);
    connect(this, &Solids::sendCurObjColor, mw, &MainWindow::hanleCurObjColor);
    connect(mw, &MainWindow::changeCurObjColor, this, &Solids::handleChangeObjectColor);
    qRegisterMetaType<Point2D>("Point2D");
    connect(mw, &MainWindow::changeCurObjCenter, this, &Solids::handleNewObjectCenter);
    qRegisterMetaType<GeomSettings>("GeomSettings");
    connect(mw, &MainWindow::sizeChanged, this, &Solids::handleSizeChanged);
    connect(mw, &MainWindow::requestCurObjSett, this, &Solids::handleGetCurrentObjSett);
    connect(this, &Solids::sendObjData, mw, &MainWindow::handleCurObjSett);
}

void Solids::handleObjectChanged(int nObject)
{
    if(allObjects.count(nObject) == 0)
    {
        return;
    }

    std::shared_ptr<GeometryObject> curObj = allObjects.at(nObject);

    viewWidget->changeCurObject(curObj);
}

void Solids::handleGetObjectColor(int nObject)
{
    if(allObjects.count(nObject) == 0)
    {
        return;
    }

    QColor curObjColor = allObjects.at(nObject)->getCurColor();

    emit sendCurObjColor(nObject, curObjColor);
}

void Solids::handleChangeObjectColor(int nObject, QColor newColor)
{
    if(allObjects.count(nObject) == 0)
    {
        return;
    }

    allObjects.at(nObject)->changeColor(newColor);

    viewWidget->changeCurObject(allObjects.at(nObject));
}

void Solids::handleNewObjectCenter(int nObject, Point2D newCcoord)
{
    if(allObjects.count(nObject) == 0)
    {
        return;
    }

    allObjects.at(nObject)->setCenter(newCcoord);

    viewWidget->changeCurObject(allObjects.at(nObject));
}

void Solids::handleSizeChanged(int nObj, GeomSettings newSett)
{
    if(allObjects.count(nObj) == 0)
    {
        return;
    }

    allObjects.at(nObj)->updateGeomSettings(newSett);

    viewWidget->changeCurObject(allObjects.at(nObj));
}

void Solids::handleGetCurrentObjSett(int nObj)
{
    if(allObjects.count(nObj) == 0)
    {
        return;
    }

    GeomSettings curObjSett = allObjects.at(nObj)->getGeomSettings();
    Point2D center = allObjects.at(nObj)->getCenter();

    emit sendObjData(center, curObjSett);
}
