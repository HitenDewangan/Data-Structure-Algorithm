from typing import TypeVar

T = TypeVar('T')       #Generic type variable

class myArray:
    def __init__(self, cap:int) -> None:
        self.__capacity = cap
        self.__size = 0
        self.__data = [None]*cap
        self.__type = type
    

    def __getitem__(self, index:int) -> T:
        if index >=0 or index < self.__size:
            return self.__data[index]
        else:
            raise IndexError("Index out of range")
    

    def __setitem__(self, index, value):
        if index >=0 or index < self.__size:
            self.__data[index] = value
        else:
            raise IndexError("Index out of range")
        

    def __len__(self):
        return self.__size


    def __resize__(self):
        new_array = [None]*(self.__capacity*2)

        for i in range(self.__size):
            new_array[i] = self.__data[i]
        self.__capacity = self.__capacity*2
        self.__data = new_array


    def __append__(self, value):
        if self.__size < self.__capacity:
            self.__data[self.__size] = value
            self.__size += 1
        else:
            self.__resize__()



#===================Creating Instance====================
array = myArray(5)
array.__append__(1)
array.__append__(2)
array.__append__(3)

array.__setitem__(2, 4)
print(array.__getitem__(2))

print(len(array))
