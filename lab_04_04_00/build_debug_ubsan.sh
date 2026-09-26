#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=undefined -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=undefined -c ip.c
clang -fsanitize=undefined -o app.exe main.o ip.o -lm
