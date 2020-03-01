#include "mainwindow.h"
#include "blocks.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Blocks<4> b;

    b.print();

    size_t i = 0;
    do{
        std::cout << "Move: " << i << std::endl;
        b.print();
    } while ((int)b.move(i++) == 0);

    b.print();

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
}
