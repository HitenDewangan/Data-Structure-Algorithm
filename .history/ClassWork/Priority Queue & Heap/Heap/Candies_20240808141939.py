'''
============================================ INTERVIEW-BIT =============================================
T = 3
A = [2, 4, 6, 8, 10]

Every second you can pick any bucket i and eat all A[i] candies. After that bucket will be filled again with A[i]/2 candies(half of the original amount of candy).
Find the max no. of candies you can eat in T seconds

'''
class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        if len(A) == 0:
            return 0
        if len(A) == 1:
            return A[0]
        if len(A) == 2:
            return max(A[0], A[1])
        if len(A) == 3:
            return max(A[0]+A[2], A[1])
        
        for i in range(1, len(A)-1):
            A[i] = A[i-1]/2
        return max(self.solve(A[:-1]), self.solve(A[1:]))   
    
    