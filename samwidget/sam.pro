######################################################################
# Automatically generated by qmake (2.01a) Tue Oct 13 19:26:24 2009
######################################################################

TEMPLATE = app
TARGET = samwidget
DEPENDPATH += .
INCLUDEPATH += .


# Input
SOURCES += sam.cpp

RESOURCES += sam.qrc

HEADERS       = glwidget.h \
                window.h \
		samdial.h \
		samclock.h
SOURCES      += glwidget.cpp \
                window.cpp \
		samdial.cpp \
		samclock.cpp
QT           += opengl gui widgets
