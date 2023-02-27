#!/bin/bash
i=0
while [[ $i < 5 ]];
do
   ((i++))
   if [[ "$i" == '2' ]];
   then 
       continue
   fi
 
   echo "$i"
done       
       
      
