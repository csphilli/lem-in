#!/bin/bash
# Calculates the average run time of map type based on 20 iterations each.
GEN="./generator"
TEST="./lem-in"
FLAG=" --flow-one"
SRC="cat file.txt"
OUTPUT="cat timedump.txt"
I=0
TOTAL=0
AVG=0
avg() { awk "BEGIN{print $*}"; }
echo "MAP			:	AVG TIME" >> time.txt
while [ $I -lt 100 ]
do
	$GEN $FLAG > file.txt
	$TEST < file.txt > timedump.txt
	calc1=$($OUTPUT | tail -n 1)
	echo $I: $calc1
	TOTAL=$(echo "$TOTAL + $calc1" | bc)
	I=$(( $I+1 ))
	if (( I % 20 == 0))
	then
		AVG=$(bc <<<"scale=4;$TOTAL/20")
		echo "$FLAG : " $AVG >> time.txt
		TOTAL=0
		AVG=0
	fi
	if ! ((I % 20 ))
	then
		case $I in
			20) FLAG=" --flow-ten";;
			40) FLAG=" --flow-thousand";;
			60) FLAG=" --big";;
			80) FLAG=" --big-superposition";;
		esac
	fi
done
