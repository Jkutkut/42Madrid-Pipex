#!/bin/sh

inputFile="Makefile"
outputFile="result.txt"

make

echo "----------------";
# ./pipex $inputFile "cat -e" "wc -l" $outputFile &&
./pipex $inputFile "cat -e" "grep Wall" "wc -l" $outputFile &&

{
	echo "----------------";
	echo
	echo "It worked!"
} ||
{
	echo "----------------";
	echo
	echo "It failed!"
}

if [ -f $outputFile ]; then
	echo "Output file exists"
	echo
	echo "----------------$outputFile----------------";
	cat $outputFile
	echo "----------------$outputFile----------------";
	rm $outputFile
else
	echo "Output file does not exist!"
fi

ps -lf