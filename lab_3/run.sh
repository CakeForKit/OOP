#!/bin/bash

qmake
make
uic interface.ui -o interface.h
./lab_3
