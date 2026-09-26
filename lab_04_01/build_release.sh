#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -O2 -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -O2 -c my_string.c
clang -o app.exe main.o my_string.o -lm
