#!/bin/sh

g++ "$1".cpp -o "$1"

rm "$1".log 1>/dev/null 2>&1

: $((tam=10000))
while [ "$tam" -le 500000 ]; do
	printf "Calculando para %d elementos...\n" "$tam"
	./"$1" "$tam" >> "$1".log

	: $((tam+=10000))
done
