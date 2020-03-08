# Tölvunarfræði 2

Projects from the course Tölvunarfræði 2 (Computer science 2). The course used Java and C++. Some of the Java classes use methods in classes from the [algs4 collection by princeton](https://algs4.cs.princeton.edu/code/).

### Upprifjun

Review at the end of the semester.

1.  Java method reverseStack. Accepts a stack and returns a stack with the same components but in reversed order.
2.  Java method farthestM. Accepts a bag of 2D points and integer m. The method calculates the distances from the origin and returns the m greates distances.
3.  C++ method insertion. Insertion sort for std::vector of int.

### 11. Verkefni

1. Java class v1. Uses the algs4 function DijkstraSP on the graph from mEWG.txt and writes out the distance from vertex 0 to vertecies 168, 200 & 201.

### 8. Verkefni

1. & 2. Add delete and swap to the Java class SinglyLinkedList. The delete method deletes a node in a singly linked list by its number and connects the list so its only missing one node. The swap method swaps the position of two nodes in a Singly Linked List.
2. C++ heapsort. The methods exch, lesss and sink needed for heapsort, finally connected together into a functioning heapsort method.

### 7. Verkefni

1. Itterative implementation of the min() and max() methods for the Java class BTS.
2. Java class v2 that measures how long it takes to look up a integer with BinarySearchST.java and prints out a plot. I start from 50.000 and go up to 5.000.000, jumping 50.000 each iteration.
3. C++ program BST. Binary search tree that suports the methods put and contains.

### 5. Verkefni

1. Java class MoreRandom. Wrote the method getRandomDoubleArray that makes a matrix of random Doubles.
2. Java class PlotRunningTimes. Plots out the time it takes to insertion sort matrices that contain 0-5000 numbers.
3. Java class SortingCompetition. Compairs the time insertion sort takes to the time it takes to merge sort. Insertion is better for small martices but around 73 components merge sort is faster.

### 4. Verkefni

1. Implementation of iterable for the Java class ArrayList.
2. Java class Hanoi that writes out all steps needed to solve the tower of Hanoi problem.
3. C++ class stack. Made for stacks of int, uses singly linked list.

### 3. Verkefni

1. Finnishing the Java class Fraction. Implementing Compairable for equals method and compareTo method.
2. Finnishing the Java class SinglyLinkedList.
3. C++ method reverse for the class SinglyLinkedList.

### 2. Verkefni

1. C++ method vector. Reads in numbers, the method collects them into a std::vector of double and then writes out the median and variance.
2. Finnishing the C++ class SinglyLinkedList. Added the method prepend that adds a node to the front of a list, Overoad for [] to get a node by number and a destructor for the class.
3. Finnishing the C++ class fraction. Overload for \* to allow mulitiplication of fractions, constructor for MixedFractions and overload for << to write out MixedFractions propperly.

### 1. Verkefni

1. C++ method swap. Takes in int pointers and swaps the values they point to.
2. Finnishing the C++ class fraction. Added cerr for denominator of 0, display method, plus method and reduce method.
3. C++ methods length & search. Length takes in a pointer to the first node in a singly linked list and returns the length of the list. Search takes in a pointer to the first node in a singly linked list and a integer, returns a pointer to the first node that contains the integer or the null pointer.

### 0. Verkefni

1. C++ method halloheimur. Classic Hello World.
2. C++ method v2. Reads in numbers from the user and returns the sum and average.
