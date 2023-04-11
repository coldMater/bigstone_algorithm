#!/bin/bash

problemNum="$1" # problem number e.g., "1K"
bjNum="$2"
filename="${problemNum}_${bjNum}"
iocount="$3" # count of input, output set 

echo "// https://www.acmicpc.net/problem/${bjNum}" >> ""$filename".cpp"

for i in $(seq 1 $iocount)
do
    touch ""$filename"_"$i"_input.txt"
    touch ""$filename"_"$i"_output.txt"
done