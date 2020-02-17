TEMPLATE = app
TARGET = dice_by_qmake
DEPENDPATH += .
INCLUDEPATH += .

MOC_DIR = qmake_files/moc
OBJECTS_DIR = qmake_files/obj
RCC_DIR = qmake_files/qrc

QT = gui widgets

# Input
HEADERS += dice.h dicewindow.h
SOURCES += dicewindow.cpp main.cpp dice.cpp
RESOURCES += images.qrc
