#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->exitAction, &QAction::triggered, [&](bool)
    {
        if(openAskDialog(tr("Close program?")))
        {
            this->deleteLater();
            this->close();
        }

    });

    ui->treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QTreeWidgetItemIterator it(ui->treeWidget);
    ui->treeWidget->setCurrentItem(*it);

    connect(ui->treeWidget, &QTreeWidget::currentItemChanged, this, &MainWindow::handleObjectChanged);
    connect(ui->pushButtonColor, &QPushButton::pressed, this, &MainWindow::handleColorChange);
    connect(ui->doubleSpinBoxX,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleCenterChanged);
    connect(ui->doubleSpinBoxY,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleCenterChanged);
    connect(ui->doubleSpinBoxZ,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleCenterChanged);
    connect(ui->doubleSpinBoxSquareSize,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleSizeChanged);
    connect(ui->doubleSpinBoxSizeXRect,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleSizeChanged);
    connect(ui->doubleSpinBoxSizeYRect,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleSizeChanged);
    connect(ui->doubleSpinBoxRadiusCircle,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleSizeChanged);
    connect(ui->doubleSpinBoxTriangle,  static_cast<void(QDoubleSpinBox::*)(double val)>(&QDoubleSpinBox::valueChanged), this, &MainWindow::handleSizeChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openMessage(const QString &message)
{
    QMessageBox * messageBox = new QMessageBox(this);
    messageBox->setText(message);
    messageBox->setWindowFlags(Qt::Window);
    messageBox->setAttribute(Qt::WA_DeleteOnClose);
    messageBox->exec();
}

bool MainWindow::openAskDialog(const QString &message)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Solids"), message,
                                  QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QTreeWidget *MainWindow::getObjectsTreePointer()
{
    return  ui->treeWidget;
}

View *MainWindow::getViewPointer()
{
    return ui->centralWidget;
}

void MainWindow::handleObjectChanged(QTreeWidgetItem *newItem, QTreeWidgetItem *oldItem)
{
    if(!newItem || !oldItem)
    {
        return;
    }

    int numObject = ui->treeWidget->currentIndex().row();

    ui->stackedSettingsWidget->setCurrentIndex(numObject);

    emit objectChanged(numObject);
    emit requestCurObjSett(numObject);

}

void MainWindow::handleColorChange()
{
    int curObjId = ui->treeWidget->currentIndex().row();
    emit requestCurObjColor(curObjId);

}

void MainWindow::hanleCurObjColor(int nObject, QColor objColor)
{
    QColorDialog dialog;
    dialog.setCurrentColor(objColor);
    dialog.setOption(QColorDialog::DontUseNativeDialog);

    if (dialog.exec() == QColorDialog::Accepted)
    {
        objColor = dialog.currentColor();
    }

    emit changeCurObjColor(nObject, objColor);
}

void MainWindow::handleCenterChanged(double newVal)
{
    if(newVal < -1.0 || newVal > 1.0)
    {
        return;
    }

    int nObj = ui->treeWidget->currentIndex().row();

    Point2D newC;
    newC.setX(ui->doubleSpinBoxX->value());
    newC.setY(ui->doubleSpinBoxY->value());

    emit changeCurObjCenter(nObj, newC);
}

void MainWindow::handleSizeChanged(double val)
{
    if(val < 0)
    {
        return;
    }

    int nObj = ui->treeWidget->currentIndex().row();

    double size1 = 0;
    double size2 = 0;

    if(nObj == 0)
    {
        size1 = ui->doubleSpinBoxSquareSize->value();
    }
    else if(nObj == 1)
    {
        size1 = ui->doubleSpinBoxSizeXRect->value();
        size2 = ui->doubleSpinBoxSizeYRect->value();
    }
    else if(nObj == 2)
    {
        size1 = ui->doubleSpinBoxTriangle->value();
    }
    else if(nObj == 3)
    {
        size1 = ui->doubleSpinBoxRadiusCircle->value();
    }

    GeomSettings curSettings;
    curSettings.size1 = size1;
    curSettings.size2 = size2;


    emit sizeChanged(nObj, curSettings);
}

void MainWindow::handleCurObjSett(const Point2D &curCenter, const GeomSettings &curObjSett)
{
    ui->doubleSpinBoxX->setValue(curCenter.x());
    ui->doubleSpinBoxY->setValue(curCenter.y());

    int nObj = ui->treeWidget->currentIndex().row();

    if(nObj == 0)
    {
        ui->doubleSpinBoxSquareSize->setValue(curObjSett.size1);
    }
    else if(nObj == 1)
    {
        ui->doubleSpinBoxSizeXRect->setValue(curObjSett.size1);
        ui->doubleSpinBoxSizeYRect->setValue(curObjSett.size2);
    }
    else if(nObj == 2)
    {
        ui->doubleSpinBoxTriangle->setValue(curObjSett.size1);
    }
    else if(nObj == 3)
    {
        ui->doubleSpinBoxRadiusCircle->setValue(curObjSett.size1);
    }

}
