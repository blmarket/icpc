#!/bin/bash

problem=aliens

g++ -O2 -std=c++11 -static -o $problem grader.cpp $problem.cpp
