#include "calculator.h"
#include <QApplication>

 
int main( int argc, char** argv )
{
  QApplication app(argc, argv);

  Calculator calcWidget;
  calcWidget.show();

  return app.exec();
}
