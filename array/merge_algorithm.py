def merge(arr, left, mid, right): 
    n1 = mid - left + 1
    n2 = right - mid

    left = [0] * n1
    right = [0] * n2

    for i in range(n1): 
        left[i] = arr[left + i]
    for i in range(n2): 
        right[i] = arr[mid + 1 + j]

    i = 0 
    j = 0 
    k = left

    while ( i < n1 and j < n2): 
        if left[i] <= right[j]: 
            arr[k] = left[i]
            i = i + 1
        else: 
            arr[k] = right[j]
            j = j + 1
        k = k + 1

    while (i < n1): 
        arr[k] = left[i]
        i = i + 1
        k = k + 1

    while (j < n2): 
        arr[k] = right[j]
        j = j + 1 
        k = k + 1 

def mergeSort(arr, left, right): 
    mid = left + (right - left) // 2

    if left < right: 
        mergeSort(arr, left, mid-1)
        mergeSort(arr, mid, right)
        merge(arr, left, mid, right)

if __name__ == "__main__": 
    arr = [9, -4, 6, 7, 9 , 3]
    left = 0 
    right = 5
    mergeSort(arr, left, right)

    for i in range(right):
        print(arr[i]) 
