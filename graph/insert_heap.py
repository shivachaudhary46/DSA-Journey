class heap: 
    def __init__(self):
        self.arr = [-1]
        self.size = 0 

    def insert(self, value): 
        self.arr.append(value)
        self.size = self.size + 1 

        i = self.size

        while(i > 1): 
            parent = i // 2

            if(self.arr[parent] < self.arr[i]):
                self.arr[parent], self.arr[i] = self.arr[i], self.arr[parent]
                i = parent
            else: 
                return 
        
    def show(self): 
        for i in range(self.size + 1): 
            print(self.arr[i], end=" ")

        print() 

    def deleteheap(self):

        if (self.size == 0):
            print("nothing to delete")

        # first node = last node 
        self.arr[1] = self.arr[self.size]

        # deleting the last node 
        self.size = self.size - 1

        # i is parent node 
        i = 1
        while(i < self.size):
            leftIndex = 2 * i 
            rightIndex = 2 * i + 1 

            if (leftIndex < self.size and self.arr[leftIndex] > self.arr[i]):
                self.arr[i], self.arr[leftIndex] = self.arr[leftIndex], self.arr[i]
                i = leftIndex

            elif (rightIndex < self.size and self.arr[rightIndex] > self.arr[i]): 
                self.arr[i], self.arr[rightIndex] = self.arr[rightIndex], self.arr[i]
                i = rightIndex

            else : 
                return 

    # 1 based indexing 
    def heapify(self, arr, n, i): 

        largest = i 
        left = 2 * i 
        right = 2 * i + 1 

        if (left < n and arr[largest] < arr[left]):
            largest = left
        if (right < n and arr[largest] < arr[right]): 
            largest = right
        
        if (largest != i): 
            arr[largest], arr[i] = arr[i], arr[largest]
            self.heapify(arr, n, largest) 

    

    # 0 based indexing  
    def min_heapify(self, arr, n, i): 

        smallest = i 
        left = 2 * i + 1 
        right = 2 * i + 2 

        if (left < n and arr[smallest] > arr[left]):
            smallest = left
        if (right < n and arr[smallest] > arr[right]): 
            smallest = right 

        if (smallest != i): 
            arr[i], arr[smallest] = arr[smallest], arr[i]
            self.min_heapify(arr, n, smallest)




if __name__ == "__main__": 
    h = heap()
    h.insert(45)
    h.insert(90)
    h.insert(35)
    h.insert(55)
    h.insert(100)

    h.show() 

    h.deleteheap()

    h.show()

    arr = [-1, 45, 34, 56, 60, 78]
    n = len(arr)
    for i in range(n//2 + 1, -1, -1):
        h.heapify(arr, len(arr), i)

    for i in range(len(arr)): 
        print(arr[i], end=" ")

    for i in range(n//2 + 1, -1, -1): 
        h.min_heapify(arr, len(arr), i)
    print() 

    for i in range(len(arr)):
        print(arr[i], end=" ") 