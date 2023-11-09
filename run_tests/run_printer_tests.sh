#!/bin/sh

for testfile in test/printer/good*.bminor
do
	./bminor --print $testfile &> $testfile.out
done

