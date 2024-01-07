#!/bin/bash

# Generate a list of random numbers
NUMS=$(jot -r -s " " 100 1 100)

# Feed the numbers to push_swap and capture the output
COMMANDS=$(echo $NUMS | ./push_swap)

# Feed the commands to checker
RESULT=$(echo $COMMANDS | ./checker $NUMS)

# Print the result
echo $RESULT
