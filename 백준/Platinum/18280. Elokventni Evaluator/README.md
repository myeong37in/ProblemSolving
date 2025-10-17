# [Platinum V] Elokventni Evaluator - 18280 

[문제 링크](https://www.acmicpc.net/problem/18280) 

### 성능 요약

메모리: 2184 KB, 시간: 12 ms

### 분류

구현, 문자열, 브루트포스 알고리즘, 많은 조건 분기, 파싱

### 제출 일자

2025년 10월 17일 16:11:26

### 문제 설명

<p>U maloj kućici na livadi, u kojoj jela s roštilja po recepturi starih leskovačkih majstora priprema Kostadin Stefanović, objeduju Matej i gospodin Malnar. Ovoga puta je Matej sazvao sastanak, a tema razgovora je izrada novog sustava za evaluaciju, starog je ipak vrijeme donekle pregazilo. Gospodin Malnar se sa svime složi te nadoda: “...i evaluator mora biti elokventniji.”. “Elokventniji? Kako to misliš elokventniji?! Jesi li siguran da su ovo vrganji?”, odgovorio je Matej. Gospodin Malnar mu tada objasni kako mu je dosta gledanja u jedne te iste poruke poput <code>Točno!</code>, <code>Prekoračeno vremensko ograničenje!</code> ili <code>Pogreška pri kompilaciji!</code>. Evaluatori bi se trebali prilagoditi zadatku i ponekad prokomentirati izlaz natjecateljeva programa, ipak je budućnost u umjetnoj inteligenciji. Vaš je zadatak pomoći Mateju da izradi prototip jednog takvog evaluatora.</p>

<p>Zamislite zadatak u kojem natjecatelj u jednoj liniji mora ispisati matematički izraz oblika:</p>

<p style="text-align: center;"><code><broj><operacija><broj>=<broj></code></p>

<p>pri čemu <code><broj></code> označava bilo koji pozitivan cijeli broj manji ili jednak 10<sup>9</sup> bez vodećih nula, a <code><operacija></code> je jedan od znakova <code>+</code>, <code>-</code>, <code>*</code> ili <code>/</code> koji predstavlja jednu od četiri osnovne matematičke operacije. Izraz koji zadovoljava ova svojstva je <em>dobro formatiran</em>. Elokventni će evaluator na ovom zadatku prikazati jednu od sljedećih poruka:</p>

<ul>
	<li><code>Tocno</code> – ispisan je matematički ispravan izraz koji je dobro formatiran.</li>
	<li><code>Izraz nije ispravno formatiran</code> – ispisani izraz ne odgovara zadanom formatu.</li>
	<li><code>Netocno, umjesto <izraz1> mogli ste ispisati <izraz2></code> – ispisani izraz (<code><izraz1></code>) je dobro formatiran, ali nije matematički točan te je promjenom <strong>najviše dva</strong> znaka u ispisu bilo moguće dobiti potpuno (matematički i formatom) ispravan izraz (<code><izraz2></code>).</li>
	<li><code>Potpuno netocno</code> – ispisani izraz je dobro formatiran, matematički nije točan i nije ga moguće ispraviti koristeći najviše dvije zamjene znakova.</li>
</ul>

### 입력 

 <p>U prvoj se liniji nalazi riječ od najviše 30 znakova koja predstavlja natjecateljevo rješenje iz teksta zadatka. Ta riječ će se sastojati isključivo od dekadskih znamenaka (<code>0</code>, <code>1</code>, . . . , <code>9</code>), osnovnih računskih operatora (<code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>) i znaka jednakosti (<code>=</code>).</p>

### 출력 

 <p>U jedini redak ispišite odgovarajuću poruku elokventnog evaluatora iz teksta zadatka.</p>

