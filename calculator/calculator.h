
#include <QMainWindow>

class QLineEdit;

class Calculator : public QMainWindow
{
  Q_OBJECT
 public:
  Calculator();

  enum Operation { Plus, Minus, Multiply, Devide, None };

 public slots:
  void numberEntered(int number);
  void plusClicked();
  void minusClicked();
  void multiplyClicked();
  void devideClicked();
  void equalClicked();
  void squaredClicked();
  void clearClicked();

 protected:
  void keyPressEvent( QKeyEvent* event );

 private:
  QLineEdit *vLineEdit;
  int vPreviousValue;
  bool vClearAtNextDigit;
  Operation vCurrentOperation;

};


