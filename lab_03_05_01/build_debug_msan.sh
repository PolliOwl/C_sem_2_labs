#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=memory -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=memory -c matrix.c
clang -fsanitize=memory -o app.exe main.o matrix.o -lm
