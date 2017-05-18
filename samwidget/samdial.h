#include <QDial>


class SamDial : public QDial
{
    Q_OBJECT
public:
    SamDial( QWidget* parent );

public slots:
    void iterate();

};
