#!/bin/python3
import copy
import math
from math import *
from operator import and_
import sys, csv


def myAtoi(string):
    res = 0
 
    for i in range(len(string)):
        res = res * 10 + (ord(string[i]) - ord('0'))
 
    return res

def generate(filename):
    new_filename = open(filename, "w+")
    
    x = input("Enter score to check level 1:\n")
    strx = myAtoi(x)
    while(strx == 0):
        x = input("Enter score to check level 1:\n")
        strx = myAtoi(x)
        
    new_filename.write(x)
    new_filename.write(" ")
    
    x = input("Enter ennemy 1 for level 1 (0 | 1 | 2 | 3):\n")
    strx = myAtoi(x)
    while (strx < 0 and strx > 3):
        x = input("Enter ennemy 1 for level 1 (0 | 1 | 2 | 3):\n")
        strx = myAtoi(x)

    new_filename.write(x)
    new_filename.write(" ")
    y = input("Enter ennemy 2 for level 1 (0 | 1 | 2 | 3):\n")
    stry = myAtoi(y)
    while (stry < 0 and stry > 3 and stry == x):
        y = input("Enter ennemy 2 for level 1 (0 | 1 | 2 | 3):\n")
        stry = myAtoi(y)

    new_filename.write(y)
    new_filename.write(" \n")
    
    x = input("Enter BOSS for level 1 ( 1 | 2):\n")
    strx = myAtoi(x)
    while (strx < 1 and strx > 2):
        x = input("Enter BOSS for level 1 ( 1 | 2):\n")
        strx = myAtoi(x)

    new_filename.write(x)
    new_filename.write(" \n")
    
    
    x = input("Enter score to check level 2:\n")
    strx = myAtoi(x)
    
    while(strx == 0):
        x = input("Enter score to check level 2:\n")
        strx = myAtoi(x)

    new_filename.write(x)
    new_filename.write(" ")
    
    x = input("Enter ennemy 1 for level 2 (0 | 1 | 2 | 3):\n")
    strx = myAtoi(x)

    while (strx < 0 and strx > 3):
        x = input("Enter ennemy 1 for level 2 (0 | 1 | 2 | 3):\n")
        strx = myAtoi(x)

    new_filename.write(x)
    new_filename.write(" ")
    y = input("Enter ennemy 2 for level 2 (0 | 1 | 2 | 3):\n")
    stry = myAtoi(y)

    while (stry < 0 and stry > 3 and stry == strx):
        y = input("Enter ennemy 2 for level 2 (0 | 1 | 2 | 3):\n")
        stry = myAtoi(y)

    new_filename.write(y)
    new_filename.write(" \n")
    
    x = input("Enter BOSS for level 2 ( 1 | 2):\n")
    strx = myAtoi(x)

    while (strx < 1 and strx > 2):
        x = input("Enter BOSS for level 2 ( 1 | 2):\n")
        strx = myAtoi(x)

    new_filename.write(x)
    new_filename.write(" \n")
    
    new_filename.close()
    
def main():
    generate(sys.argv[1])

main()