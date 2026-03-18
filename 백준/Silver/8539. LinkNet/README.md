# [Silver I] LinkNet - 8539 

[문제 링크](https://www.acmicpc.net/problem/8539) 

### 성능 요약

메모리: 3320 KB, 시간: 28 ms

### 분류

자료 구조, 정렬, 스위핑, 우선순위 큐

### 제출 일자

2026년 3월 18일 10:54:14

### 문제 설명

<p>W sieci LinkNet komputery są przyłączone do linii komunikacyjnej w sposób przedstawiony na rysunku. Dostępne punkty przyłączeń są ponumerowane kolejno 0, 1, ..., <em>R</em>. Do jednego punktu może być przyłączony tylko jeden komputer. Każdy z komputerów może być przyłączony do sieci tylko w jednym punkcie. Komunikacja w sieci jest synchroniczna.</p>

<center style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/01e6c4a7-eda1-44e3-a40d-a58b9ca66236/-/preview/"></center>

<p>W danym takcie komputery przyłączone do punktów 0 ≤ <em>a</em> < <em>b</em> ≤ <em>R</em> mogą dokonać transmisji danych tylko wtedy, gdy żaden komputer przyłączony do łącza o numerze <em>c</em>, <em>a</em> < <em>c</em> < <em>b</em> nie bierze udziału w transmisji danych z jakimkolwiek innym komputerem. W jednym takcie komputer może brać udział tylko w jednej tranmisji.</p>

<p>Napisz program który:</p>

<ul>
	<li>wczytuje opisy transmisji, które trzeba zrealizować,</li>
	<li>oblicza jaka jest minimalna liczba taktów wystarczających do zrealizowania transmisji,</li>
	<li>wypisuje obliczoną liczbę.</li>
</ul>

### 입력 

 <p>W pierwszym wierszu danych podana jest liczba transmisji <em>N</em>: 0 ≤ <em>N</em> ≤ 100000. W kolejnych <em>N</em> wierszach podane są opisy transmisji - po jednym w wierszu. Opis każdej transmisji składa się z dwóch liczb <em>a</em>, <em>b</em>: 0 ≤ <em>a</em> < <em>b</em> ≤ 1 000 000 000, oznaczających numery punktów, pomiędzy którymi ma być transmisja danych. Liczby <em>a</em> i <em>b</em> są oddzielone spacją.</p>

### 출력 

 <p>W pierwszym i jedynym wierszu wyniku powinna być podana jedna liczba: minimalna liczba taktów wystarczających do zrealizowania wszystkich transmisji opisanych w danych.</p>

