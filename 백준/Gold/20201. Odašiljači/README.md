# [Gold III] Odašiljači - 20201 

[문제 링크](https://www.acmicpc.net/problem/20201) 

### 성능 요약

메모리: 14468 KB, 시간: 44 ms

### 분류

이분 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2026년 2월 12일 16:29:52

### 문제 설명

<p>Sadly, this is the last time Sean will play James Bond.</p>

<p>His mission is to network n antennas that are scattered across a vast desert, which can be represented as a 2D plane. He will set the transmission radius of each antenna to be the same non negative real number r. The range of an antenna is defined as the set of all points whose distance to the antenna is at most r. If ranges of two antennas have a common point, those antennas can directly communicate. Also, if antennas A and B can communicate, as well as antennas B and C, then antennas A and C are also able to communicate, through antenna B.</p>

<p>Sean wants to network the antennas, i.e. make possible for <strong>every two</strong> antennas to communicate. Since M has limited his spending for this mission, and larger radii require more money, Sean will choose the <strong>smallest possible radius</strong> r. Help him solve this problem!</p>

### 입력 

 <p>The first line contains an integer n (1 ≤ n ≤ 1000), the number of antennas.</p>

<p>Each of the following n lines contains integers x<sub>i</sub> and y<sub>i</sub> (0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>), coordinates of the i-th antenna.</p>

### 출력 

 <p>Output the minimal radius.</p>

<p>Your answer will be considered correct if its absolute or relative error doesn’t exceed 10<sup>−6</sup>.</p>

