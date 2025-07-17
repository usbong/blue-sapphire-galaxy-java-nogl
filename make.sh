#!/bin/bash

# C/C++ Computer Language and Simple Directmedia Layer (SDL) 
#
# Compile and Link Multiple Source Files
#
# @company: USBONG
# @author: SYSON, MICHAEL B.
# @date created: 20200930
# @last updated: 20250717; from 20211025
# @website address: http://www.usbong.ph
#
# Reference:
# 1) https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html;
# last accessed: 20200930

#removed by Mike, 20210818
#cp -r ./textures ./output/
#cp -r ./input ./output/

#rm *.o

#note: sequence

#g++ -c mainLinux.cpp
#g++ -c OpenGLCanvas.cpp
#g++ -c UsbongUtils.cpp
# ...

g++ -c inputTestSDL.cpp

#g++ -o ./output/UsbongPagongLinux mainLinux.o OpenGLCanvas.o UsbongUtils.o PolygonUtils.o MyDynamicObject.o Level2D.o Level3D.o Pilot.o Robotship.o Font.o Text.o -lGL -lGLU -lglut -lSDL2 -lSDL2_image

g++ -o ./inputTestSDL inputTestSDL.o -lSDL2