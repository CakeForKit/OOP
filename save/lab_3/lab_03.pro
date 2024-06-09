#TARGET = lab_3

QT = core gui widgets

OBJECTS_DIR = out
QMAKE_CXXFLAGS += -std=c++20
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

HEADERS = \
    concepts.hpp \
    load/builder/*.h \
    load/reader/creators/ReaderSolution.h \
    load/reader/creators/ReaderCreatorMaker.h \
    load/reader/creators/ReaderCreator.hpp \
    load/reader/creators/BaseReaderCreator.h \
    load/reader/*.h \
    \
    load/director/BaseCarcasModelDirector/*.h \
    load/director/BaseDirector/*.h \
    load/director/CarcasModelDirectorOfDotsLinks/*.h \
    load/director/creators/*.h \
    load/director/creators/*.hpp \
    load/director/creators/BaseModelDirectorCreator/*.h \
    load/director/creators/ModelDirectorSolution/*.h \
    \
    object_scene/carcas_model/*.h \
    object_scene/*.h \
    \
    matrix/iterators/*.h \
    matrix/iterators/*.hpp \
    matrix/matrix/*.h \
    matrix/matrix/*.hpp \
    \
    exeptions/BaseException.h \
    exeptions/LoadException.h \
    exeptions/MatrixExceptions.h \
    \
    tests/*.h


SOURCES = \
    main.cpp \
    load/builder/*.cpp \
    load/reader/creators/ReaderSolution.cpp \
    load/reader/creators/BaseReaderCreator.cpp \
    load/reader/*.cpp \
    \
    load/director/BaseCarcasModelDirector/*.cpp \
    load/director/BaseDirector/*.cpp \
    load/director/CarcasModelDirectorOfDotsLinks/*.cpp \
    load/director/creators/BaseModelDirectorCreator/*.cpp \
    load/director/creators/ModelDirectorSolution/*.cpp \
    \
    object_scene/carcas_model/*.cpp \
    object_scene/*.cpp \
    \
    matrix/matrix/*.cpp \
    exeptions/BaseException.cpp \
    \
    tests/*.cpp
   

INCLUDEPATH = \
    . \
    load/builder \
    load/reader/creators \
    load/reader \
    \
    load/director/BaseCarcasModelDirector \
    load/director/BaseDirector \
    load/director/CarcasModelDirectorOfDotsLinks \
    load/director/creators \
    load/director/creators/BaseModelDirectorCreator \
    load/director/creators/ModelDirectorSolution \
    \
    object_scene/carcas_model \
    object_scene \
    matrix/iterators \
    matrix/matrix \
    exeptions \
    tests
    

FORMS += \
    

DISTFILES += \
    
#DEFINES = 

