#!/bin/bash

x=$1
y=$2
COUNT=$#

if (($COUNT == 2)); then
    make re -C ./generator/
    ./generator/generator $x $y imperfect > ./map
    make re -C ./rpg/
    ./rpg/my_rpg
else
    make re -C ./generator/
    ./generator/generator $x $y > ./map
    make re -C ./rpg/
    ./my_rpg
fi
