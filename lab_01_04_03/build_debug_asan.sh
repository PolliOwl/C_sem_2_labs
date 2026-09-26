#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=address -c main.c
clang -fsanitize=address -o app.exe main.o -lm
