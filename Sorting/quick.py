def partition(arr, low, high):
    i, pivot = low - 1, arr[high]
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)
    

size = int(input())
arr = list(map(int, input().split()))[:size]
quick_sort(arr,0, size - 1)
print(arr)