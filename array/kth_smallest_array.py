# Given an integer K'th smallest Element 

def kthsmallest(arr, k):

    arr.sort() 
    return arr[k-1]

if __name__ == "__main__":
    k = 4 
    arr = [ 9, 3, 1, 4, 5, 0, 12, 17, 2]
    print(kthsmallest(arr, k))

# smallest array find garnu xa bhane 
# 0, 1, 2, 3, 4, 5, 9, 12, 17 
# order of time complexity = O(nlog(n)) time and O(1) space 

# Using Max-Heap O(n*log(k)) Time and O(k) Space 


