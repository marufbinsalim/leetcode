#!/bin/bash

# Script to compile and run LeetCode problem solutions
# Usage: ./run_problem.sh <problem_number>

if [ $# -eq 0 ]; then
    echo "Usage: $0 <problem_number>"
    echo "Example: $0 98"
    exit 1
fi

PROBLEM_NUM=$1

# Find the problem directory matching the pattern problem_${PROBLEM_NUM}_*
PROBLEM_DIR=$(ls -d problem_${PROBLEM_NUM}_* 2>/dev/null | head -n 1)

if [ -z "$PROBLEM_DIR" ]; then
    echo "Error: No problem directory found for problem number $PROBLEM_NUM"
    echo "Available problems:"
    ls -d problem_* | sed 's/problem_//' | sort
    exit 1
fi

if [ ! -f "$PROBLEM_DIR/solution.cpp" ]; then
    echo "Error: solution.cpp not found in $PROBLEM_DIR"
    exit 1
fi

if [ ! -f "tree/tree.cpp" ]; then
    echo "Error: tree/tree.cpp not found"
    exit 1
fi

echo "Found problem directory: $PROBLEM_DIR"
echo "Compiling solution..."

# Compile the solution with tree.cpp
g++ "$PROBLEM_DIR/solution.cpp" tree/tree.cpp list/list.cpp -o "$PROBLEM_DIR/a.out"

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful! Running solution..."
echo "----------------------------------------"

# Run the compiled program
"$PROBLEM_DIR/a.out"

echo "----------------------------------------"
echo "Execution completed."

# Clean up the a.out file
rm "$PROBLEM_DIR/a.out"
echo "Cleaned up a.out file."