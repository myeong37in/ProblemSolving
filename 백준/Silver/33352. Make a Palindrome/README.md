# [Silver I] Make a Palindrome - 33352 

[문제 링크](https://www.acmicpc.net/problem/33352) 

### 성능 요약

메모리: 2392 KB, 시간: 8 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 11월 12일 15:28:36

### 문제 설명

<p>You have a string $s$ consisting of lowercase English letters. You want to transform it into a palindrome by performing zero or more operations. In one operation, you can swap any two characters in the string which are at distance exactly $2$ from each other (in other words, there is exactly one character between them).</p>

<p>Determine if it is possible to transform the string $s$ into a palindrome.</p>

<p>A palindrome is a string that coincides with its reversed copy.</p>

### 입력 

 <p>The first line contains an integer $t$ ($1 \le t \le 10^5$), the number of test cases. The test cases follow.</p>

<p>The first line of each test case contains an integer $n$ ($1 \le n \le 10^5$). The second line contains the string $s$ of length $n$ consisting of lowercase English letters.</p>

<p>The sum of $n$ over all test cases does not exceed $10^5$.</p>

### 출력 

 <p>For each test case, print a line containing "<code>YES</code>" if it is possible to transform the given string into a palindrome by the given rules, or "<code>NO</code>" otherwise.</p>

