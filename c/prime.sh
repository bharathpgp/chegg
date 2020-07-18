#!/bin/bash
rm -rf numbers
mkdir numbers
cd numbers
for i in $(seq 1 $((100+RANDOM%50))); do
for j in $(seq 1 $((10*i))); do
echo $j >> file$i.txt
done
done
cd ..
