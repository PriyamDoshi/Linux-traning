#!/bin/bash

#while loop
number=1
while [ $number -lt 10 ]
do
echo "$number"
 (( number++ ))
done
#unlil loop
num=1
until [ $num -lt 10 ]
do
echo "$num"
 (( num++ ))
done
