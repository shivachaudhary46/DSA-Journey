def binary_search(arr, start, end, key): 
    
    mid = ( start + end ) // 2

    while (start <= end):

        if arr[mid] == key:
            return mid
        
        if arr[mid] < key: 
            start = mid + 1 

        else: 
            end = mid 

        mid = (start + end) // 2

    return -1 

if __name__ == "__main__": 
    even_array = [2, 4, 7, 9, 11, 17]
    odd_array = [5, 6, 9, 14, 21]

    res = binary_search(even_array, 0, 5, 17)

    print(res)