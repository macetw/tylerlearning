
#include "samdial.h"

SamDial::SamDial( QWidget* parent )
    : QDial( parent )
{
    setNotchesVisible( true );
}

void SamDial::iterate()
{
    setValue( value() + 1 );
}


