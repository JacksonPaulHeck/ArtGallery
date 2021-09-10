# Fall 2021 CS 3353 PA 01 Template Repo

## Introduction

This is the repository for program 1 in the Fall 2021 Algorithms Class at Southern Methodist University.

Created by Jackson Paul Heck and Garrett Webb

## Description of Problem

You are tasked with figuring out a better way for a gallery to place rectangular art on a wall. 

- The wall is defined by a given Width and Height.
- Each picture is defined by a given ID, Price, Width, and Height.

Given a set of potential art pieces that could be displayed on the wall, determinea placement for a subset of art pieces such that if all the pieces sold it would maximize profit.

## Three Input Algorithms

Our three input algorithms are
- Brute Force: Run through every possible permutation of the wall, and find the most profitable one
- Highest Value First: Start by placing the most expensive picture first
- Cost-Size Ratio: Place pictures in order of cost-size ratio, starting with largest ratio

## How to Build/Execute

- Navigate into project folder "21f-pa01-jp-and-garretts-cool-kids-team"
- Run ```g++ -g src/main.cpp src/picture.cpp src/gallery.cpp``` to compile the project
- Run ```./a.out ./test/input.txt ./output/test-bruteforce.txt ./output/test-highvalue.txt ./output/test-custom.txt```

## Sample I/O

Input:
```
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
```

test-custom.txt Output:
```
    1900
    8 1000 1 1 0 0
    6 250 123 10 1 0
    5 330 10 700 124 0
    4 100 100 100 134 0
    2 200 300 100 234 0
    7 20 838 70 134 100
```

## Placement Algorithm

We used a version of the 2D Rectangular Bin Packing problem to solve the issue of how to place the pictures of various sizes on the canvas. Originally we began with a brute force implementation. It was simple to write but it had a major downfall: speed. Running some calculations, an input file of 10 pictures and a wall of size 1000x1000 would have taken 35.7 days to run. 

A much better solution was to implement a binary-tree like algorithm that splits the canvas into two rectangles and places the image into one of those rectangles. This cut the time to about 30 seconds.

## Performance Write-Up

Three algorithms are implemented for input into the canvas.
1. Brute Force
2. Highest Value First
3. Ratio (Price/Area)

The Brute Force algorithm is the most optimal as it will 100% of the time generate the best possible input configuration maximizing profit. This is done by creating a set of all possible permutations of a given set, creating a potential gallery for each of those sets, and choosing the one that has the highest total price. However, this algorithm runs in O(n!) time where n is the number of pictures to be placed on the wall. Which means given a dataset of more than 10 pictures, it will take a long time to run.

The Highest Value First algorithm is sub-optimal but still will generate a set that could potentially have the highest total price. It does this by first sorting the pictures from highest to lowest price without regard to size. One pitfall with this algorithm is for example an input set like:
```
1000
1000
3
1 1000 1000 1000
2 400 250 250
3 400 250 250
4 400 250 250
```
the optimal algorithm would pick and place pictures 2, 3, and 4 giving a total price of 1200. The Highest Value First algorithm would pick only picture 1 only giving a total price of 1000.However, this algorithm runs in O(n<sup>2</sup>) time given that the sorting algorithm used is selection sort.

The Ratio algorithm is again a sub-optimal but still will generate a set that could produce a set that has a high total price. This is done again through sorting the input values. They are sorted by calculating the ratio between Price and Total Area. By first inserting the picture with the highest ratio, the price will increase signifigantly while the area taken up on the canvas will be minimized. It also uses the selection sort giving it a time of O(n<sup>2</sup>) as well.
