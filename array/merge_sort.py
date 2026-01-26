# # merging the array 
# # 9, 3, 4, 1, 10, 13, 2
# # in next step 9, 3, 4, 1, and another array 10, 13, 2
# # next step 9, 3 & 4, 1, another step 10, 13 & 2 
# def merge(arr, left, mid, right): 
#     n1 = mid - left + 1 
#     n2 = right - mid

#     arr1 = [0] * n1
#     arr2 = [0] * n2

#     for i in range(n1):
#         arr1[i] = arr[left + i]

#     for j in range(n2):
#         arr2[j] = arr[mid + 1 + j]

#     k = left 
#     i = 0 
#     j = 0
    
#     # if both array size is same 
#     while i < n1 and j < n2 : 
#         if arr1[i] <= arr2[j]: 
#             arr[k] = arr1[i] 
#             i = i + 1 
#         else: 
#             arr[k] = arr2[j]
#             j = j + 1 
#         k = k + 1

#     # if left array is greater 
#     while i < n1: 
#         arr[k] = arr1[i]
#         i = i + 1 
#         k = k + 1 

#     while j < n2: 
#         arr[k] = arr2[j]
#         j = j + 1 
#         k = k + 1 
    

# def merge_sort(arr, left, right): 
#     if left < right: 
#         mid = (left + right) // 2

#         merge_sort(arr, left, mid) # lets first merge the left side
#         merge_sort(arr, mid + 1, right) # right merge 

#         merge(arr, left, mid, right)

# def merging(arr, left, mid, right):
#     n1 = mid - left + 1 
#     n2 = right - mid 

#     print("n1: ", n1)
#     print("n2: ", n2)

#     arr1 = [0] * n1 
#     arr2 = [0] * n2 

#     for i in range(n1): 
#         arr1[i] = arr[left + i]

#     for j in range(n2): 
#         arr2[j] = arr[mid + 1 + j]

#     print("arr1: ", arr1)
#     print("arr2: ", arr2)

# if __name__ == "__main__": 

#     arr = [9, 3, 2, 1, 10, 11, 5, 6]
#     merge_sort(arr, 0, 7)

#     print (arr)

def merge(arr, left, mid, right):
    n1 = mid - left + 1 
    n2 = right - mid 

    L = [0] * n1
    R = [0] * n2

    for i in range(n1):
        L[i] = arr[left + i]

    for j in range(n2): 
        R[j] = arr[mid + 1 + j]

    i = 0
    j = 0
    k = left 

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i = i + 1 
        else: 
            arr[k] = R[j]
            j = j + 1
        k = k + 1 

    while i < n1:
        arr[k] = L[i]
        i = i + 1 
        k = k + 1 

    while j < n2: 
        arr[k] = R[j]
        j = j + 1 
        k = k + 1     

def merge_sort(arr, left, right): 

    if left < right: 
        mid = (left + right) // 2 

        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

        merge(arr, left, mid, right)

if __name__ == "__main__": 
    arr = [9, 3, 2, 1, 11, 4, 5, 10]
    merge_sort(arr, 0, 7)

    print(arr)