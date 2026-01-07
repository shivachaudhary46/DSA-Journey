def reverse_array(array):

    n = len(array)

    for i in range(n//2):

        temp = array[i]
        array[i] = array[n-i-1]
        array[n-i-1]= temp

    return array

if __name__ == "__main__":
    arr = [2, 3, 4, 5, 6]
    arr = reverse_array(arr)
    for i in range(len(arr)):
        print(arr[i], end=" ")