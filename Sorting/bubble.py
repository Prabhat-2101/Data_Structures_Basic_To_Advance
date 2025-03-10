size = int(input())
arr = list(map(int,input().split()))[:size]
for i in range(size):
    for j in range(i+1,size):
        if arr[i]>arr[j]:
            arr[i], arr[j] = arr[j], arr[i]
            
print(arr)