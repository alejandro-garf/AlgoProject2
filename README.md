# 🎃 Alejandro Fonseca & Leonardo Nava  
# CPSC 335 - Algorithm Engineering Project 2  
## Trick-or-Treat House Wait Times (Algo 1) & Haunted House Duplicate Clues (Algo 2)

---

## Overview
This project solves two Halloween-themed problems using **stack-based** and **linked list cycle detection** techniques:

- **Algorithm 1:** Determines how many houses you must visit to find more candies.
- **Algorithm 2:** Detects the duplicate clue causing an infinite haunted loop.

---

## Prerequisites
To compile and run these C++ programs, you will need:

- A **C++ compiler** (e.g., `g++` for GCC).
- A command-line terminal.

---

## Installation & Compilation

### 1. Clone the Repository
```bash
git clone https://github.com/alejandro-garf/AlgoProject2.git
cd AlgoProject2
2. Compile Both Programs
bash
Copy
Edit
g++ -o wait_houses wait_houses.cpp
g++ -o find_duplicate_clue find_duplicate_clue.cpp
3. Run the Programs
bash
Copy
Edit
./wait_houses
./find_duplicate_clue
Usage
Algo 1: Trick-or-Treat House Wait Times
Input the number of houses.

Input the candies at each house.

Output will display the wait times array showing how many houses until a better candy house appears.

Algo 2: Haunted House Duplicate Clues
Input the number of rooms (n + 1 clues, where one clue is duplicated).

Input the clue values in order.

Output will reveal the duplicated clue.

Example Test Cases
🎃 Wait Houses
Input:

Copy
Edit
8
3 5 8 2 1 4 10 6
Output:

Copy
Edit
1 1 4 2 1 1 0 0
👻 Duplicate Clues
Input:

Copy
Edit
5
5 3 4 7 7
Output:

csharp
Copy
Edit
Duplicate clue is: 7
Efficiency Summary

Algorithm	Time Complexity	Space Complexity
Wait Houses	O(n)	O(n)
Duplicate Clues	O(n)	O(1)
Authors
Alejandro Fonseca - gfon@csu.fullerton.edu

Leonardo Nava - leonava24@csu.fullerton.edu
