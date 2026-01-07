def two_pointer(arr):
    left = 0
    right = len(arr) - 1

    while left < right: 
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1

    return arr

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    new_arr=two_pointer(arr)

    for i in range(len(new_arr)):
        print(new_arr[i], end=" ")