#include "glass.h"
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QKeyEvent>
#include <math.h>
#include <algorithm>

glass::glass(QWidget *parent) : QWidget(parent)
{
    //---------------------- отложенная инициализация -------------------------------------------
       connect(this,SIGNAL(signalGlassInit()),this, SLOT(slotGlassInit()),Qt::QueuedConnection);
       emit signalGlassInit();
    //-------------------------------------------------------------------------------------------
}

void glass::slotGlassInit()
{
   //--------------- инициализация массива -------------------------------
    glassArray.resize(this->rows());
       for(int i = 0; i < this->rows(); i++)
       {
            glassArray[i].resize(this->colomns());
       }
       glassArray.fill(glassArray[0].fill(emptyCell));

       cpen.setRgb(255,255,255);

}


void glass::paintEvent(QPaintEvent *event)
{

//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------
//-------------------- рисуем сетку -----------------------------------
       QPainter painter(this);
       painter.setPen (QPen (Qt::gray, 1, Qt::SolidLine) ) ;

       for (uint i = 0; i <  this->colomns(); ++i)
        {
         for(uint j = 0; j < this->rows(); j++)
           {
           int x1 = 10*i;
           int y1 = 10*j;
           int w1 = 10;
           int h1 = 10;

       painter.setBrush(QBrush(glassArray[j][i], Qt::SolidPattern));
       painter.drawRect(x1,y1,w1,h1);
            }
          }

       //------------------------------------------------------------

       int y = this->width();
       int x = this->height();

        painter.setPen (QPen (Qt::black, 1, Qt::SolidLine) ) ;
        painter.setFont(QFont("Times", 8, QFont::Normal));

//------------------------------------------------------------
//------------------------------------------------------------

       painter.translate(0.0,this->height());
       painter.rotate(-90.0);
       painter.setPen (QPen (Qt::blue, 2, Qt::SolidLine) ) ;
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.setPen (QPen (Qt::black, 3, Qt::SolidLine) ) ;
       painter.drawLine(QLine(0,0,x,0));
       painter.drawLine(QLine(0,0,0,y));

       QVector<QLineF> clines;

       clines.resize(0);

       for (int i = 0; i < y; i+=10)
       {
             clines.push_back(QLineF(0, i, 4, i));
       }

       for (int i = 0; i < x; i+=10)
       {
            clines.push_back(QLineF(i, 0, i, 4));
       }

       for (int i = 0; i < y; i+=50)
       {
             clines.push_back(QLineF(0, i, 7, i));
             painter.drawText(10,i+5, QString::number(i));
       }

       for (int i = 0; i < x; i+=50)
       {
            clines.push_back(QLineF(i, 0, i, 7));
            painter.drawText(i-5,20, QString::number(i));
       }

       painter.setPen (QPen (Qt::black, 1, Qt::SolidLine) ) ;
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.drawLines(clines);
//-------------------------------------------------------------------------------------------------------
       painter.setPen (QPen (Qt::black, 2, Qt::SolidLine) ) ;
//-------------------------------------------------------------------------------------------------------

 painter.setPen (QPen (cpen, 2, Qt::SolidLine) ) ;
 painter.setRenderHint(QPainter::Antialiasing, true);
 painter.drawPolyline(vec);

 painter.setPen (QPen (Qt::black, 1, Qt::SolidLine) ) ;

 for(int i =0; i<vec.size();i++)
 {
  painter.drawEllipse(QPointF(vec[i]),2.0, 2.0);

  if (i%100 == 0)
  {
      QString str = "";
      str.clear();
      str.append("(");
      str.append(QString::number(vec[i].rx()));
      str.append(",");
      str.append(QString::number(vec[i].ry()));
      str.append(")");
      //painter.setPen (QPen (Qt::black, 5, Qt::SolidLine) ) ;
      QFont font15;
      font15.setPixelSize(15);
      painter.setFont(font15);
      painter.drawText(vec[i].rx()+5, vec[i].ry()+5, str);
  }

 }

//---------------------- вызов слота для передачи в маин -------------------------------------------
  emit signalGlassRepaint();
//-------------------------------------------------------------------------------------------

}


