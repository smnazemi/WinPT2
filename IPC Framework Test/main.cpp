#include <QtGui/QApplication>
#include "fwtest.h"


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);//create a QApplication object
	fwtest w; //create a fwtest object
	w.show();//sets the applications ui visibility

	a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));//initiate the application
	return a.exec();
}
