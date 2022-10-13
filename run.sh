#!/bin/sh

inputFile="Makefile"
outputFile="result.txt"

make

echo "./pipex $inputFile \"cat -e\" \"wc -l\" $outputFile"
# echo "./pipex here_doc end \"grep a\" cat cat cat cat \"wc -l\" $outputFile"

echo "----------------";


# valgrind --leak-check=full \
#          --show-leak-kinds=all \
#          --track-origins=yes \
#          --verbose \
#          --log-file=valgrind-out.txt \
#          ./executable exampleParam1

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
./pipex $inputFile "notexisting" "wc" $outputFile &&
# ./pipex $inputFile "cat -e" "hostname" $outputFile &&
# ./pipex $inputFile "cat -e" "wc -l" $outputFile &&
# ./pipex here_doc end "grep a" "wc -l" $outputFile &&
# ./pipex $inputFile "cat -e" "grep Wall" "wc -l" $outputFile &&
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
