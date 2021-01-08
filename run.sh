#!/bin/sh
# This uses a -q flag to surpress the graph printing within lem-in program.
# Add this file to where your lem-in executable will be located.
# The program 'generator' must also be included and at the same location.
GEN="./generator"
LEM="./lem-in"
flag=" --flow-one"
declare -i J=1
declare -i I=0
declare -i AVG=0
declare -i MAX=0
declare -i MIN=0
FREQ=0
AVG_FREQ=0

while [ $J -lt 10 ]
do
	echo "ITERATION $J" >> output.txt
	while [ $I -lt 500 ]
	do
		MAP=$($GEN $flag > file.txt)
		declare -i EXP=$(cat file.txt | tail -n 1 | cut -d ' ' -f 8)
		declare -i FILE=$(cat file.txt | wc -l)
		declare -i LINES=$($LEM -q < file.txt | wc -l)
		declare -i DIFF=$(($LINES - $EXP))
		echo "I: $I | MINE: $LINES | EXPECTED $EXP | DIFFERENCE $DIFF"
		AVG=$[$AVG+$DIFF]
		if [ $DIFF -gt 10 ]
		then
			FREQ=$[$FREQ+1]
		fi
		if [ $DIFF -gt $MAX ]
		then
			MAX=$DIFF
		fi
		if [ $DIFF -lt $MIN ] && [ $LINES -ne 0 ]
		then
			MIN=$DIFF
		fi
		# if [ $LINES -eq 0 ]
		# then
		# 	exit
		# fi
		I=$[$I+1]
		if ! ((I % 100))
		then
			echo "	$flag" >> output.txt
			echo "	AVERAGE		: $[$AVG/100]" >> output.txt
			echo "	MIN DIFF    : $MIN" >> output.txt
			echo "	MAX DIFF	: $MAX" >> output.txt
			AVG_FREQ=$(bc <<<"scale=4;$FREQ/100")
			echo "	% FREQ > 10 :" $AVG_FREQ >> output.txt
			MAX=0
			MIN=0
			AVG=0
			AVG_TIME=0
			FREQ=0
			AVG_FREQ=0
			case $I in
				100) flag=" --flow-ten";;
				200) flag=" --flow-thousand";;
				300) flag=" --big";;
				400) flag=" --big-superposition";;
				500) flag=" --flow-one";;
			esac
			echo "_________________________"
		fi
	done
	I=0
	J=$[$J+1]
	sleep 120
done

