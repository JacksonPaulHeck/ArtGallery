# Fall 2021 CS 3353 PA 01 Template Repo

## Introduction

This is the repository for program 1 in the Fall 2021 Algorithms Class at Southern Methodist University.

Created by Jackson Paul Heck and Garrett Webb

## Description of Problem

You are tasked with figuring out a better way for a gallery to place rectangular art on a wall. 

- The wall is defined by a given Width and Height.
- Each picture is defined by a given ID, Price, Width, and Height.

Given a set of potential art pieces that could be displayed on the wall, determinea placement for a subset of art pieces such that if all the pieces sold it would maximize profit.

## Three Placement Algorithms

Our three placement algorithms are
- Brute Force: Run through every possible permutation of the wall, and find the most profitable one
- Highest Value First: Start by placing the most expensive picture first
- Cost-Size Ratio: Place pictures in order of cost-size ratio, starting with largest ratio

## How to Build/Execute

- Navigate into project folder "21f-pa01-jp-and-garretts-cool-kids-team"
- Run "g++ -g src/main.cpp src/picture.cpp src/gallery.cpp" to compile the project
- Run "./a.out ./test/input.txt ./output/test-bruteforce.txt ./output/test-highvalue.txt ./output/test-custom.txt"

## Sample I/O

Input:
  1024 768
  8
  1 300 1023 767
  2 200 300 100
  3 250 800 700
  4 100 100 100
  5 330 10 700
  6 250 123 10
  7 20 838 70
  8 1000 1 1

test-custom.txt Output:
  1900
  8 1000 1 1 0 0
  6 250 123 10 1 0
  5 330 10 700 124 0
  4 100 100 100 134 0
  2 200 300 100 234 0
  7 20 838 70 134 100

## Performance Write-Up
