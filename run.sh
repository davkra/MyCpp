#!/bin/bash

if [[ $2 == "valgrind" ]]; then
  clear && make $1 && echo "" && valgrind ./$1
else
  clear && make $1 && echo "" && ./$1
fi
