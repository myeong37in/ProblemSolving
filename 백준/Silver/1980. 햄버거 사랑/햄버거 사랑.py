n, m, t = map(int, input().split())
colamin = t
hammax = 0
for i in range(0, t//n+1):
    for j in range(0, t//m+1):
        a = i * n + j * m
        if a > t: break
        cola = t - a
        if colamin > cola:
            colamin = cola
            hammax = i + j
        elif colamin == cola:
            hammax = max(hammax, i+j)
print(hammax, colamin)