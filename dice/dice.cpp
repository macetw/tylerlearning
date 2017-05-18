#include <QTimer>

#include "dice.h"

Dice::Dice( QWidget* parent )
 : QLabel( parent ),
   vValue( 1 )
{
  setScaledContents( true );
  updateToValue();
  setMinimumSize( 10, 10 );

  vTimer = new QTimer( this );
  vTimer->setInterval( 200 );
  
  connect( vTimer, SIGNAL( timeout() ),
           this, SLOT( roll() ) );
  vTimer->start();
}

void Dice::roll()
{
  vValue = ( ( vValue ) % 6 ) + 1;
  updateToValue();
}

void Dice::setValue(int value)
{
  vTimer->stop();
  vValue = value;
  updateToValue();
}


void Dice::updateToValue()
{
  QString resource( QString( ":images/%1.png" ).arg( vValue ) );
  setPixmap( QPixmap( resource ) );
}
