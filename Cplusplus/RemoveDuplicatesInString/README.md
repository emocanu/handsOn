### RemoveDuplicatesInString

#### The problem

Given a string, there is a possible transformation that can be done on it using the following rule:\
The adjacent letters can be removed.\
For example, given "XYYZXZXZXY", using the rule for the first match of "YY", the result is "XZXZXZXY".\
The transformation also applies recursively, if an adjacency is created by a previous transformation, that adjacency shall be removed too.\
Given the string: "XYZZXXY", the first rule gives "XYXXY", then "XYY", then "X".

The assignment is to create a program that __efficiently__ ccomputes a string from an input string, using the above transformation.

#### The solutions

Four solutions are given in the source code, some of them being the refinement of previous solutions.
