# [Gold II] Taking Turns - 6015 

[문제 링크](https://www.acmicpc.net/problem/6015) 

### 성능 요약

메모리: 18436 KB, 시간: 72 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2026년 3월 1일 00:14:05

### 문제 설명

<p>Farmer John has invented a new way of feeding his cows. He lays out N (1 <= N <= 700,000) hay bales conveniently numbered 1..N in a long line in the barn. Hay bale i has weight W_i (1 <= W_i <= 2,000,000,000). A sequence of six weights might look something like:</p>

<pre>        17 5 9 10 3 8 </pre>

<p>A pair of cows named Bessie and Dessie walks down this line after examining all the haybales to learn their weights. Bessie is the first chooser. They take turns picking haybales to eat as they walk (once a haybale is skipped, they cannot return to it). For instance, if cows Bessie and Dessie go down the line, a possible scenario is:</p>

<ul>
	<li>Bessie picks the weight 17 haybale</li>
	<li>Dessie skips the weight 5 haybale and picks the weight 9 haybale</li>
	<li>Bessie picks the weight 10 haybale</li>
	<li>Dessie skips the weight 3 haybale and picks the weight 8 haybale</li>
</ul>

<p>Diagrammatically:</p>

<pre>Bessie   |      |
        17 5 9 10 3 8 
Dessie       |      |</pre>

<p>This scenario only shows a single skipped bale; either cow can skip as many as she pleases when it's her turn.</p>

<p>Each cow wishes to maximize the total weight of hay she herself consumes (and each knows that the other cow has this goal). Furthermore, a cow will choose to eat the first bale of hay that maximimizes her total weight consumed.</p>

<p>Given a sequence of hay weights, determine the amount of hay that a pair of cows will eat as they go down the line of hay.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: W_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: Two space-separated integers, the total weight of hay consumed by Bessie and Dessie respectively</li>
</ul>

<p> </p>

