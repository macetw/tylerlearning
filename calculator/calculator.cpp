#include "calculator.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QSignalMapper>
#include <QIntValidator>

#include <QKeyEvent>

#include <iostream>

using namespace std;

Calculator::Calculator()
 : QMainWindow( 0 ),
   vPreviousValue( 0 ),
   vClearAtNextDigit( false ),
   vCurrentOperation( None )
{
  QSignalMapper* numberMapper = new QSignalMapper( this );
  connect(numberMapper, SIGNAL( mapped(int) ),
          this, SLOT( numberEntered(int) ));

  QPushButton*numbers[10];

  for (int i = 0;
       i < 10;
       i = i + 1)  {
    numbers[i] = new QPushButton( this );
    numbers[i]->setText( QString::number( i ) );
    numberMapper->setMapping( numbers[i], i );
    connect( numbers[i], SIGNAL(clicked()),
             numberMapper, SLOT(map()) );
  }

  QPushButton * plus = new QPushButton( this );
  plus->setText("+");
  connect( plus, SIGNAL(clicked()),
           this, SLOT(plusClicked()) );

  QPushButton * minus = new QPushButton( this );
  minus->setText("-");
  connect( minus, SIGNAL(clicked()),
           this, SLOT(minusClicked()) );

  QPushButton * multiply = new QPushButton( this );
  multiply->setText("x");
  connect( multiply, SIGNAL(clicked()),
           this, SLOT(multiplyClicked()) );

  QPushButton * devide = new QPushButton( this );
  devide->setText("-");
  connect( devide, SIGNAL(clicked()),
           this, SLOT(devideClicked()) );

  QPushButton * equal = new QPushButton( this );
  equal->setText("=");
  connect( equal, SIGNAL(clicked()),
           this, SLOT(equalClicked()) );

  QPushButton * squared = new QPushButton( this );
  squared->setText("^");
  connect( squared, SIGNAL(clicked()),
           this, SLOT(squaredClicked()) );

  QIntValidator *validator = new QIntValidator( this );

  vLineEdit = new QLineEdit( this );
  vLineEdit->setValidator( validator );
  vLineEdit->setAlignment( Qt::AlignRight );

  QWidget *centralWidget = new QWidget( this );
  setCentralWidget(centralWidget);

  QGridLayout* grid = new QGridLayout( centralWidget );
  grid->setSpacing( 1 );

  //                 widget    row, column
  grid->addWidget( numbers[0], 5,   0, 1, 4 );
  grid->addWidget( numbers[1], 4,   0 );
  grid->addWidget( numbers[2], 4,   1 );
  grid->addWidget( numbers[3], 4,   2 );
  grid->addWidget( numbers[4], 3,   0 );
  grid->addWidget( numbers[5], 3,   1 );
  grid->addWidget( numbers[6], 3,   2 );
  grid->addWidget( numbers[7], 2,   0 );
  grid->addWidget( numbers[8], 2,   1 );
  grid->addWidget( numbers[9], 2,   2 );
  grid->addWidget( plus,       1,   0 );
  grid->addWidget( minus,      1,   1 );
  grid->addWidget( multiply,   1,   3 );
  grid->addWidget( devide,     2,   3 );
  grid->addWidget( squared,    3,   3 );
  grid->addWidget( equal,      1,   2 );
  grid->addWidget( vLineEdit,  0,   0, 1, 3);
}

void Calculator::numberEntered(int digit)
{
  QString text = vLineEdit->text();
  if (vClearAtNextDigit) {
    text.clear();
    vClearAtNextDigit = false;
  }
  text.append( QString::number( digit ) );
  const QValidator* validate = vLineEdit->validator();
  int pos = text.size();
  if (validate->validate( text, pos ) == QValidator::Acceptable) {
    vLineEdit->setText( text );
  }
}

void Calculator::plusClicked()
{
  equalClicked();
  vCurrentOperation = Plus;
  vClearAtNextDigit = true;
  QString text = vLineEdit->text();
  vPreviousValue = text.toInt();
}

void Calculator::minusClicked()
{
  equalClicked();
  vCurrentOperation = Minus;
  vClearAtNextDigit = true;
  QString text = vLineEdit->text();
  vPreviousValue = text.toInt();
}

void Calculator::multiplyClicked()
{
  equalClicked();
  vCurrentOperation = Multiply;
  vClearAtNextDigit = true;
  QString text = vLineEdit->text();
  vPreviousValue = text.toInt();
}

void Calculator::devideClicked()
{
  equalClicked();
  vCurrentOperation = Devide;
  vClearAtNextDigit = true;
  QString text = vLineEdit->text();
  vPreviousValue = text.toInt();
}

void Calculator::squaredClicked()
{
  equalClicked();
  vCurrentOperation = None;
  vClearAtNextDigit = true;
  int value = vLineEdit->text().toInt();
  int newValue = value * value;
  vLineEdit->setText( QString::number( newValue ) );
  QString text = vLineEdit->text();
  vPreviousValue = text.toInt();
}

void Calculator::equalClicked()
{
  if (vCurrentOperation != None) {
    QString text = vLineEdit->text();
    int currentValue = text.toInt();

    int newValue = 0;
    switch( vCurrentOperation ) {
      case( Plus ):
        newValue = vPreviousValue + currentValue;
	break;
      case( Minus ):
        newValue = vPreviousValue - currentValue;
	break;
      case( Multiply ):
        newValue = vPreviousValue * currentValue;
	break;
      case( Devide ):
        newValue = vPreviousValue / currentValue;
	break;
    }

    vLineEdit->setText( QString::number( newValue ) );
    vClearAtNextDigit = true;
    vCurrentOperation = None;
  }
}

void Calculator::keyPressEvent( QKeyEvent* event )
{
  const Qt::Key pressed = (Qt::Key)event->key();
  const QString text = event->text();
  if (pressed >= Qt::Key_0 && pressed <= Qt::Key_9) {
    const int number = text.toInt(); 
    numberEntered( number );
  } else if (text == "-") {
    minusClicked();
  } else if (text == "+") {
    plusClicked();
  } else if (text == "*") {
    multiplyClicked();
  } else if (text == "+") {
    devideClicked();
  } else if (text == "=") {
    equalClicked();
  } else {
    QMainWindow::keyPressEvent(event);
  }
}

