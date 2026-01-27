def print_contigious_array(arr): 
    
    for st in range(0, len(arr)): 
        for end in range(st, len(arr)): 
            for k in range(st, end + 1):
                print(arr[k], end="")
            print(" ", end="")
        print()
    

if __name__ == "__main__": 
    arr = [1, 2, 3, 4, 5]
    print_contigious_array(arr)

    for i in range(0, len(arr)): 
        for j in range(0, len(arr)):
            for k in range(0, len(arr)):
                for l in range(0, len(arr)):
                    print(l, end="", sep=" ")
            print(" ", end="")
            print()
        print()
    print()