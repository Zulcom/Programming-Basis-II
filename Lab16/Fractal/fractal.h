/* ======================================================================
**  Fractal.h
** ======================================================================
*/

#ifndef _Fractal_h_
#define _Fractal_h_

#include <QWidget>
#include <QPainter>

// ======================================================================
class Fractal : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent* pe);
public:
    Fractal(int _n = 1, QWidget* pwgt = 0);
    virtual ~Fractal();
private:
    void Triangle (QPainter& painter, int xa, int ya, int xb, int yb, int xc, int yc, int n);
    int n;
};

#endif  //_Fractal_h_
