#include <QDateTimeEdit>

class QLabel;

class SamClock : public QWidget
{
    Q_OBJECT
public:
    SamClock( QWidget* parent );

private slots:
    void update();

private:
    QDateTimeEdit * edit;
    QLabel * secondsLeft;
};
