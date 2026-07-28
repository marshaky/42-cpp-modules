#!/bin/bash

# Function to compile and run the converter program with the given argument
check_input() {
    echo "Input: $1"
    ./converter "$1"
    echo "-----------------------------------"
}

# Compile the converter program
make

# Check various inputs
check_input "a"
check_input "b"
check_input "0"
check_input "42"
check_input "-42"
check_input "42.42"
check_input "-42.42"
check_input "42.42f"
check_input "-42.42f"
check_input "42.42ff" # Invalid input
check_input "42.42f1"  # Invalid input
check_input "inf"
check_input "+inf"
check_input "-inf"
check_input "inff"
check_input "+inff"
check_input "-inff"
check_input "nan"
check_input "nanf"
check_input "9999999999999999999999999999999999999" # Overflow
check_input "-99999999999999999999999999999999999999999999999999999999999999999999999999999999999" # Overflow

# Clean up
make fclean
