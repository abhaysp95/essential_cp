#!/usr/bin/env python

arr=[20, 12, 10, 15, 2];

start=0
while start<len(arr):
    midx=start
    for j in range(midx, len(arr)-1):
        if arr[j]>arr[j+1]:
            midx=j+1
    arr[start], arr[midx] = arr[midx], arr[start]
    start+=1

print(arr)
