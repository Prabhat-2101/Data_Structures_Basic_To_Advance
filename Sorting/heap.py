def heapify(arr,idx,size):
    largest = idx
    left, right = 2*idx + 1, 2*idx + 2
    if left<size and arr[left]>arr[largest]: largest = idx
    if right<size and arr[right]>arr[largest]: largest = idx
    if largest != idx:
        arr[largest], arr[idx] = arr[idx], arr[largest]
        heapify(arr,largest,size)
        
def heap_sort(arr,size):
    for i in range((size // 2) - 1, -1, -1):
        heapify(arr, i, size)
    for i in range(size - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, 0, i)
    
size = int(input())
arr = list(map(int, input().split()))[:size]
heap_sort(arr,size)
print(arr)