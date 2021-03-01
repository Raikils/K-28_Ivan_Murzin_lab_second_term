QT += testlib
QT +=core gui  \
     winextras \
     widgets   \
     printsupport
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../project
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/plot.h $$INCDIR/qcustomplot.h $$INCDIR/mainwindow.h $$INCDIR/createplot.h $$INCDIR/tabledelegate.h
SOURCES += $$INCDIR/plot.cpp $$INCDIR/qcustomplot.cpp $$INCDIR/mainwindow.cpp $$INCDIR/createplot.cpp $$INCDIR/tabledelegate.cpp

SOURCES +=  tst_test1.cpp
