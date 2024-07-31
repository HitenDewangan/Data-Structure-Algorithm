class Node:
    def __init__(self, data, next = None):
        self.data = data
        self.next = None

class Queue:

    def __init__(self, head = None, tail = None):
        self.__front = None
        self.__rear = None
        self.__size = 0

    def size(self):
        return self.__size


    def isEmpty(self):
        return self.__size == 0

    def enqueue(self, data):
        newNode = Node(data)
        if(self.isEmpty()):
            self.__front = self.__rear = newNode
        else:
            self.__rear.next = newNode
            self.__rear = newNode
        self.__size += 1

    def dequeue(self):
        if(self.isEmpty()):
            raise Exception("Queue is empty")
        else:
            temp = self.__front
            self.__front = self.__front.next
            ret = temp.data
            del temp
            self.__size -= 1
            return ret

            

    def peek(self):
        if(self.isEmpty()):
            raise Exception("Queue is empty")
        else:
            return self.__front.data
    

    def __str__(self):
        l = []
        trav = self.__front
        while trav is not None:
            l.append(trav.data)
            trav = trav.next
        return " ----> ".join(map(str, l))  
    



# ===================================== Driver Code ===================================

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print(q)

print(q.peek())

print(q.dequeue())
print(q)

q.enqueue(4)
print(q)