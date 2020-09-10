#!/bin/bash

# Filename: ex21.sh
#
# Problem: Count the number of quotes each person had in the top 100 quote
# list. Then output the list of names in alphabetical order with the number of quotes each.
cat ex21.input | gawk '{


		if (match($0,"-")) {
			name=substr($0,0,match($0,"-")-1);
			names[name]++;
		}
	}
	END {
			n = asorti(names,namesi)
			#print n
			for (i=1;i<=n;i++){
				print namesi[i] "had", names[namesi[i]],"quotes."
			}
}'
