# [Gold V] Knigs of the Forest - 5016 

[문제 링크](https://www.acmicpc.net/problem/5016) 

### 성능 요약

메모리: 3320 KB, 시간: 44 ms

### 분류

구현, 자료 구조, 정렬, 시뮬레이션, 우선순위 큐

### 제출 일자

2026년 4월 3일 15:17:43

### 문제 설명

<p>All moose are knigs of the forest, but your latest moose-friend, Karl-Älgtav, is more interesting than most. In part because of his fondness of fermented blueberries, and in part because of the tribe he lives in. Each year his tribe holds a tournament to determine that year’s alphamoose. The winner gets to mate with all the moose-chicks, and then permanently leaves the tribe. The pool of contenders stays constant over the years, apart from the old alpha-moose being replaced by a newcomer in each tournament.</p>

<p>Karl-Älgtav has recently begun to wonder when it will be his turn to win all the chicks, and has asked you to help him determine this. He has supplied a list of the strength of each of the other male moose in his tribe that will compete during the next n−1 years, along with their time of entry into the tournament. Assuming that the winner each year is the moose with greatest strength, determine when Karl-Algtav ¨ becomes the alpha-moose.</p>

### 입력 

 <p>The first line of input contains two space separated integers k (1 ≤ k ≤ 10<sup>5</sup>) and n (1 ≤ n ≤ 10<sup>5</sup>), denoting the size of the tournament pool and the number of years for which you have been supplied sufficient information.</p>

<p>Next is a single line describing Karl-Älgtav, containing the two integers y (2011 ≤ y ≤ 2011 + n − 1) and p (0 ≤ p ≤ 2<sup>31</sup> − 1). These are his year of entry into the tournament and his strength, respectively.</p>

<p>Then follow n + k − 2 lines describing each of the other moose, in the same format as for Karl-Älgtav.</p>

<p>Note that exactly k of the moose will have 2011 as their year of entry, and that the remaining n − 1 moose will have unique years of entry.</p>

<p>You may assume that the strength of each moose is unique.</p>

### 출력 

 <p>The year Karl-Älgtav wins the tournament, or unknown if the given data is insufficient for determining this.</p>

