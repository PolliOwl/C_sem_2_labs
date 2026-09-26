#!/bin/bash
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=memory -c main.c
clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g3 -fsanitize=memory -c ip.c
clang -fsanitize=memory -o app.exe main.o ip.o -lm
