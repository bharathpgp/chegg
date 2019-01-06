#!/bin/bash #========================================================================
# Script Name: # By:
# Date:
# Purpose:
#phmenu your initials here
#February 2009
#A menu for the Corporate Phone List
# Command Line: phmenu #======================================================================== trap "rm ./f 2> /dev/null; exit" 0 1 3
phonefile=~/source/corp_phones
loop=y
while test $loop = "y"
do
clear
tput cup 3 12; echo "Corporate Phone Reporting Menu"
tput cup 4 12; echo "===============================" #tput cup 6 9; echo "P - Print Phone List"
tput cup 7 9; echo "A - Add New Phones"
tput cup 8 9; echo "S - Search for Phones"
tput cup 9 9; echo "V - View Phone List"
tput cup 10 9; echo "D - Delete Phone"
tput cup 12 9; echo "Q - Quit: "
tput cup 12 19;
read choice || continue
case $choice in
[Aa]) ./phoneadd ;;
[Pp]) ./phlist1 ;;
[Ss]) ./phonefind ;;
[Vv]) clear ; less $phonefile ;;
[Dd]) tput cup 16 4; echo "Delete Phone Record"
tput cup 17 4; echo "Phone: "
tput cup 17 11; read number
tput cup 18 4; echo "Accept? (y)es or (n)o: " tput cup 18 27; read Accept
if test $Accept = "y"
then
sed /$number/d $phonefile > f cp f $phonefile
rm f fi
#;;
[Qq]) clear ; exit ;;
*) tput cup 14 4; echo "Invalid Code"; read choice ;; esac
done
