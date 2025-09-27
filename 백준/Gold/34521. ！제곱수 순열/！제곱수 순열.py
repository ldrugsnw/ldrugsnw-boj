import sys
input=sys.stdin.readline

T=int(input())
for _ in range(T):
    N=int(input())
    ans=[]
    flag = 4
    num = 2
    prev = flag
    for i in range(1,N+1):
        if flag==i:
            t=ans.pop()
            ans.append(i)
            ans.append(t)
            flag = prev + 4*num
            num += 1
            prev = flag
        else:ans.append(i)
    print(*ans)