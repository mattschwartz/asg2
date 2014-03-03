#!/bin/bash
rm -r ./turnin-dir
mkdir ./turnin-dir
cp ./buildit ./turnin-dir
cp ./configure.ac ./turnin-dir
cp ./Makefile.am ./turnin-dir
cp ./makeit ./turnin-dir
cp ./plugins.cfg ./turnin-dir
cp ./resources.cfg ./turnin-dir
cp ./README ./turnin-dir
cp -r ./media ./turnin-dir
cp ./Ball.cpp ./turnin-dir
cp ./Ball.h ./turnin-dir
cp ./Court.cpp ./turnin-dir
cp ./Court.h ./turnin-dir
cp ./BaseApplication.cpp ./turnin-dir
cp ./BaseApplication.h ./turnin-dir
cp ./TutorialApplication.cpp ./turnin-dir
cp ./TutorialApplication.h ./turnin-dir
#cp ./OgreApp ./turnin-dir
#cp ./Common.h ./turnin-dir
#cp ./MinimalOgre.h ./turnin-dir
#cp ./MinimalOgre.cpp ./turnin-dir
cp ./PaddleController.cpp ./turnin-dir
cp ./PaddleController.h ./turnin-dir
cp ./Paddle.h ./turnin-dir
cp ./Paddle.cpp ./turnin-dir
cp ./Launcher.cpp ./turnin-dir
cp ./Launcher.h ./turnin-dir
cp ./SoundManager.cpp ./turnin-dir
cp ./SoundManager.h  ./turnin-dir
cp ./SoundEffect.cpp  ./turnin-dir
cp ./SoundEffect.h  ./turnin-dir
cp ./assignment2 ./turnin-dir
tar -c -z -f files.tgz turnin-dir
