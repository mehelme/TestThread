#include "MainWindow.h"
#include <QApplication>
#include <QDebug>

#include <cstdlib>

typedef int (*Function)();

static Function Do;

static int EraseAll() {
  return system("yes");
}

void NeverCalled() {
  Do = EraseAll;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

//    qDebug() << Do();
//    int c = a.exec();
//	qDebug() << "THE MAIN END.";
    return a.exec();
}
