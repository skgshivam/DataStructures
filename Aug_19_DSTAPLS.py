T = eval(input())
for i in range(T):
    N, K = input().split()
    if int(N) % (int(K) * int(K)) == 0:
        print("NO")
    else:
        print("YES")