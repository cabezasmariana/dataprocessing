# Extracredit - Dataprocessing and Storage

-----------------------------------------------------------------------------------------

## Overview
This C++ project creates an in-memory database that supports key-value storage
with transaction functionalities. Users can add, retrieve, and manage data through
transaction-based operations like starting, committing, and rolling back changes.
The database ensures data remains consistent and provides a simple way to handle complex
data modifications, similar to how financial systems protect against partial or failed
transactions.

-----------------------------------------------------------------------------------------

## How to Run the Code

### Prerequisites
1. A C++ compiler.
2. A terminal/command prompt to be able to execute commands.

### Steps to Compile and Run
1. Compile the code using the following command:
   g++ -std=c++17 -o ec ec.cpp
   
2. Run the compiled program using the following command:
   ./ec

3. Functionality is tested within main, observe results via terminal.

-----------------------------------------------------------------------------------------

## Suggestions for Improvement

To improve the assignment, the course instructions could benefit from clearer guidelines
about handling edge cases. For example, the guidelines should explain what happens
when students try to perform actions on an empty database or start a new transaction while
one is already running. Including guidance on managing concurrent transactions would also
make the project more practical and challenging. Providing a set of automated test cases
would help ensure fair and consistent grading, giving students a clear understanding of
the expected implementation and making the assessment process more straightforward.

-----------------------------------------------------------------------------------------
## Sources
- https://www.dbvis.com/thetable/database-transactions-101-the-essential-guide/
- https://medium.com/@mithoonkumar/design-an-in-memory-nosql-database-ood-428d48b68dfa
- https://www.geeksforgeeks.org/java-util-hashmap-in-java-with-examples/
- https://www.geeksforgeeks.org/python-dictionary/ 
