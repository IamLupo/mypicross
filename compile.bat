@echo off
g++ -c "include/Grid.cpp" -o "temp/Grid.o"
g++ -c "include/GridInfo.cpp" -o "temp/GridInfo.o"
g++ -c "main.cpp" -o "temp/main.o"

g++ "temp/Grid.o" "temp/GridInfo.o" "temp/main.o" -o main.exe -static

pause

main.exe

pause