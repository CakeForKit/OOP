TARGET = lab_4

QT += gui widgets core
OBJECTS_DIR = ./out
QMAKE_CXXFLAGS += -std=c++20 -g3 
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

INCLUDEPATH += \
    . \
    mainwindow \
    button_lift \
    cabin_lift \
    controller_lift \
    doors_lift \
    lift \


HEADERS += \
    mainwindow/*.h \
    button_lift/*.h \
    cabin_lift/*.h \
    controller_lift/*.h \
    doors_lift/*.h \
    lift/*.h \


SOURCES += \
    ./*.cpp \
    \
    mainwindow/*.cpp \
    button_lift/*.cpp \
    cabin_lift/*.cpp \
    controller_lift/*.cpp \
    doors_lift/*.cpp \
    lift/*.cpp \





    