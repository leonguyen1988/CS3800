# !/bin/bash


g++ *.cpp -o leo.out
valgrind --leak-check=full -v ./leo.out
