#!/usr/bin/env python

arr = [20, 12, 10, 15, 2]

for i in range(len(arr)-1):
    for j in range(i+1, len(arr)):
        if arr[i]>arr[j]:
            arr[i], arr[j] = arr[j], arr[i]

print(arr)
