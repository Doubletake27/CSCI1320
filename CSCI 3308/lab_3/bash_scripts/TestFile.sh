#!/bin/bash
# Author : Your Name
# Date: Today's date
# Script follows here:
# Lab 3, CSCI 3308
# TestFile.sh
# Author: Henry Meyerson
# Date: 2/8/2021
clear
# This is for Testing
echo "Program Started Sucessfully"

# ---- Function Declarations
# count_lines()
count_lines(){
	echo "Counting Lines:"
	lineCount=$(egrep -c "*" $FILE)
	echo "  $lineCount"
}
# count_words()
count_words(){
	echo "Counting Words:"
	# Lorem
	lorem=$(egrep -io "Lorem" $FILE | wc -l)
	lorem1=$(egrep -in "Lorem" $FILE | cut -f1 -d:)
	sed -in '/lorem/=' $FILE
	echo "  Lorem: $lorem"
	echo "$lorem1"
	# model 
	model=$(egrep -io "model" $FILE | wc -l)
	echo "  Model: $model"
	egrep -in "Model" $FILE | cut -f1 -d:
	# Ipsum
	ipsum=$(egrep -io "ipsum" $FILE | wc -l)
	echo "  Ipsum: $ipsum"
	egrep -in "Ipsum" $FILE | cut -f1 -d:
	# will
	will=$(egrep -io "will" $FILE | wc -l)
	echo "  Will: $will"
	egrep -in "Will" $FILE | cut -f1 -d:
	#echo "Lines they are found on:"
	#egrep -n "will" $FILE | cut -f1 -d:
}
# add_text()
add_text(){
	echo "Adding Text:"
	
}
# copy_and_exit()
copy_and_exit(){
	echo "Copying and Exiting:"
	
}
# ---- END Function Declarations


# Send in sample_text.txt
FILE=sample_text.txt

# Check if file sample_text exists
if [[ -f "$FILE" ]]; then
	echo "$FILE exists"
else 
	echo "$FILE does not exist"
	exit
fi

count_lines
count_words

# Menu is contained within a loop
	# Display a menu - Each should call a function
		# count_lines()
		# count_words()
		# add_text()
		# copy_and_exit()
