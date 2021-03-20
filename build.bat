@echo off

mkdir out\main\cpp\gas\core
mkdir out\test\cpp\gas\core

g++ -c -std=c++17 src\main\cpp\gas\core\obj.cpp -o out\main\cpp\gas\core\obj.o
g++ -c -std=c++17 src\main\cpp\gas\core\str.cpp -o out\main\cpp\gas\core\str.o
g++ -c -std=c++17 src\main\cpp\gas\core\ptr.cpp -o out\main\cpp\gas\core\ptr.o
ar -r out\libgas.a out\main\cpp\gas\core\obj.o out\main\cpp\gas\core\str.o out\main\cpp\gas\core\ptr.o

g++ -c -std=c++17 -Isrc\main\cpp src\test\cpp\test.cpp -o out\test\cpp\test.o
g++ -std=c++17 out\test\cpp\test.o -Lout -lgas -o out\test.exe

