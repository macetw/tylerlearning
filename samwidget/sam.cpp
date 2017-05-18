#include <QApplication>
#include <QLabel>
#include <QDialog>
#include <QTimer>
#include <QVBoxLayout>
#include <QSound>

#include "window.h"
#include "samdial.h"
#include "samclock.h"


int main( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    QDialog *dialog = new QDialog( 0 );
    QLabel* sam = new QLabel( dialog );
    SamDial* dial = new SamDial( dialog );
    sam->setText( "Sam" );

    SamClock* clock = new SamClock( dialog );

    Window* win = new Window( dialog );

    QVBoxLayout* layout = new QVBoxLayout( dialog );
    layout->addStretch();
    layout->addWidget( sam, Qt::AlignCenter );
    layout->addWidget( win, Qt::AlignCenter );
    layout->addWidget( dial );
    layout->addWidget( clock );
    layout->addStretch();

    QTimer* timer = new QTimer( dialog );
    timer->setInterval( 1000 );
    QObject::connect( timer, SIGNAL(timeout()),
	              dial, SLOT(iterate()));

    timer->start();

    dialog->show();
    return app.exec();
}
