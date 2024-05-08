# binary search algorithm implementation in python

arr = [7, 3, 0, 8, 1, 3, 2, 5, 1, 0, 10]

arr_size = len(arr) - 1

# sorting arr (bubble sort)
def sorting_arr(arr, arr_size):
    for i in range(0, arr_size):
        for j in range(i+1, arr_size):
            if(arr[i] > arr[j]):
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp

sorting_arr(arr, arr_size)
print(arr)
    
# binary search
def binary_search(arr, item, arr_size):
    low = 0
    high = arr_size
    
    while low <= high:
        middle = low + (high - low) // 2
        if(arr[middle] == item):
            return middle
        elif(arr[middle] < item):
            low = middle + 1
        else:
            high = middle - 1
    
    return -1

item = 8
result = binary_search(arr, item, arr_size)
if(result < 0):
    print(item, "Not Found.!")
else:
    print(item, "Found! Index at", result)