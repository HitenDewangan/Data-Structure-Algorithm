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

import heapq as pq

A = [2, 4, 6, 8, 10]

pq = he
for i in range(len(A)):
    pq.heappush(pq, -A[i])


ans = 0
for _ in range(len(A)):
    curr = pq.heappop(A)
    ans += curr
    pq.heappush(A, curr//2)

print(ans)