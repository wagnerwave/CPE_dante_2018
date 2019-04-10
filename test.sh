#!/bin/bash

./generator/generator 10000 10000 > map
./solver/solver map > solving
