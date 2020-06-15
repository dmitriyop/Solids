#include "view.h"


View::View(QWidget *parent) :
    QGLWidget(parent)
{

}

void View::initializeGL()
{
   glClearColor(colorBackground.x(), colorBackground.y(), colorBackground.z(), colorBackground.w()); // заполняем экран белым цветом
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glEnable(GL_CULL_FACE);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void View::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nHeight, nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void View::paintGL() // рисование
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   if(!curObjectData)
   {
       return;
   }

   QColor curColor = curObjectData->getCurColor();
   qglColor(curColor);

   std::vector<Point2D> curCoords = curObjectData->getCoordinates();
   std::size_t nPoints = curCoords.size();

   glBegin(GL_POLYGON);
   //Set vertices
   for(std::size_t i = 0; i < nPoints; ++i)
   {
       glVertex3f(static_cast<float>(curCoords[i].x()), static_cast<float>(curCoords[i].y()), 0.5);
   }
   glEnd();

}

void View::changeCurObject(std::shared_ptr<GeometryObject> newObject)
{
    curObjectData = newObject;
    this->update();
}

View::~View()
{

}
