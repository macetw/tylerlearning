#include <QPushButton>
#include <QLayout>
#include "dice.h"
#include "dicewindow.h"

DiceWindow::DiceWindow()
{
  QWidget * mainWidget = new QWidget( this );
  setCentralWidget( mainWidget );

  vDice1 = new Dice( this );
  vDice2 = new Dice( this );

  QPushButton * rollButton = new QPushButton( this );
  rollButton->setText( "Roll" );

  connect( rollButton, SIGNAL( clicked() ),
           this, SLOT( rollDice() ) );

  QHBoxLayout * diceLayout = new QHBoxLayout;
  QHBoxLayout * buttonLayout = new QHBoxLayout;

  diceLayout->addStretch();
  diceLayout->addWidget(vDice1);
  diceLayout->addStretch();
  diceLayout->addWidget(vDice2);
  diceLayout->addStretch();

  buttonLayout->addStretch();
  buttonLayout->addWidget(rollButton);
  buttonLayout->addStretch();

  QVBoxLayout * layout = new QVBoxLayout( mainWidget );
  layout->addStretch();
  layout->addLayout(diceLayout);
  layout->addStretch();
  layout->addLayout(buttonLayout);
}


void DiceWindow::rollDice()
{
  int newValue = ((float)rand() * 6.0f / RAND_MAX) + 1;

  vDice1->setValue(newValue);

  newValue = ((float)rand() * 6.0f / RAND_MAX) + 1;
  vDice2->setValue(newValue);
}
