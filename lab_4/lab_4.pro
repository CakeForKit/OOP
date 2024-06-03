#TARGET = lab_4

QT += gui widgets core
OBJECTS_DIR = ./out
QMAKE_CXXFLAGS += -std=c++20
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

INCLUDEPATH += \
    . \
    mainwindow \


HEADERS += \
    mainwindow/*.h


SOURCES += \
    ./*.cpp \
    \
    mainwindow/*.cpp





    