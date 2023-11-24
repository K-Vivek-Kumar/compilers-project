@echo off
bison -d parser.y
if errorlevel 1 (
    echo Error: Bison compilation failed
    exit /b 1
)

flex lexer.l
if errorlevel 1 (
    echo Error: Flex compilation failed
    exit /b 1
)

gcc lex.yy.c parser.tab.c -o vwake
if errorlevel 1 (
    echo Error: Compilation failed
    exit /b 1
)

.\vwake %1
if errorlevel 1 (
    echo Error: Execution failed
    exit /b 1
)

g++ -c svas.cpp -o svas.o
if errorlevel 1 (
    echo Error: Compilation of svas.cpp failed
    exit /b 1
)

g++ -c plotter.cpp -o svas_plotter.o
if errorlevel 1 (
    echo Error: Compilation of plotter.cpp failed
    exit /b 1
)

g++ svas_plotter.o svas.o -o svas
if errorlevel 1 (
    echo Error: Linking failed! No Executable Generated.
    exit /b 1
)

.\svas
if errorlevel 1 (
    echo Error: Execution of svas failed
    exit /b 1
)
