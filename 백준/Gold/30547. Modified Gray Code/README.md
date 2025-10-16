# [Gold V] Modified Gray Code - 30547 

[문제 링크](https://www.acmicpc.net/problem/30547) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

비트마스킹, 브루트포스 알고리즘, 자료 구조, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵, 런타임 전의 전처리, 트리를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2025년 10월 16일 18:50:52

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="width: 224px; height: 156px;"></p>

<p>The Gray Code is a well-known binary sequence in which successive elements differ by only one bit, and the bit chosen to be switched yields the smallest normal binary value not yet used.  The first element of the sequence is the binary sequence corresponding to 0. For example, the 3-bit Gray Code sequence is 000, 001, 011, 010, 110, 111, 101, 100.  So the element at index 0 is 000, the element at index 4 is 110, and so on.</p>

<p>We want to modify the Gray Code so that successive elements differ by an even number of bits, but again the bits selected to be changed should yield the smallest normal binary value not yet used.  We call this the even Gray code.  Here are the first 3 elements of the 5-bit even Gray Code:</p>

<pre>0   0 0 0 0 0
1   0 0 0 1 1     (2 bits switched – positions 1 and 2)
2   0 0 1 0 1     (2 bits switched – positions 2 and 3)</pre>

<p>Given an index $K$, give the element at index $K$ in the 10-bit even Gray Code.</p>

### 입력 

 <p>The first line of input consists of an integer $N$ ($1\le N\le 500$), which is the number of queries that will be made.  The remaining $N$ lines each contains a positive integer $K$ ($1 \leq K \leq 500$) representing the index of the 10-bit even Gray Code.</p>

### 출력 

 <p>For each input query, print the 10-bit representation of the corresponding even Gray Code element. There may be leading 0's but there should be no spaces between the digits.</p>

