#!/bin/bash

y=$1
x=$2

count=$#

if (($count == 2)); then
    make re -C ./generator/
    ./generator/generator $y $x > map
    make re -C ./rpg/
    cd rpg
    ./my_rpg
else
    make re -C ./generator/
    ./generator/generator $y $x perfect > map
    make re -C ./rpg/
    cd rpg
    ./my_rpg
fi
