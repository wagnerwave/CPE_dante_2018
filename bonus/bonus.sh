#!/bin/bash

x=$1
y=$2
count=$#
imperfect=2

if [$count == $imperfect]
then
    make re -C ./generator/
    ./generator/generator $x $y imperfect > ./map
    make re -C ./rpg/
    ./rpg/my_rpg
else
    make re -C ./generator/
    ./generator/generator $x $y > ./map
    make re -C ./rpg/
    cd rpg
    ./my_rpg
fi
