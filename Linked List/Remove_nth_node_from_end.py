'''Delete nth node from end of a Singly linked list'''

class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = None

    def __str__(self):
        return str(self.data)
    
    def __size(self):
        return self.data
    
class SinglyLinkedList(Node):
    def __init__(self, head = None, tail = None):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def size(self):
        return self.__size
    
    def __str__(self):
        l = []
        trav = self.__head
        while trav is not None:
            l.append(trav.data)
            trav = trav.next
        return " ----> ".join(map(str, l))
    
    def append(self, data):
        newNode = Node(data)
        if self.__head == None:
            self.__head = newNode
            self.__tail = newNode
        else:
            self.__tail.next = newNode
            self.__tail = newNode
            self.__tail.next = None
        self.__size += 1


    
    def remove_nth_from_end(self, n):
        if self.__head == None:
            raise Exception("List is empty")
        if n>self.size():
            raise Exception("Index out of range")
        if n==self.size():
            prev = self.__head
            self.__head = self.__head.next
            del prev
        
        node = self.__head
        prev = None
        index_to_search = self.size() - n   #index to search for storing previous node address
        
        i = 0
        while (i < index_to_search):
            prev = node
            node = node.next
            i += 1 
        
        prev.next = node.next
        del node
        self.__size -= 1
        


#==========================================================================
l = SinglyLinkedList()

# inserting data
for i in range(1, 10, 2):
    l.append(i)

print()
print(l)
print("List size: ", l.size())

# removing nth node
print()
l.remove_nth_from_end(3)
print("List after removing 3rd node: ", l, sep = "\n")
print("List size: ", l.size())

print()
l.append(11)
print(l)
print("List size: ", l.size())
print(type(l))

