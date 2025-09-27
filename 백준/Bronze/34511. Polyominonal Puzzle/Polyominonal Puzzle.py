from collections import deque
import sys
def input():return sys.stdin.readline().rstrip()
dx=[-1,1,0,0]
dy=[0,0,-1,1]

N,M=map(int,input().split())
graph=[input() for _ in range(N)]
visited=[[False]*M for _ in range(N)]

def bfs(y,x):
    global cnt
    q=deque([(y,x)])
    visited[y][x]=True
    while q:
        y,x=q.popleft()
        for i in range(4):
            ny,nx=y+dy[i],x+dx[i]
            if 0<=ny<N and 0<=nx<M and graph[ny][nx]=='Y':
                cnt+=1
            if 0<=ny<N and 0<=nx<M and not visited[ny][nx] and graph[ny][nx]=='X':
                visited[ny][nx]=True
                q.append((ny,nx))

cnt=0
for i in range(N):
    for j in range(M):
        if graph[i][j]=='X' and not visited[i][j]:
            bfs(i,j)

print(cnt)