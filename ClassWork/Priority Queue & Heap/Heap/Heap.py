class Heap:
    def __init__(self):
        self.__l = []

    def __leftchild(self, p) -> int:
        return 2 * p + 1
    
    def __rightchild(self, p) -> int:
        return 2 * p + 2
    
    def __parent(self, p) -> int:
        return (p - 1) // 2

    def isEmpty(self) -> bool:
        return self.size() == 0
    
    def size(self) -> int:
        return len(self.__l)

    def push(self, value) -> int:  
        self.__l.append(value)
        index = len(self.__l) - 1

        while(index != 0 and self.__l[index] > self.__l[self.__parent(index)]):    # parent < child then swap 
            # pIndex = self.__parent(index)
            self.__l[index], self.__l[self.__parent(index)] = self.__l[self.__parent(index)], self.__l[index]

            index = self.__parent(index)

        return index

    def pop(self) -> int:
        if(self.isEmpty()):
            raise Exception("Heap is empty")
        
        self.__l[0], self.__l[-1] = self.__l[-1], self.__l[0]   # swap root and last

        value = self.__l.pop()   # pop last element
        index = 0

        while(self.__l[index] < self.__l[self.__leftchild(index)] or self.__l[index] < self.__l[self.__rightchild(index)]):
            curr, left, right = self.__l[index], -1, -1

            if(self.__l[self.__leftchild(index)] < len(self.__l)):   # if left child exists
                left = self.__l[self.__leftchild(index)]

            if(self.__l[self.__rightchild(index)] < len(self.__l)):  # if right child exists
                right = self.__l[self.__rightchild(index)]

            if(curr >= self.__l[self.__leftchild(index)] and curr >= self.__l[self.__rightchild(index)]):    # current is biggest
                break

            if(curr < left and left > right):  # left is bigger
                self.__l[index], self.__l[self.__leftchild(index)] = self.__l[self.__leftchild(index)], self.__l[index]
                index = self.__leftchild(index)  # go left
            else:    # right is bigger
                self.__l[index], self.__l[self.__rightchild(index)] = self.__l[self.__rightchild(index)], self.__l[index]
                index = self.__rightchild(index)  # go right

        return value


    def top(self) -> int:
        pass
    