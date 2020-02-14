TEMPLATE = app
TARGET = dice
DEPENDPATH += .
INCLUDEPATH += .

QT = gui widgets

# Input
HEADERS += dice.h dicewindow.h
SOURCES += dicewindow.cpp main.cpp dice.cpp
RESOURCES += images.qrc
