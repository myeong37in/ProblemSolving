# [Platinum V] Secret Polynomial - 4124 

[문제 링크](https://www.acmicpc.net/problem/4124) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 애드 혹, 많은 조건 분기

### 제출 일자

2026년 3월 10일 23:56:57

### 문제 설명

<p>You may have encountered IQ tests with inane questions such as the following: find the next number in the sequence 1, 2, 3, __. Obviously the correct answer is 16, since the sequence lists the values f(1), f(2), f(3), f(4), ..., where f(x) = 2x<sup>3</sup> - 12x<sup>2</sup> + 23x - 12. More generally, given some information about the values of a polynomial, can you find the polynomial? We will restrict our attention to polynomials whose coefficients are all non-negative integers.</p>

### 입력 

 <p>The first line of input contains an integer 0 < n <= 10000, the number of polynomials to be identified. Each of the next n lines contains two integers, the values f(1) and f(f(1)), where f is the polynomial to be found. Each of these values fits within the range of a signed two's complement 32-bit integer.</p>

### 출력 

 <p>For each polynomial to be found, output a single line listing its coefficients separated by spaces. Assuming the degree of the polynomial is d, list the d+1 coefficients in descending order of power (i.e. starting with the coefficient of xd and finishing with the coefficient of x<sup>0</sup>). If the polynomial is the zero polynomial, just output 0. If no polynomial f has the desired values of f(1) and f(f(1)), instead output a line containing the word IMPOSSIBLE. If multiple polynomials f have the desired values of f(1) and f(f(1)), instead output a line containing the word AMBIGUOUS.</p>

