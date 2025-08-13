T = int(input())

for _ in range(T):
    N = int(input())

    s = N//5
    ss = N%5

    result = "++++ "*(s) + "|" * ss
    print(result)