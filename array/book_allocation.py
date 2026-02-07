def isPossible(arr, n, m, mid): 
    pageSum = 0 
    studentCount = 1 

    for i in range(n):
        if (pageSum + arr[i] <= mid): 
            pageSum += arr[i]

        else:
            studentCount = studentCount + 1 
            if studentCount > m or arr[i] > mid : 
                return False
            pageSum = arr[i]
    
    return True

# n is number of the student
# m is minimum number of books assigned to each students 

# Each student receives atleast one book 
# Each student is assigned a contiguous sequence of books 
# No book is assigned to more than one student
def bookAllocation(arr, n, m): 

    s = 0 
    
    total = 0
    for i in range(len(arr)): 
        total += arr[i]

    e = total 

    mid = (s + (e-s)) // 2 
    ans = 0

    while (s < e):
        if isPossible(arr, n, m, mid): 
            ans = mid 
            e = mid 
        else: 
            s = mid + 1 

        mid = (s + (e-s)) // 2 
    
    return ans 

if __name__ == "__main__":
    arr = [10, 20, 30, 40]
    ans=bookAllocation(arr, len(arr), 2)
    print(ans)
    