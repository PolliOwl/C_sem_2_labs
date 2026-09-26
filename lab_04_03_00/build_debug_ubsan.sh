#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=undefined -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=undefined -c words.c
clang -fsanitize=undefined -o app.exe main.o words.o -lm
