#include <QApplication>

#include "dicewindow.h"

int main( int argc, char* argv[] )
{
  QApplication app( argc, argv );

  DiceWindow window;

  window.show();
  return app.exec();
}

