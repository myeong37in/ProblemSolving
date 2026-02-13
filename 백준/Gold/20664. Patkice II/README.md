# [Gold I] Patkice II - 20664 

[문제 링크](https://www.acmicpc.net/problem/20664) 

### 성능 요약

메모리: 55016 KB, 시간: 332 ms

### 분류

구현, 그래프 이론, 최단 경로, 데이크스트라, 역추적, 0-1 너비 우선 탐색

### 제출 일자

2026년 2월 13일 16:02:13

### 문제 설명

<p>After Holywood got its hands on the fascinating story of the successful umbrella voyage between two islands, Netflix executives decided to make a series adaptation of the three ducks' travels.</p>

<p>As you may remember from the first round of COCI 20/21, the ducks have a map of ocean currents. The ducks travel together. The island where the ducks live is marked by the letter '<code>o</code>'. The ducks can start their voyage in any of the four directions. Ocean currents in these seas move in one of the four directions, and are marked in the following way: west-east '<code>></code>', east-west '<code><</code>', north-south '<code>v</code>' and south-north '<code>^</code>'. When the ducks are located on a cell with a current, they will move one cell in the direction of the current.</p>

<p>Calm sea is marked by a dot '<code>.</code>'. If the currents bring the ducks to a cell with calm sea, outside the map, or back to the starting island, they will stop their voyage. The island that the ducks want to visit is marked by '<code>x</code>'.</p>

<p>In order to make the series more appealing, Netflix made a few changes to the story: the sea now may contain wild vortexes (the ducks can get stuck in a cycle) and sea currents that carry the ducks outside the map. (The ducks also form a heartbreaking love triangle, but that is not important right now.)</p>

<p>Therefore, the original map of currents has been changed. But under heavy deadline pressure, the director has made some mistakes: the ducks cannot arrive from the initial to the target island via sea currents anymore.</p>

<p>Netflix directors are very important persons, so they don't really spend time contemplating plot holes. Thus it is your task now to replace as few as possible characters on the map, so that the ducks can go from the initial to the target island.</p>

<p>For story purposes, the cells with ('<code>o</code>' and '<code>x</code>') cannot be modified. All other cells are either sea currents or calm sea (characters '<code><>v^.</code>'). You can replace characters in those cells with characters from the same set '<code><>v^.</code>'.</p>

### 입력 

 <p>The first line contains integers r and s (3 ≤ r, s ≤ 2000), the number of rows and columns of the map.</p>

<p>Each of the following r lines contains s characters from the set '<code>o<>v^.x</code>', that represent the map of ocean currents. There will always be exactly one character '<code>o</code>' and exactly one character '<code>x</code>' on the map, and they will not be adjacent.</p>

### 출력 

 <p>In the first line output k, the minimum number of changes so that the ducks can go from the initial to the target island.</p>

<p>In the each of the next r lines, output s characters, describing a map which differs from the input map in exactly k cells, satisfying the requirements of the problem.</p>

<p>If there are multiple valid maps, output any of them.</p>

