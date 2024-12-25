#!/usr/bin/env python

arr=[20, 12, 10, 15, 2];

for i in range(1, len(arr)):
    key,j=arr[i],i-1
    while j>=0 and key<arr[j]:
        arr[j+1]=arr[j]
        j-=1
    arr[j+1]=key


print(arr)
