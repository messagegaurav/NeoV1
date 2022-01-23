#!/bin/sh
echo "Running Valgrind for memory leaks ..... \n\r";
file=$1
valgrind --leak-check=full "./"$file
    