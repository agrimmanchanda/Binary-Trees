# Binary-Trees
Create a binary tree from a given Boolean function 

To compile, enter on command line: g++ main.cpp -o main 

To run, enter on command line: ./main

With a specified Boolean function, the program takes as inputs the values of X1, X2...XN which would produce a 1 in the truth table. 

For example, for X1 & X2: the input vector would be 11 because they 1 & 1 = 1. 

Likewise for X1 OR X2: the input vectors would be 01, 10, 11 because they all result in 1 for truth table. 

The program generates a binary tree for this representation. This is done by placing in the roots the strings "X1", "X2" ..."XN". 

The two subtrees of each root will then signify that the root value is 0 or 1 respectively for the left and right subtree. 

The leaves signify whether the value is 0 or 1 depending on boolean function, so for example with X1 & X2:

                                                  X1 
      
                                            X2          X2 
                                          0   0       0   1
