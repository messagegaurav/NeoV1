#!/bin/sh
echo "Running Valgrind for memory leaks ..... \n\r";
file=$1
valgrind  "./"$file    