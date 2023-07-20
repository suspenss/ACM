from sys import stdin
from collections import deque

input = stdin.readline

def solve() -> ():
    N, Q, K = map(int, input().split())
    cost    = list(map(int, input().split()))
    height  = list(map(int, input().split()))

    dq = deque()
    maxLen = K; curSum = 0; f = [0] * N

    for i in range(N):
        dq.append(i)
        curSum += cost[i]

        if i - K + 1 >= 0 and height[i] == height[i - K + 1]:
            maxLen = K
        else:
            maxLen += 1

        while len(dq) > maxLen:
            curSum -= cost[dq[0]]
            dq.popleft()

        f[i] = curSum

    for _ in range(Q):
        print(f[int(input()) - 1])

if __name__ == '__main__':
    solve()
