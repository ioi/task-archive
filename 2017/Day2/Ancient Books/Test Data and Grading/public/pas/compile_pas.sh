#!/bin/bash

problem=books

fpc -XS -O2 -o$problem grader.pas
