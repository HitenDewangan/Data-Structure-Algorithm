'''
============================================ INTERVIEW-BIT =============================================
T = 3
A = [2, 4, 6, 8, 10]

then ans = 24 (10+8+6 = 24)

Every second you can pick any bucket i and eat all A[i] candies. After that bucket will be filled again with A[i]/2 candies(half of the original amount of candy).
Find the max no. of candies you can eat in T seconds

'''
# since at every second we need bucket with max candies, we use heap

# min log(n) is of heap
# max log(n) is of multi_set

import heapq

# logic for this question

# we will use max heap
# we will use multiset