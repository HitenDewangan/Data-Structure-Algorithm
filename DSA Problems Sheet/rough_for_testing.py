#this file is to run the test cases

# Codeforces : Yet Another Broken Keyboard 
# https://codeforces.com/contest/1272/problem/C


n, k = map(int, input().split())  # n = size of string  & k = no. of available letters on keyboard

string = input()

avail_letters = set(input().split(" "))        # to store the letters separately as set elements

index = set()      # to store index of characters from string that are not in available_letters

last_found_at = 0
for i in range(n):
    if string[i] not in avail_letters:
        last_found_at = i
        index.add(string.index(string[i], last_found_at))

sum = 0      # to count the total no. of substrings we can make with available_characters
curr_start = 0    # to store the index from where we have to make substring
for i in range(n):
    if i in index:
        curr_start = i+1

    else:
        sum += (i - curr_start + 1)

print(n, k, sep="#")
# print(available_letters)
print(avail_letters)
print(string)
print(index)
print(sum)

#Time Complexity : O(n)
#Space Complexity : O(n)