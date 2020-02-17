#include <QtWidgets/QLabel>

class QTimer;

class Dice : public QLabel
{
  Q_OBJECT
 public:
  Dice( QWidget* parent );
  ~Dice() {};

  int heightForWidth( int w ) { return w; }

  void setValue(int value);
  int value() const { return vValue; }

  void updateToValue();

 public slots:
  void roll();
  
 private:
  Dice(); /* disabled */

  QTimer* vTimer;
  int vValue;
};
