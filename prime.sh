#! /usr/bin/bash

Num=2
Count=0
IsPrime=1
m=0

echo "Frist 20 prime numbers"

while [ $Count -lt 20 ];
	do
	(( IsPrime = 1 ))
	n=$(( Num - 1 ))
	while [ $n -ge 2 ];
		do
		m=$(( Num % n ))
		if [ $m == 0 ]
		then
			(( IsPrime = 0 ))
		fi
		(( n -= 1));
	done
	
	if [ $IsPrime == 1 ]
	then
		echo $Num
		(( Count += 1 ))
	fi

	(( Num += 1 ));
	
done
