#!/bin/bash

bison -d parser.y
if [ $? -ne 0 ]; then
    echo "Error: Bison compilation failed"
    exit 1
fi

flex lexer.l
if [ $? -ne 0 ]; then
    echo "Error: Flex compilation failed"
    exit 1
fi

gcc lex.yy.c parser.tab.c -o vwake
if [ $? -ne 0 ]; then
    echo "Error: Compilation failed"
    exit 1
fi

./vwake "$1"
if [ $? -ne 0 ]; then
    echo "Error: Execution failed"
    exit 1
fi

g++ -c svas.cpp -o svas.o
if [ $? -ne 0 ]; then
    echo "Error: Compilation of svas.cpp failed"
    exit 1
fi

g++ -c plotter.cpp -o svas_plotter.o
if [ $? -ne 0 ]; then
    echo "Error: Compilation of plotter.cpp failed"
    exit 1
fi

g++ svas_plotter.o svas.o -o svas
if [ $? -ne 0 ]; then
    echo "Error: Linking failed! No Executable Generated."
    exit 1
fi

./svas
if [ $? -ne 0 ]; then
    echo "Error: Execution of svas failed"
    exit 1
fi

exit 0
