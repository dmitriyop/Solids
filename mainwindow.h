#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>
#include <QColorDialog>

#include "view.h"
#include "geomsettings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openMessage(const QString &message);

    bool openAskDialog(const QString &message);

    QTreeWidget *getObjectsTreePointer();

    View *getViewPointer();

public slots:
    void handleObjectChanged(QTreeWidgetItem *newItem, QTreeWidgetItem *oldItem);

    void handleColorChange();

    void hanleCurObjColor(int nObjects, QColor objColor);

    void handleCenterChanged(double newVal);

    void handleSizeChanged(double val);

    void handleCurObjSett(const Point2D &curCenter, const GeomSettings &curObjSett);

signals:
    void objectChanged(int objectIndex);
    void requestCurObjColor(int objectIndex);
    void changeCurObjColor(int nObject, QColor newColor);
    void changeCurObjCenter(int nObject, Point2D newCcoord);
    void sizeChanged(int nObj, GeomSettings gSett);
    void requestCurObjSett(int nObj);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
