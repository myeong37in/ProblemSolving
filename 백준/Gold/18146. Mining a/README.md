# [Gold II] Mining a - 18146 

[문제 링크](https://www.acmicpc.net/problem/18146) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학

### 제출 일자

2025년 9월 29일 23:49:07

### 문제 설명

<p>Blockchain technology is used in many digital currency systems, such as Bitcoin and Ethereum. In this technology, distributed users share a common list of records (called the chain), and a user has the right to add a new record to the chain by solving a mathematical problem. This process is called mining. The i-Taiwan company has developed up a new digital currency system, called the ICPC (I-taiwan Coins for the Public Currency). In the ICPC system, its mathematical problem for mining is as follows. Given positive integer n, the problem asks one to find the largest integer a such that</p>

<p>1/n = 1/(a⊕b) + 1/b, for some positive integer b</p>

<p>where ⊕ is the bitwise exclusive-or operator. For example, for n = 12, its solution is a = 145. In this case, b = 13 and thus a ⊕ b = 145 ⊕ 13 = 10010001<sub>2</sub> ⊕ 1101<sub>2</sub> = 10011100<sub>2</sub> = 156. Accordingly,</p>

<p>1/(a⊕b) + 1/b = 1/156 + 1/13 = 1/12 = 1/n.</p>

<p>You are an ambitious programmer, and you want to mine a lot of digital coins from this system in a short time. Please write a program to find the largest a for each n in order to earn the rewards from ICPC.</p>

### 입력 

 <p>The first line of the input file contains exactly one positive integer T that gives you the number of test cases. In the following T lines, each line corresponds to one test case and specifies the integer n.</p>

### 출력 

 <p>For each test case, output the largest number a in one line.</p>

