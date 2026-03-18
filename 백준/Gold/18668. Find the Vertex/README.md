# [Gold IV] Find the Vertex - 18668 

[문제 링크](https://www.acmicpc.net/problem/18668) 

### 성능 요약

메모리: 33516 KB, 시간: 316 ms

### 분류

그래프 이론, 그래프 탐색, 애드 혹

### 제출 일자

2026년 3월 18일 14:21:44

### 문제 설명

<p>You are given a connected undirected graph with n vertices and m edges. The vertices are numbered from 1 to n. The vertex number s is the initial vertex. You don’t know the number s, but you know all distances from vertex s to every other vertex including itself, taken modulo 3. You have to find the number s.</p>

<p>The distance between two vertices is the length of the shortest path between them. The length of a path is the number of edges in it.</p>

### 입력 

 <p>The first line contains two integers n and m (1 ≤ n, m ≤ 500 000), the number of vertices and the number of edges.</p>

<p>The second line contains n integers d<sub>1</sub>, d<sub>2</sub>, . . . , d<sub>n</sub> (0 ≤ d<sub>i</sub> ≤ 2). Here, d<sub>i</sub> is the distance between vertices s and i, taken modulo 3.</p>

<p>The next m lines describe the edges. The i-th of these lines describes i-th edge and contains two integers u and v (1 ≤ u, v ≤ n), the indices of vertices connected by this edge.</p>

<p>It is guaranteed that there are no self-loops and no multiple edges in the graph. Also, it is guaranteed that the graph is connected.</p>

### 출력 

 <p>Print the number s: the index of the initial vertex. If there are multiple answers, print any one of them.</p>

