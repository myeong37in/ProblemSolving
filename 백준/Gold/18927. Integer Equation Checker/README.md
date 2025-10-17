# [Gold II] Integer Equation Checker - 18927 

[문제 링크](https://www.acmicpc.net/problem/18927) 

### 성능 요약

메모리: 2184 KB, 시간: 12 ms

### 분류

브루트포스 알고리즘, 구현, 파싱, 문자열

### 제출 일자

2025년 10월 17일 16:04:03

### 문제 설명

<p>In this task you need to create a checker for integer equations with error correction.</p>

<p>The integer equation is given in the form:</p>

<pre><number1><operation><number2>=<number3></pre>

<p>wherein "<code><numberI></code>" denotes any positive integer less than or equal to <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9$</span></mjx-container> without leading zeros, and  "<code><operation></code>" is one of the signs '<code>+</code>', '<code>-</code>', '<code>*</code>' or '<code>/</code>' that represents  one of the four basic math operations (note that unary plus and unary minus are <strong>not allowed</strong>). An expression that satisfies these properties is called <em>well-formatted</em>. </p>

<p>The checker shall read the equations and give the outcome in the next way:</p>

<ul>
	<li><code>Correct</code> --- a well-formatted mathematically correct equation is given.</li>
	<li><code>Format Error</code> --- the given equation does not match the default format.</li>
	<li><code>Typo: <equation1> instead of <equation2></code> --- the given equation (<code><equation1></code>) is well-formatted but not mathematically correct and is is enough to replace up to two characters in it to obtain a mathematically correct and well-formatted equation (<code><equation2></code>).</li>
	<li><code>Math Error</code> --- the given equation is well-formatted, mathematically incorrect, and it is impossible to correct two or less characters and obtain a well-formatted and mathematically correct equation.</li>
</ul>

<p>Note that characters can be only replaced, they cannot be inserted or deleted.</p>

### 입력 

 <p>The first line of the input contains a non-empty string of up to 30 characters that represents the equation to be checked. This word consists only of decimal digits ('<code>0</code>' - '<code>9</code>'), arithmetic  operators ('<code>+</code>', '<code>-</code>', '<code>*</code>', and '<code>/</code>') and equality signs ('<code>=</code>').</p>

### 출력 

 <p>Print the result of evaluation. Refer to the samples for clarity.</p>

