#!/bin/bash

if [[ $2 == "valgrind" ]]; then
  clear && make $1 && echo "" && valgrind ./$@
else
  clear && make $1 && echo "" && ./$@
fi
