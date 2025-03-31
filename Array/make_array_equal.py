import math as mt
def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        total_sum = sum(a)
        least = mt.floor(total_sum / n )

        is_possible,excess = True,0
        
        for i in range(n):
            if a[i] > least:
                excess += a[i] - least
            elif a[i] < least:
                if excess >= least - a[i]:
                    excess -= least - a[i]
                else:
                    is_possible = False
                    break

        if is_possible:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()
