#!/bin/sh

cat < input | wc -l > output ||
echo "error"
< $0 cat | wc -l > output
