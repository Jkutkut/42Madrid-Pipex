#!/bin/sh

inputFile="tests/files/empty.txt"
outputFile="result.txt"

./pipex $inputFile cat "wc -l" $outputFile &&

{
	echo "It worked!"
	if [ -f $outputFile ]; then
		echo "Output file exists!"
		rm $outputFile
	else
		echo "Output file does not exist!"
	fi
} ||
{
	echo "It failed!"
	if [ -f $outputFile ]; then
		echo "Output file exists!"
		rm $outputFile
	else
		echo "Output file does not exist!"
	fi
}