#!/usr/bin/env python3

"""
ArrayClient.py import the Array class from the Array.py module and 
exercises the class methods.
"""

import Array

maxSize = 10 
arr = Array.Array(maxSize)   # allocate 10 element array

# insert 10 items 
arr.insert(77)
arr.insert(99)
arr.insert("foo")
arr.insert("bar")
arr.insert(44)
arr.insert(55)
arr.insert(12.34)
arr.insert(0)
arr.insert("baz")
arr.insert(-17)

# exercise traverse
print(f"Array containing {len(arr)} items")
arr.traverse()   # print by default

# exercise search
print(f"Search for 12 returns: {arr.search(12)}")
print(f"Search for 12.34 returns: {arr.search(12.34)}")

# exercse deletion 
# we've fixed the error
print(f"Deleting 0 return {arr.delete(0)}")
print(f"Deleting 17 return {arr.delete(17)}")

print(f"Array after deletions has {len(arr)} items")