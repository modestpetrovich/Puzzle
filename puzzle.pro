QT += widgets
requires(qtConfig(listview))

HEADERS     = mainwindow.h \
              piecesmodel.h \
              puzzlewidget.h
              
SOURCES     = main.cpp \
              mainwindow.cpp \
              piecesmodel.cpp \
              puzzlewidget.cpp

