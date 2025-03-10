def insertion_sort(arr, size):
    for i in range(1, size):
        key,j = arr[i], i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

size = int(input())
arr = list(map(int, input().split()))[:size]
insertion_sort(arr,size)
print(arr)