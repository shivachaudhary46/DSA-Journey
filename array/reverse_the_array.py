# reversing the array through creating a temporary array 
def reverse_array(array):
    n = len(array)

    temp = [0] * n

    for i in range(n):
        temp[i] = array[n-i-1]

    for i in range(len(array)):
        array[i] = temp[i]

    return array

arr = [1, 2, 3, 4, 5]

print("before reversing with using s(n): ")
for i in range(len(arr)):
    print(arr[i], end=" ")

res = reverse_array(arr)

print("\nafter reversing with using s(n): ")
for i in range(len(res)):
    print(res[i], end=" ")