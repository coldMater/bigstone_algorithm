filename="$1" # problem number e.g., "1K_2312"
iocount="$2" # count of input, output set 

touch ""$filename".cpp"

for i in $(seq 1 $iocount)
do
    touch ""$filename"_"$i"_input.txt"
    touch ""$filename"_"$i"_output.txt"
done