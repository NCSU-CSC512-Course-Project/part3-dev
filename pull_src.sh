#!/bin/bash

git clone https://github.com/NCSU-CSC512-Course-Project/part1-dev.git
git clone https://github.com/NCSU-CSC512-Course-Project/part2-dev.git

cp part1-dev/kpc/Key* ./integrated
cp part1-dev/kpc/Common.h ./integrated
cp part2-dev/src/Sem* ./integrated

rm -rf part1-dev
rm -rf part2-dev
