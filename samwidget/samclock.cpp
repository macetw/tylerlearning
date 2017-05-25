#include <QDateTimeEdit>
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>

#include "samclock.h"

SamClock::SamClock( QWidget* parent )
  : QWidget( parent )
{

    edit = new QDateTimeEdit( this );
    edit->setDisplayFormat( "dd.MM.yyyy h:mm:ss AP" );

    secondsLeft = new QLabel( this );
    QHBoxLayout* layout = new QHBoxLayout( this );
    layout->addWidget( edit );
    layout->addWidget( secondsLeft );
    QTimer * timer = new QTimer( this );
    timer->setInterval( 1000 );
    connect( timer, SIGNAL(timeout()),
	     this, SLOT(update()));
    timer->start();

}


void SamClock::update()
{
    edit->setDateTime( QDateTime::currentDateTime() );

    const QTime bedtime( 8+12, 0, 0 );
    const QTime currentTime( QTime::currentTime() );

    int seconds = currentTime.secsTo( bedtime );
    bool past = false;

    if ( seconds < 0 ) {
	past = true;
        seconds = 0-seconds;
    }

    int hr = seconds / 3600;
    seconds = seconds % 3600;

    int min = seconds / 60;
    seconds = seconds % 60;
 
    QString label("It's %1 hours, %2 minutes, %3 seconds until bedtime." );
    if (past) {
      label = ("<font color=red>It's %1 hours, %2 minutes, %3 seconds past bedtime! <i>Get to bed!</i></font>" );
    }

    if (seconds % 10 == 0) {
      //QSound* sound = new QSound( "bedtime.wav", this );
      //if (sound->isAvailable()) {
        //sound->play();
      //} else {
        //qWarning("unable to play sound");
      //}

    }


    label = label.arg(hr).arg(min).arg(seconds);

    secondsLeft->setText( label );
}


