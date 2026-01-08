#sorting and finding minimum and largest number in array time complexity = O(nlogn) & space complexity = O(1)
# def reverse_array(arr):
#     sortArry = sorted(arr)
#     return sortArry[0], sortArry[-1]

# if __name__ == "__main__":
#     arr = [9, 1, 4, 7, 2, 8, 0]
#     min, max = reverse_array(arr)
#     print("Minimum number in array: ", min, "Maximum number in array: ", max)

# Iterating the array and finding the minimum and maximum number in array O(n) and space complexity O(1)
def reverse_array(arr):
    mini = 0 
    maxi = 0

    for i in range(len(arr)):
        if maxi < arr[i]:
            maxi = arr[i]
        elif mini > arr[i]:
            mini = arr[i]

    return mini, maxi

if __name__ == "__main__":
    arr = [9, 1, 4, 7, 2, 8, 0]
    min, max = reverse_array(arr)
    print("Minimum number in array: ", min, "Maximum number in array: ", max)