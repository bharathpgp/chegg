#!/bin/bash
if [ "$#" -eq 0 ]; then
while :
do
echo "Enter a directory path :"
read dir
if [ -d "$dir" ]; then
break
else
echo "Not Valid path"
continue
fi
done
else
dir = "$1"
fi
if [ -d "$dir/Data" ]; then
echo "Data directory already exist! \ncancel(c)/overwrite(o)"
read choice
if [ "$choice" = "c" ]; then
return
else
mkdir -p $dir/Data
mkdir -p $dir/Data/Image
mkdir -p $dir/Data/Cach
return
fi
fi
mkdir $dir/Data
mkdir $dir/Data/Image
mkdir $dir/Data/Cach