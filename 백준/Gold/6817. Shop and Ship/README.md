# [Gold I] Shop and Ship - 6817 

[문제 링크](https://www.acmicpc.net/problem/6817) 

### 성능 요약

메모리: 50980 KB, 시간: 624 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라, 벨만–포드, 다이얼

### 제출 일자

2026년 3월 3일 12:54:07

### 문제 설명

<p>In Doubleclickland, there are N cities (N ≤ 5, 000), with each city having various trade routes to other cities. In total, there are T trade routes (0 ≤ T ≤ 25, 000, 000). in Doubleclickland. For each trade route between two cities x and y, there is a transportation cost C(x, y) to ship between the cities, where C(x, y) ≥ 0, C(x, y) ≤ 10, 000 and C(x, y) = C(y, x). Out of the N cities, K (1 ≤ K ≤ N) of these cities have stores with really nice pencils that can be purchased on-line. The price for each pencil in city x is P<sub>x</sub> (0 ≤ P<sub>x</sub> ≤ 10, 000).</p>

<p>Find the minimal price to purchase one pencil on-line and have it shipped to a particular city D (1 ≤ D ≤ N) using the cheapest possible trade-route sequence. Notice that it is possible to purchase the pencil in city D and thus require no shipping charges.</p>

### 입력 

 <p>The first line of input contains N, the number of cities. You can assume the cities are numbered from 1 to N. The second line of input contains T, the number of trade routes. The next T lines each contain 3 integers, x y C(x, y), to denote the cost of using the trade route between cities x and y is C(x, y). The next line contains the integer K, the number of cities with a store that sells really nice pencils on-line. The next K lines contains two integers, z and P<sub>z</sub>, to denote that the cost of a pencil in city z is P<sub>z</sub>. The last line contains the integer D, the destination city</p>

### 출력 

 <p>Output the minimal total cost of purchasing a pencil on-line and shipping it to city D.</p>

