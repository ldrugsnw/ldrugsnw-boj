a,b,c=map(int,input().split())
N=int(input())
if N%2:
    print((a+b+c)*(N//2)+a+b+c+(c-a)*(N//2))
else:
    print((a+b+c)*(N//2)+(c-a)*(N//2))