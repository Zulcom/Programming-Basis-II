/* ======================================================================
**  Fractal.cpp
** ======================================================================
*/  

#include <QImage>

#include "fractal.h"

// ----------------------------------------------------------------------
Fractal::Fractal(int _n /*= 1*/, QWidget* pwgt /*= 0*/) : n(_n),  QWidget(pwgt) { }

// ----------------------------------------------------------------------
Fractal::~Fractal() { }

// ----------------------------------------------------------------------
void Fractal::paintEvent(QPaintEvent*) {
    QImage   img(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;

    painter.begin(&img);
    painter.initFrom(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.eraseRect(rect());

    int xa = 0;
    int ya = size().height();
    int xb = size().width();
    int yb = size().height();
    int xc = 0;
    int yc = 0;

    painter.drawLine(xa, ya, xb, yb);
    painter.drawLine(xb, yb, xc, yc);
    painter.drawLine(xc, yc, xa, ya);

    Triangle (painter, xa, ya, xb, yb, xc, yc, n);

    painter.end();

    painter.begin(this);
    painter.drawImage(0, 0, img);
    painter.end();
}

void Fractal::Triangle (QPainter& painter, int xa, int ya, int xb, int yb, int xc, int yc, int n) {
    int xp, yp, yq, xq, xr, yr;
    if ( n > 0 ) {
        xp = (xb+xc)/2; yp = (yb+yc)/2;
        xq = (xc+xa)/2; yq = (yc+ya)/2;
        xr = (xa+xb)/2; yr = (ya+yb)/2;
        //Рисование тpеугольника
        painter.drawLine(xp, yp, xq, yq);
        painter.drawLine(xq, yq, xr, yr);
        painter.drawLine(xr, yr, xp, yp);
        //Рисование трех малых треугольников
        Triangle (painter, xa, ya, xr, yr, xq, yq, n-1);
        Triangle (painter, xb, yb, xp, yp, xr, yr, n-1);
        Triangle (painter, xc, yc, xq, yq, xp, yp, n-1);
    }
}
