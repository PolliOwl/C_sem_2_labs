#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=address -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=address -c matrix.c
clang -fsanitize=address -o app.exe main.o matrix.o -lm
