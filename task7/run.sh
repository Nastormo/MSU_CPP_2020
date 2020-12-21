#!/bin/bash
g++ map.cpp -o map
g++ -std=c++1z hint_map.cpp -o hint_map

echo "map"
time ./map
echo "hint map"
time ./hint_map
echo "Done"