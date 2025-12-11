# [Silver V] Skattkartan - 20861 

[문제 링크](https://www.acmicpc.net/problem/20861) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2025년 12월 11일 21:23:41

### 문제 설명

<p>Paulina gillar Japan, jättemycket. Under en semester i Tokyo besöker hon en nöjespark där det finns en stor labyrint. För att navigera i labyrinten får Paulina en skattkarta som hon följer.</p>

<p>På skattkartan är varje ruta markerad med pilar för att visa åt vilket håll man ska gå från den rutan.</p>

<p>Paulina börjar alltid i den ruta som befinner sig längst upp till vänster på skattkartan, och följer därefter pilarna. I labyrinten finns det två olika mål: en bit smaskig laxsushi, samt en läskig samuraj. Det kan också hända att skattkartan leder runt Paulina i en oändlig cykel av rutor så hon aldrig når ett mål.</p>

<p>Kan du hjälpa Paulina att avgöra vilket mål hon når, eller om hon kommer gå runt i all oändlighet.</p>

### 입력 

 <p>Indatan börjar med en rad som innehåller antalet rader <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>R</mi><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le R \le 100$</span></mjx-container>) i skattkartan. Därefter följer en rad som innehåller antalet kolumner <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$C$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>C</mi><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le C \le 100$</span></mjx-container>) i skattkartan. Slutligen följer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R$</span></mjx-container> rader som alla innehåller <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$C$</span></mjx-container> tecken vardera -- själva skattkartan.</p>

<p>Följande tecken förekommer i skattkartan:</p>

<ul>
	<li>"<code><</code>" -- ruta med vänsterpil,</li>
	<li>"<code>></code>" -- ruta med högerpil,</li>
	<li>"<code>v</code>" -- ruta med nedåtpil,</li>
	<li>"<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2227"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>∧</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\wedge$</span></mjx-container>" -- ruta med uppåtpil,</li>
	<li>"<code>A</code>" -- rutan sushin befinner sig på,</li>
	<li>"<code>B</code>" -- rutan samurajen befinner sig på.</li>
</ul>

<p>Paulina börjar på den första rutan i den första raden av skattkartan. Skattkartan är konstruerad så att Paulina aldrig kommer lämna labyrinten när hon följer pilarna.</p>

### 출력 

 <p>Ditt program ska skriva ut en enda rad med texten </p>

<ul>
	<li>"<code>sushi</code>" om hon når sushin genom att följa pilarna,</li>
	<li>"<code>samuraj</code>" om hon når samurajen genom att följa pilarna,</li>
	<li>"<code>cykel</code>" om hon kommer springa runt i all oändlighet genom att följa pilarna.</li>
</ul>

