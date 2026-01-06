# [Gold V] Coordinates - 13899 

[문제 링크](https://www.acmicpc.net/problem/13899) 

### 성능 요약

메모리: 44884 KB, 시간: 736 ms

### 분류

그래프 이론, 그래프 탐색, 깊이 우선 탐색

### 제출 일자

2026년 1월 6일 14:57:10

### 문제 설명

<p>In this problem, you are an advisor to a galactic empire that tries to locate all the rebel bases on a planet Taboo. The map of the planet Taboo is a grid of size 10<sup>8</sup> ×10<sup>8</sup> and a position of a rebel based can be described by coordinate (x,y) where 0 ≤ x, y < 10<sup>8</sup>.</p>

<p>The empire captures a number of the rebels that surrender and interrogate them about the locations of the bases. Unfortunately, each surrendered rebel can only tell how far along X axis and Y axis a pair of bases are. Your job in this problem is to help reconstructing possible coordinates of all the bases that is consistent with all the interrogations.</p>

### 입력 

 <p>First line consists of two integers, N and M where 1 ≤ N ≤ 100 000 is the number of bases and N ≤ M ≤ 1 000 000 is the number of captured rebels.</p>

<p>The next M lines consist of 4 integers, a<sub>i</sub>, b<sub>i</sub>, dx<sub>i</sub>, and dy<sub>i</sub> where 1 ≤ a<sub>i</sub> , b<sub>i</sub> ≤ N, -10<sup>8</sup> ≤ dx<sub>i</sub>, dy<sub>i </sub>≤ 10<sup>8</sup> indicating that the x-coordinate of base bi subtracted with the x-coordinate of base a<sub>i</sub> is dx<sub>i</sub> and the y-coordinate of base b<sub>i</sub> subtracted with the y-coordinate of base a<sub>i</sub> is dy<sub>i</sub></p>

<p>It is guaranteed that we can always deduce the positions of the bases from the input. </p>

### 출력 

 <p>The output consists of N lines each line consists of 2 integers x<sub>j</sub> and y<sub>j</sub> indicating possible position of the j th base. You can answer any solution that is consistent with all the interrogations. Translation of map is possible to outside of [0, 10<sup>8</sup>], however, the output coordinate of each base must be between -10<sup>9</sup> to 10<sup>9</sup></p>

