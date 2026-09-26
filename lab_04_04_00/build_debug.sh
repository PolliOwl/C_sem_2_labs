#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -c ip.c
clang -o app.exe main.o ip.o -lm
