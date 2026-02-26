# [Gold III] Fiber Network - 6563 

[문제 링크](https://www.acmicpc.net/problem/6563) 

### 성능 요약

메모리: 2288 KB, 시간: 28 ms

### 분류

비트마스킹, 플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2026년 2월 26일 09:30:21

### 문제 설명

<p>Several startup companies have decided to build a better Internet, called the "FiberNet". They have already installed many nodes that act as routers all around the world. Unfortunately, they started to quarrel about the connecting lines, and ended up with every company laying its own set of cables between some of the nodes.</p>

<p>Now, service providers, who want to send data from node <em>A</em> to node <em>B</em> are curious, which company is able to provide the necessary connections. Help the providers by answering their queries.</p>

### 입력 

 <p>The input contains several test cases. Each test case starts with the number of nodes of the network <em>n</em>. Input is terminated by <em>n=0</em>. Otherwise, <em>1<=n<=200</em>. Nodes have the numbers <em>1, ..., n</em>. Then follows a list of connections. Every connection starts with two numbers <em>A, B</em>. The list of connections is terminated by <em>A=B=0</em>. Otherwise, <em>1<=A,B<=n</em>, and they denote the start and the endpoint of the unidirectional connection, respectively. For every connection, the two nodes are followed by the companies that have a connection from node <em>A</em> to node <em>B</em>. A company is identified by a lower-case letter. The set of companies having a connection is just a word composed of lower-case letters.</p>

<p>After the list of connections, each test case is completed by a list of queries. Each query consists of two numbers <em>A, B</em>. The list (and with it the test case) is terminated by <em>A=B=0</em>. Otherwise, <em>1<=A,B<=n</em>, and they denote the start and the endpoint of the query. You may assume that no connection and no query contains identical start and end nodes.</p>

### 출력 

 <p>For each query in every test case generate a line containing the identifiers of all the companies, that can route data packages on their own connections from the start node to the end node of the query. If there are no companies, output <code>"-"</code> instead. Output a blank line after each test case.</p>

