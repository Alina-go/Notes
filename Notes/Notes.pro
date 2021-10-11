QT += widgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notes
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    CustomTableWidget.h \
    AboutNote.h \
    Notes.h\
#    TddSorting.h \
    test_runner.h

SOURCES += \
    main.cpp \
    CustomTableWidget.cpp \
    AboutNote.cpp \
    Notes.cpp
#    TddSorting.cpp

Tests.depends = Notes
