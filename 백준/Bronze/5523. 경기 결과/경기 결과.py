import sys
input = sys.stdin.readline

N = int(input())

a_win = 0
b_win = 0

for _ in range(N):
    a, b = map(int, input().split(' '))
    if a>b : 
        a_win = a_win + 1
    elif b>a :
        b_win = b_win + 1

print(f"{a_win} {b_win}")