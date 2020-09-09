#!/bin/bash

# Filename: ex19.sh
#
# Problem: Use awk to print the last field of every even numbered line from 
# ex19.input. 
cat ex19.input | awk '{
		#print $FNR
		FS=","
		if(FNR%2==0){
			print $NF
		}
	}'
