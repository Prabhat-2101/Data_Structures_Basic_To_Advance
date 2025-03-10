def merger(arr, low, mid, high):
    s1, s2 = mid - low + 1, high - mid
    lsubarr = arr[low:low + s1]
    rsubarr = arr[mid + 1:mid + 1 + s2]
    
    i, j, k = 0, 0, low
    while i < s1 and j < s2:
        if lsubarr[i] <= rsubarr[j]:
            arr[k] = lsubarr[i]
            i += 1
        else:
            arr[k] = rsubarr[j]
            j += 1
        k += 1
    
    while i < s1:
        arr[k] = lsubarr[i]
        i += 1
        k += 1

    while j < s2:
        arr[k] = rsubarr[j]
        j += 1
        k += 1

def merge_sort(arr, low, high):
    if low >= high:
        return
    mid = low + (high - low) // 2
    merge_sort(arr, low, mid)
    merge_sort(arr, mid + 1, high)
    merger(arr, low, mid, high)

size = int(input())
arr = list(map(int, input().split()))[:size]
merge_sort(arr, 0, size - 1)
print(arr)
