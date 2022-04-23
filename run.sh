#!/bin/sh

inputFile="Makefile"
outputFile="result.txt"

make

echo "----------------";

./pipex $inputFile "cat -e" "wc -l" $outputFile &&

{
	echo "----------------";
	echo "It worked!"
} ||
{
	echo "----------------";
	echo "It failed!"
}

if [ -f $outputFile ]; then
	echo "Output file exists!"
	# rm $outputFile
else
	echo "Output file does not exist!"
fi
