#!/bin/sh
clang-format -style=Google -i main.c || echo "EXIT_ERROR"
