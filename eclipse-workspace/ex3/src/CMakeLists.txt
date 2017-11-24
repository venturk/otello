cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.h Board.cpp Cell.cpp Cell.h Point.cpp Point.h String.cpp String.h Game.cpp Game.h Player.h HumanPlayer.cpp HumanPlayer.h GameLogic.h DefaultLogic.cpp DefaultLogic.h CellMap.cpp CellMap.h ConsoleMsgs.cpp ConsoleMsgs.h)
add_executable(untitled ${SOURCE_FILES} Board.h Board.cpp)