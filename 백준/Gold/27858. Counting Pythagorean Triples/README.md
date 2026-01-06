# [Gold V] Counting Pythagorean Triples - 27858 

[문제 링크](https://www.acmicpc.net/problem/27858) 

### 성능 요약

메모리: 2032 KB, 시간: 12 ms

### 분류

브루트포스 알고리즘, 수학

### 제출 일자

2026년 1월 6일 15:21:27

### 문제 설명

<p>A Pythagorean triple is a set of three positive integers, a, b and c, for which:</p>

<p style="text-align: center;">a² + b² = c²</p>

<p>A Pythagorean triple is a Primitive Pythagorean Triple (PPT) if a, b and c have no common factors.</p>

<p>Write a program which takes as input a positive integer, n, and outputs a count of:</p>

<ol>
	<li>The number of different PPTs in which n is the hypotenuse ( c ).</li>
	<li>The number of non-primitive Pythagorean triples in which n is the hypotenuse ( c ).</li>
	<li>The number of different PPTs in which n is one of the sides ( a or b ).</li>
	<li>The number of non-primitive Pythagorean triples in which n is the one of the sides ( a or b ).</li>
</ol>

<p>For the same a, b, c: b, a, c is the “same” as a, b, c (i.e it only counts once). Non-primitive Pythagorean triples are Pythagorean triples which are not PPT.</p>

<p>For example, in the case of n = 65, the following are the cases for each of the criteria above:</p>

<ol>
	<li>33, 56, 65; 63, 16, 65</li>
	<li>39, 52, 65; 25, 60, 65</li>
	<li>65, 72, 97; 65 2112 2113</li>
	<li>65, 420, 425; 65, 156, 169</li>
</ol>

### 입력 

 <p>Input consists of a single line containing a single non-negative decimal integer n, (3 ≤ n ≤ 2500).</p>

### 출력 

 <p>There is one line of output. The single output line contains four decimal integers:</p>

<p>The first is the number of different PPTs in which n is the hypotenuse ( c ).</p>

<p>The second is the number of non-primitive Pythagorean triples in which n is the hypotenuse ( c).</p>

<p>The third is the number of different PPTs in which n is the one of the sides ( a or b ).</p>

<p>The fourth is the number of non-primitive Pythagorean triples in which n is the one of the sides (a or b).</p>

