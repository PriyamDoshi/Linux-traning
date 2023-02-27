#!/bin/bash
a=10
 
# a: variable is set
if [[ -v a ]];
then
    echo "variable named a is already set"
else
    echo "variable a is not set"
fi
 
# b: variable is not set
if [[ -v b ]];
then
    echo "variable named b is already set"
else
    echo "variable b is not set"
fi
