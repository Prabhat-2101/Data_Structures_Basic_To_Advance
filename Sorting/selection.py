def selection_sort(arr,size):
    for i in range(size-1):
        mini = i
        for j in range(i,size):
            if arr[j]<arr[mini]:
                mini = j
        arr[i], arr[mini] = arr[mini], arr[i]

size = int(input())
arr = list(map(int, input().split()))[:size]
selection_sort(arr,size)
print(arr)
