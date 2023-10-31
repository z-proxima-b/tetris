#!/usr/bin/env/bash
export GTEST_COLOR=yes
source ~/.bash_profile
g++ -std=c++14 -Wall -g -o tet prog.cpp blob.cpp blob_factory.cpp machine.cpp states.cpp state.cpp game.cpp menu.cpp exit_menu.cpp gameover_menu.cpp board.cpp colours.cpp next.cpp score.cpp lines.cpp -I../inc `pkg-config --cflags --libs raylib gtest`
if [ "$?" -eq 0 ]
then ./tet
fi 
