class Node:
    def __init__(self, data, prev = None, next = None):
        self.data = data
        self.next = None
        self.prev = None

    def __str__(self):
        return str(2 * self.data)
    
    def __size(self):
        return self.data


class DoublyLinkedList(Node):
    def __init__(self, head = None, tail = None):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def contains(self, data):
        node = self.head
        while node:
            yield node                     
            node = node.next
        


    def size(self):
        return self.__size
    
    
    def isEmpty(self):
        return self.__size == 0
    
    
    def __str__(self):
        l = []
        trav = self.__head
        while trav is not None:
            l.append(trav.data)
            trav = trav.next
        return " ----> ".join(map(str, l))
    
    #============================================== this is internal functionality of iterators ===============================
    # this is how " for i in l " works
    
    def __iter__(self):
        self.__trav = self.__head
        return self
    
    def __next__(self):
        if self.__trav is None:
            raise StopIteration
        else:
            data = self.__trav.data
            self.__trav = self.__trav.next
            return data
    #===========================================================================================================================
    
    
    def append(self, data):       # to add at the end
        newNode = Node(data)
        if self.isEmpty():
            self.__head = newNode
            self.__tail = newNode
        else:
            self.__tail.next = newNode
            newNode.prev = self.__tail
            self.__tail = newNode
            self.__tail.next = None
        self.__size += 1

        

    def addFirst(self, data):        # to add at the beginning
        newNode = Node(data)

        if self.isEmpty():
            self.__tail = newNode
            self.__head = newNode
        else:
            newNode.next = self.__head
            self.__head.prev = newNode
            self.__head = newNode
            self.__head.prev = None
        self.__size += 1



    def addAt(self, index, data):            # to add at any index
        if index < 0 or index > self.__size:
            raise IndexError("Index out of range")
        if index == 0:
            self.addFirst(data)
        elif index == self.__size:
            self.append(data)
        else:
            newNode = Node(data)
            trav = self.__head
            for _ in range(index - 1):
                trav = trav.next
            newNode.prev = trav
            newNode.next = trav.next
            trav.next = newNode
            newNode.next.prev = newNode
            self.__size += 1
        
    
    def removeFirst(self):            # to remove at the beginning
        if self.isEmpty():
            raise IndexError("List is empty")
        else:
            temp = self.__head
            self.__head = self.__head.next
            self.__head.prev = None
            del temp
            self.__size -= 1

    def removeLast(self):                # to remove at the end
        if self.isEmpty():
            raise IndexError("List is empty")
        else:
            temp = self.__tail
            self.__tail = self.__tail.prev
            self.__tail.next = None
            del temp
            self.__size -= 1

    def removeAt(self, index):               # to remove at any index
        if index < 0 or index >= self.__size:
            raise IndexError("Index out of range")
        if index == 0:
            self.removeFirst()
        elif index == self.__size - 1:
            self.removeLast()
        else:
            trav = self.__head
            for _ in range(index - 1):
                trav = trav.next
            temp = trav.next
            trav.next = temp.next  # trav.next = trav.next.next
            temp.next.prev = trav
            del temp
            self.__size -= 1



#=============================================================================
# node = Node(10)
# print(node)                              # node calls __str__ method which returns  (2 * self.data) = 2 * node
# print(node.data)                         # node value = 10


#=========================initialising list========================================
l = DoublyLinkedList()
print("The list is empty: ", l.isEmpty())

l.append(10)
print(l)

for i in range(1,10,2):
    l.append(i)

print(l)

# printing size using class
print("The list is empty : ", l.isEmpty())
print("The size of the list is : ", l.size())

#inserting node at a index
l.addAt(3, 20)
print(l)
print("The size of the list is : ", l.size())

#removing node at a index
l.removeAt(3)
print(l)
print("The size of the list is : ", l.size())

#iterating through elements
for i in l:
    print(i, end=" - ")







'''The Yield keyword in Python is similar to a return statement used for returning values or objects in Python. However, there is a slight difference. The yield statement returns a generator object to the one who calls the function which contains yield, instead of simply returning a value.
'''