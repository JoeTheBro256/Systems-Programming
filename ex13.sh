#!/bin/bash

# Filename: ex13.sh
#
# Problem: Add writing to an array and reading from the array.

echo Please type in 3 foods you like:

val=""

array=()

for xx in `seq 1 3`; do
	read val
	array+=($val)
done


PS3='Now Select the food you like the best: '
select option in ${array[@]}
do
  echo "The option you have selected is: $option"
  break
done

