# CSC512 Course Project Part 3 - Integrated Seminal Input Feature Detection

## Overview
This is the final part of the course project which aims to integrate the key points collector and the seminal input feature detector into one cohesive unit. We are not utilizing any different libraries for this part. Here is a brief overview of how this program works:
1. Takes in a C file as inpus.
2. Invokes the key points detector to retrieve the key points and branch-pointer trace of the program.
3. Analyzes the branch-pointer trace to reveal where the program branched the most.
4. Invokes the seminal input feature detector to pinpoint the seminal input feature at the most encountered branch point.

## Example
Here is a quick example for this C program:
```c
#include <stdio.h>
#define read(x) scanf("%d", &x)
#define write(x) printf("%d\n", x)
#define print(x) printf(x)

int array[16];

void initialize_array(void) {
  int idx, bound;
  bound = 16;

  idx = 0;
  while (idx < bound) {
    array[idx] = -1;
    idx = idx + 1;
  }
}

int fib(int val) {
  if (val < 2) {
    return 1;
  }
  if (array[val] == -1) {
    array[val] = fib(val - 1) + fib(val - 2);
  }

  return array[val];
}

int main(void) {
  int idx, bound;
  bound = 16;

  initialize_array();

  idx = 0;

  print("The first few digits of the Fibonacci sequence are:\n");
  while (idx < bound) {
    write(fib(idx));
    idx = idx + 1;
  }
}
```
The KeyPointsCollector will find that the most encountered branch point is on line 24 stemming from line 23:
```c
 if (array[val] == -1) {
    array[val] = fib(val - 1) + fib(val - 2);
  }
```
Subsequently, the SeminalInputFeature detector will find that the seminal input feature assosiciated is ```val```, declared in the function definition for ```fib```:
```c
int fib(int val) {
```
Outputting:
```bash
Line 19: val
```

## Build and Usage
To build this project, ensure you have the following items installed on your system. (These should all be installed in the NCSU Ubuntu 22.04 LTS Image)<br>
- LibClang, this is a part of the LLVM Project, To build correctly, run the build script [here](https://github.com/NCSU-CSC512-Course-Project/part3-dev/blob/main/build_llvm.sh).
- Part 1 and Part 2 of the project, these can be retrieved with this [script](https://github.com/NCSU-CSC512-Course-Project/part3-dev/blob/main/pull_src.sh)

To build:
```bash
./build_llvm.sh
./pull_src.sh
make
```
To run, place test files in root directory.
```bash
make run
```
You will be given a singular prompt to enter the name of the file which is being tested. Any edited files created by the KPC will be written to the out directory. Below is an example of the full shell output for the above program.
```
➜  part3-dev git:(main ↑1) make run
rm -f out/*
mkdir -p bin bin/objs out
g++  bin/objs/Integrated.o  bin/objs/KeyPointsCollector.o  bin/objs/main.o  bin/objs/SeminalInputFeatureDetector.o -O0 -g3 -std=c++17 -lclang -o bin/Integrated
bin/Integrated
Enter a file name for analysis: TF_1_fib.c
Translation unit for file: TF_1_fib.c successfully parsed.
Translation unit for file: TF_1_fib.c successfully parsed.
C compiler is: gcc
Compilation Successful
The most encountered branch point is: 23
The Seminal Input Feature of this program is:
Line 6: array
```
# Testing (For Grader)
All our chosen test files are prefixed with TF in the root directory, TF_3_SPEC.c is the chosen SPEC program for our testing.

