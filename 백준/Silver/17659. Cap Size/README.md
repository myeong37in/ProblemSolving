# [Silver II] Cap Size - 17659 

[문제 링크](https://www.acmicpc.net/problem/17659) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

많은 조건 분기

### 제출 일자

2025년 10월 22일 12:12:41

### 문제 설명

<p>Picking the right size of your cap is surprisingly difficult. If your cap is too small, it keeps digging into your head, or — even worse — you can’t even get it over your computer science filled head. And if it is too large, it keeps wiggling, and you know that it will just fall down or be blown away by the wind at the most solemn and important moment. So before committing to a cap size, you tried on several different caps, and recorded how they fit: some might have been too large, some too small, and if you were lucky, one might even have fit perfectly. After trying on some (but maybe not all) caps, you now want to compute how many caps could possibly still fit you perfectly.</p>

### 입력 

 <p>The first line contains a number 1 ≤ K ≤ 100, which is the number of input data sets in the file. This is followed by K data sets of the following form:</p>

<p>The first line of a data set contains two integers n, t with 0 ≤ t ≤ n ≤ 100: n is the number of caps that are available, and t is the number you tried on. This is followed by a line with n integers 0 ≤ s<sub>i</sub> ≤ 1000, giving you the size of the i<sup>th</sup> cap. They will be given in strictly increasing order (which also means that the same cap size never appears twice).</p>

<p>Next are t lines, each with two integers c<sub>i</sub>, f<sub>i</sub>, where 0 ≤ c<sub>i</sub> ≤ 1000 and −1 ≤ f<sub>i</sub> ≤ 1. Here, c<sub>i</sub> is the size of the cap you tried on (which will always be a size occuring in the earlier list of all sizes), and f<sub>i</sub> the fit, where f<sub>i</sub> = −1 means it was too large, f<sub>i</sub> = 0 that it fit perfectly, and f<sub>i</sub> = 1 that it was too small.</p>

### 출력 

 <p>For each data set, first output “Data Set x:” on a line by itself, where x is its number. Then, output the number of caps that might still fit you perfectly based on the information you received. If the input claimed that a large cap was too small and a smaller cap was too large, or that two different cap sizes fit perfectly, then output “Inconsistent feedback” instead.</p>

