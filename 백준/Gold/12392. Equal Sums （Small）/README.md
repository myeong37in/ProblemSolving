# [Gold V] Equal Sums (Small) - 12392 

[문제 링크](https://www.acmicpc.net/problem/12392) 

### 성능 요약

메모리: 25584 KB, 시간: 48 ms

### 분류

백트래킹, 브루트포스 알고리즘

### 제출 일자

2025년 10월 22일 14:30:11

### 문제 설명

<p>I have a set of positive integers <strong>S</strong>. Can you find two non-empty, distinct subsets with the same sum? </p>

<p>Note: A subset is a set that contains only elements from <strong>S</strong>, and two subsets are distinct if they do not have exactly the same elements.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow, one per line. Each test case begins with <strong>N</strong>, the number of positive integers in <strong>S</strong>. It is followed by <strong>N</strong>distinct positive integers, all on the same line.</p>

<h3>Limits</h3>

<ul>
	<li>No two numbers in <strong>S</strong> will be equal.</li>
	<li>1 ≤ <strong>T</strong> ≤ 10.</li>
	<li><strong>N</strong> is <em>exactly</em> equal to 20.</li>
	<li>Each number in <strong>S</strong> will be a positive integer less than 10<sup>5</sup>.</li>
</ul>

### 출력 

 <p>For each test case, first output one line containing "Case #x:", where x is the case number (starting from 1).</p>

<ul>
	<li>If there are two different subsets of <strong>S</strong> that have the same sum, then output these subsets, one per line. Each line should contain the numbers in one subset, separated by spaces.</li>
	<li>If it is impossible, then you should output the string "Impossible" on a single line.</li>
</ul>

<p>If there are multiple ways of choosing two subsets with the same sum, any choice is acceptable.</p>

<p> </p>

<div> </div>

