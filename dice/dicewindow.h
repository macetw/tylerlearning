#include <QMainWindow>

class QPushButton;
class Dice;

class DiceWindow : public QMainWindow
{
  Q_OBJECT
 public:
  DiceWindow();
  ~DiceWindow() {};

 public slots:
  void rollDice();

 private:
  Dice* vDice1;
  Dice* vDice2;

};
