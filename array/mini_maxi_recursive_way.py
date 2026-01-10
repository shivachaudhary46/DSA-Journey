def find_min_max(arr, low, high):
    result = [0, 0]
    # base case yeuta element huna sakxa means tei minimum huna sakxa, tei maximum huna sakxa
    # 2 elements ko case huna sakxa, means yeuta minimum huna sakxa ra arko maximum huna sakxa
    # aru recursively iterate garnu parxa half break gardai

    # If base element [6] (low == high [0 == 0])
    if low == high: 
        result[0] = arr[low]
        result[1] = arr[high]
        return result
    
    # If there are 2 element 
    # result[0, 0], 1st element is maximum, 2nd element is minimum,
    # ki [maximum, minimum] hunxa, ki [minimum, maximum] hunxa 
    if high == low + 1:
        if arr[low] < arr[high]: 
            result[0] = arr[high]
            result[1] = arr[low]
            return result
        else: 
            result[0] = arr[low]
            result[1] = arr[high]
            return result 

    # recursively iterate garnu parxa 
    mid = ( low + high ) // 2

    left = find_min_max(arr, low, mid)
    right = find_min_max(arr, mid + 1, high)

    # [0, 0] first element chai maximum hunxa ni ta so compare garne right patti ko maximum ki left patti ko 
    # 2nd element chai minimum hunxa ni ta so compare garne left patti ko minimum hunxa ki right patti ko 
    result[0] = max(left[0], right[0])
    result[1] = min(left[1], right[1])

    return result 
    
# suppose [9, 2, 7, 1, 0, 11, 5, 6]
# since yo base 1 or 2 xaina so, hamile yeslai half garnu parxa 7 element xa, mid = 0 + 7 // 2 = 3, 
# [9 2 7 1], [0, 11, 5, 6] , mid1 = 3 // 2 = 1, mid2 = 3 // 2 = 1
# [9, 2], [7, 1], [0, 11], [5, 6] base element haru 
# [9, 2], [7, 1], [11, 0], [6, 5] base element lai order garera rakhem 
# pahila suru max(9, 7)=9, min(2, 1)=1 | max(11, 6)=11, min(0, 5)=0 | result = [9, 11], result = [1, 0] | result = [11, 0]

if __name__ == "__main__": 
    arr = [9, 2, 7, 1, 0, 11, 5, 6]
    result = find_min_max(arr, 0, len(arr)-1)
    print("maximum element : ", result[0])
    print("minimum element : ", result[1])