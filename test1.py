from math import *
from collections import *
from sys import *
from os import *

## Read input as specified in the question.
## Print output as specified in the question.

n=int(input())
for i in range(1,n+1):
    for j in range(1,i+1):
        if j==i or j==1:
            print(i,end="")
        else:
            print("0",end="")
    print()