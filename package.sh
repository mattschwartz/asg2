#!/bin/bash
rm -r ./turnin-dir
cp ./buildit ./turnin-dir
cp ./configure.ac ./turnin-dir
cp ./Makefile.am ./turnin-dir
cp ./makeit ./turnin-dir
cp ./plugins.cfg ./turnin-dir
cp ./resources.cfg ./turnin-dir
cp ./README ./turnin-dir
cp -r ./media ./turnin-dir
#cp ./Ball.cpp ./turnin-dir
#cp ./Ball.h ./turnin-dir
#cp ./PlayingField.cpp ./turnin-dir
#cp ./PlayingField.h ./turnin-dir
#cp ./BaseApplication.cpp ./turnin-dir
#cp ./BaseApplication.h ./turnin-dir
#cp ./TutorialApplication.cpp ./turnin-dir
#cp ./TutorialApplication.h ./turnin-dir
#cp ./OgreApp ./turnin-dir
cp ./MinimalOgre.h ./turnin-dir
cp ./MinimalOgre.cpp ./turnin-dir
cp ./PaddleController.cpp ./turnin-dir
cp ./PaddleController.h ./turnin-dir
cp ./Paddle.h ./turnin-dir
cp ./Paddle.cpp ./turnin-dir
cp ./assignment2 ./turnin-dir
cp ./Room.cpp ./turnin-dir
cp ./Room.h ./turnin-dir
tar -c -z -f files.tgz turnin-dir



