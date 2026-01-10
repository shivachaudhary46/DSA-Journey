def find_min_max(arr): 
    n = len(arr)

    # odd bhayeko case ma minimum ra maximum same ho bhanera assume garxum 
    # tespaxi iterate garinxa
    # Even bhayeko case ma first ko 2 number ma which one is smallest or largest bhayeko assume garne i = 2 use garne 
    # 
    if n % 2 == 1: 
        mini = maxi = arr[0]
        i = 1
    else: 
        if arr[0] > arr[1]:
            mini = arr[1]
            maxi = arr[0]
        else: 
            mini = arr[0]
            maxi = arr[1]
        i = 2 


    while(i < n): 
        if arr[i] < arr[i + 1]: 
            mini = min(mini, arr[i])
            maxi = max(maxi, arr[i+1])
        elif arr[i] == arr[i+1] : 
            maxi = max(maxi, arr[i])
        else: 
            mini = min(mini, arr[i+1])
            maxi = max(maxi, arr[i]) 
        i += 2

    return [maxi, mini]

# suppose [9, 4, 5, 1, 11, 0, 12]
# since it is odd first element is minimum and maximum 
# now we have to compare [4, 5], [1, 11], [0, 12] 
# [9, 4], [11, 1], [0, 12]

if __name__ == "__main__":
    arr = [9, 4, 5, 1, 11, 0, 7]
    maxi, mini = find_min_max(arr)
    print(maxi, mini)
    