#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -O2 -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -O2 -c file.c
clang -o app.exe main.o file.o -lm
