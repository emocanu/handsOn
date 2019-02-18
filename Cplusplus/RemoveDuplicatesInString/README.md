### RemoveDuplicatesInString

#### The problem

Given a string, there is a possible transformation that can be done on it using the following rule:\
The adjacent letters can be removed.\
For example, given "XYYZXZXZXY", using the transformation for the first match of "YY", the result is "XYYZXZXZXY".\
The transformation also applies recursively, if an adjacency is created by a previus transformation, that adjacency shall be removed too.\
Given the string: "XYZZXXY", the first transformation gives "XYXXY", then "XYY", then "X".

The assignment is to create a program that __efficiently__ ccomputes a string for an input string, using the above transformation.

#### The solutions

Four solutions are given in the source code, some of them being the refinement of previous solutions.
