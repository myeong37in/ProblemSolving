'''
Python으로 다시 구현해 봅시다
'''

import sys
from collections import deque

def bfs(N, A, B, DA, DB):
    q = deque()
    q.append((A, B, 0))
    visited = set()
    visited.add((A, B, 0))

    while q:
        a, b, dist = q.popleft()

        if a == b:
            return dist
        
        if (dist & 1) == 0:
            na = (N + (a - DA)) % N
            state = (na, b, 1)
            if state not in visited:
                visited.add(state)
                q.append((na, b, dist + 1))

            na = (a + DA) % N
            state = (na, b, 1)
            if state not in visited:
                visited.add(state)
                q.append((na, b, dist + 1))
        else:
            nb = (N + (b - DB)) % N
            state = (a, nb, 0)
            if state not in visited:
                visited.add(state)
                q.append((a, nb, dist + 1))

            nb = (b + DB) % N
            state = (a, nb, 0)
            if state not in visited:
                visited.add(state)
                q.append((a, nb, dist + 1))

    return -1

def main():
    N, A, B, DA, DB = map(int, sys.stdin.readline().split())
    ans = bfs(N, A - 1, B - 1, DA, DB)
    if ans == -1:
        print("Evil Galazy")
    else:
        print(ans)
    

if __name__ == "__main__":
    main()