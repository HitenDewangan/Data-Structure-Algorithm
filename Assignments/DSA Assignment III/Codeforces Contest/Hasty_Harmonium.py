s = input()

if(len(s) == 2 and s[0] <= s[1]):
    print(s)
else:
    store = "zzzz"
    for i in range(len(s)-1):
        for j in range(i+1, len(s)):
            if(store > (s[i] + s[j])):
                store = s[i] + s[j]
    

    print(store)


# time limit can exceed for large input, check cpp solution given 