def bucket_sort(arr, MAX_VALUE):
    count = [0]*MAX_VALUE
    for i in arr: count[i] += 1
    res = []
    for i in range(MAX_VALUE):
        for j in range(count[i]):
            res.append(i)
    return res

size = int(input())
arr = list(map(int, input().split()))[:size]
res = bucket_sort(arr,10000)
print(res)