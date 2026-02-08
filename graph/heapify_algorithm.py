class heapify: 
    def __init__(self):
        self.arr = [-1]
        self.size = 0 

    def insert(self, value): 
        self.arr.append(value)
        self.size = self.size + 1

        index = self.size

        while ( index > 1 ): 
            parent = index // 2 

            if self.arr[parent] < self.arr[index]: 
                self.arr[parent], self.arr[index] = self.arr[index], self.arr[parent]
                index = parent
            else:
                return
            
    def show(self):
        for i in range(self.size + 1): 
            print(self.arr[i], end=" ")
        
        print()

    def deleteheap(self): 
        self.arr[1] = self.arr[self.size]
        self.size = self.size - 1 

        index = 1 
        while (index < self.size):
            largest = index
            leftIndex = 2 * index
            rightIndex = 2 * index + 1

            if leftIndex < self.size and self.arr[leftIndex] > self.arr[index]: 
                largest = leftIndex

            elif rightIndex < self.size and self.arr[rightIndex] > self.arr[index]: 
                largest = rightIndex
            else: 
                return
            
            if largest != index: 
                self.arr[largest], self.arr[index] = self.arr[index], self.arr[largest]

    def deleteHeap1(self): 

        self.arr[1] = self.arr[self.size]
        self.size = self.size - 1 

        index = 1
        while(index < self.size): 
            leftIndex = 2 * index 
            rightIndex = 2 * index + 1

            if leftIndex < self.size and self.arr[leftIndex] > self.arr[index]: 
                self.arr[leftIndex], self.arr[index] = self.arr[index], self.arr[leftIndex]
                index = leftIndex
            
            elif rightIndex < self.size and self.arr[rightIndex] > self.arr[index]: 
                self.arr[rightIndex], self.arr[index] = self.arr[index], self.arr[rightIndex]
                index = rightIndex

            else: 
                return
            
    def max_heapify(self, arr, n, i): 
        largest = i 
        left = 2 * i 
        right = 2 * i + 1

        while ( i < n): 
            if left < n and arr[left] < arr[i]: 
                largest = left
            elif right < n and arr[right] < arr[i]: 
                largest = right 
            else: 
                return 

             
    def max_heapify(self, arr, ):
        pass
        # clear
        

if __name__ == "__main__": 
    h = heapify() 
    h.insert(78)
    h.insert(45)
    h.insert(2)
    h.insert(79)
    h.insert(89)
    h.insert(90)

    h.show() 

    # h.deleteheap()
    
    # h.show()

    h.deleteHeap1()
    
    h.show() 