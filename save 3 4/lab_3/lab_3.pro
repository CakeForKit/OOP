#TARGET = lab_3

QT += gui widgets core
OBJECTS_DIR = ./out
QMAKE_CXXFLAGS += -std=c++20 -g3
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

INCLUDEPATH += \
    . \
    concepts \
    \
    commands \ 
    commands/camera \
    commands/draw \
    commands/load \
    commands/object_scene \
    commands/scene \
    \
    drawer \
    \
    exceptions \
    \
    facade \
    \
    load/builder \
    load/director \
    load/reader \
    load/reader/BaseReader \
    load/reader/ReaderSolution \
    load/reader/CarcasModelReader \
    load/reader/TxtCarcasModelReader \
    load/reader/CsvCarcasModelReader \
    \
    managers \
    \
    matrix \
    \
    object_scene \
    \
    scene \
    \
    strategy \
    \
    transform \
    \
    visitor


# Input
HEADERS += \
    ./*.hpp \
    concepts/*.h \
    \
    commands/*.h \ 
    commands/camera/*.h \
    commands/draw/*.h \
    commands/load/*.h \
    commands/object_scene/*.h \
    commands/scene/*.h \
    \
    drawer/*.h \
    \
    exceptions/*.h \
    \
    facade/*.h \
    \
    load/builder/*.h \
    load/director/*.h \
    load/director/*.hpp \
    load/reader/*.h \
    load/reader/*.hpp \
    load/reader/BaseReader/*.h \
    load/reader/ReaderSolution/*.h \
    load/reader/CarcasModelReader/*.h \
    load/reader/TxtCarcasModelReader/*.h \
    load/reader/CsvCarcasModelReader/*.h \
    \
    managers/*.h \
    managers/*.hpp \
    \
    matrix/*.h \
    matrix/*.hpp \
    \
    object_scene/*.h \
    \
    scene/*.h \
    \
    strategy/*.h \
    \
    transform/*.h \
    \
    visitor/*.h 


SOURCES += \
    ./*.cpp \
    \
    commands/*.cpp \ 
    commands/camera/*.cpp \
    commands/draw/*.cpp \
    commands/load/*.cpp \
    commands/object_scene/*.cpp \
    commands/scene/*.cpp \
    \
    drawer/*.cpp \
    \
    exceptions/*.cpp \
    \
    facade/*.cpp \
    \
    load/builder/*.cpp \
    load/director/*.cpp \
    load/reader/BaseReader/*.cpp \
    load/reader/ReaderSolution/*.cpp \
    load/reader/CarcasModelReader/*.cpp \
    load/reader/TxtCarcasModelReader/*.cpp \
    load/reader/CsvCarcasModelReader/*.cpp \
    \
    managers/*.cpp \
    \
    object_scene/*.cpp \
    \
    scene/*.cpp \
    \
    strategy/*.cpp \
    \
    transform/*.cpp \
    \
    visitor/*.cpp





    