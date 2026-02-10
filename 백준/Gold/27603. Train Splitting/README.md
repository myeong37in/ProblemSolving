# [Gold II] Train Splitting - 27603 

[문제 링크](https://www.acmicpc.net/problem/27603) 

### 성능 요약

메모리: 2152 KB, 시간: 16 ms

### 분류

그래프 이론, 자료 구조, 해 구성하기, 분리 집합

### 제출 일자

2026년 2월 10일 10:47:57

### 문제 설명

<p>There are $n$ big cities in Italy, and there are $m$ train routes between pairs of cities. Each route connects two different cities bidirectionally. Moreover, using the trains one can reach every city starting from any other city.</p>

<p>Right now, all the routes are operated by the government-owned Italian Carriage Passenger Company, but the government wants to privatize the routes. The government does not want to give too much power to a single company, but it also does not want to make people buy a lot of different subscriptions. Also, it would like to give a fair chance to all companies. In order to formalize all these wishes, the following model was proposed.</p>

<p>There will be $k ≥ 2$ private companies indexed by $1, 2, \dots , k$. Each train route will be operated by exactly one of the $k$ companies. Then:</p>

<ul>
	<li>For any company, there should exist two cities such that it is impossible to reach one from the other using only routes operated by that company.</li>
	<li>On the other hand, for any two companies, it should be possible to reach every city from any other city using only routes operated by these two companies.</li>
</ul>

<p>Find a plan satisfying all these criteria. It can be shown that a viable plan always exists. Please note that you can choose the number $k$ and you do not have to minimize or maximize it.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 1000$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>The first line of each test case contains two integers $n$ and $m$ ($3 ≤ n ≤ 50$, $n-1 ≤ m ≤ n(n-1)/2$) — the number of cities and the number of train routes.</p>

<p>The next $m$ lines contain two integers $u_i$ and $v_i$ each ($1 ≤ u_i , v_i ≤ n$, $u_i \ne v_i$) — the $i$-th train route connects cities $u_i$ and $v_i$.</p>

<p>It is guaranteed that the routes connect $m$ distinct pairs of cities. It is guaranteed that using the trains one can reach every city starting from any other city.</p>

<p>The sum of the values of $n$ over all test cases does not exceed $5000$.</p>

### 출력 

 <p>For each test case, on the first line print an integer $k$ ($2 ≤ k ≤ m$) — the number of companies in your plan; on the second line print $m$ integers $c_1, c_2, \dots , c_m$ ($1 ≤ c_i ≤ k$) — in your plan company $c_i$ operates the $i$-th route.</p>

<p>If there are multiple valid plans, you may print any of them.</p>

