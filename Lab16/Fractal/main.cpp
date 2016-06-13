/* ======================================================================
**  main.cpp
** ======================================================================
*/

#include <QApplication>
#include <QMessageBox>

#include "fractal.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv) {
    QApplication app(argc, argv);

    int n;
    if(argc !=2) {
        //QMessageBox::information(0, QString("Error!"), 
        //     QString("Incorrect command line! Wated: command number"), 
        //     QMessageBox::Close);
        n = 5;
    } else {
        n = QString(argv[1]).toInt();
        if((n < 1)||(n > 7)) {
            QMessageBox::information(0, 
                                 QString("Error!"), 
                                 QString("Argument must be value from 1 to 7"), 
                                 QMessageBox::Close);
            return -1;
        }
    }

    Fractal fractal(n);

    fractal.resize(800, 600);
    fractal.show();

    return app.exec();
}
