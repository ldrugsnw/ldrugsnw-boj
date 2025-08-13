import sys
input = sys.stdin.readline
N = int(input())
count=0

k = 1
while N > 0 :
    if N-k >= 0 :
        N = N-k
        count+=1
        k += 1
    else :
        k = 1
    
print(count)
