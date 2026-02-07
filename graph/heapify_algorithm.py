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

if __name__ == "__main__": 
    h = heapify() 
    h.insert(78)
    h.insert(45)
    h.insert(2)
    h.insert(79)
    h.insert(89)
    h.insert(90)

    h.show() 

            
        