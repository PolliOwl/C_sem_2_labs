#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -O2 -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -O2 -c words.c
clang -o app.exe main.o words.o -lm
