# [Silver I] Žoliapjovė - 7257 

[문제 링크](https://www.acmicpc.net/problem/7257) 

### 성능 요약

메모리: 3592 KB, 시간: 36 ms

### 분류

정렬, 이분 탐색, 누적 합

### 제출 일자

2026년 2월 19일 12:45:01

### 문제 설명

<p>Prie Martyno sodybos yra pievelė. Į šią pievelę galima žiūrėti kaip į N centimetrų tiesę, kurioje kas centimetrą išdygęs a<sub>i</sub> (1 ≤ i ≤ N) centimetrų aukščio žolės kuokštas.</p>

<p>Iki šiol žolė nebuvo pjaunama ir dabar po šią pievelę vargiai išeina pasivaikščioti, o ką jau kalbėti apie piknikus.</p>

<p>Martynas nusipirko žoliapjovę ir ketina per M dienų nupjauti didžiąją dalį žolės. Kiekviena diena j (1 ≤ j ≤ M) atrodo taip:</p>

<ul>
	<li>Ryte visi dar pilnai nenupjauti žolės kuokštai (a<sub>i</sub> ≠ 0) paauga per 1cm.</li>
	<li>Dieną Martynas pasiima žoliapjovę ir b<sub>j</sub> kartų pjaudamas pervažiuoja pievelę. Kiekvieno pjovimo metu visi nenupjauti žolės kuokštai nupjaunami (sumažėja aukštis) po 1cm;</li>
	<li>Po to Martynas suskaičiuoja kiek centimetrų žolės dar liko nenupjauta.</li>
</ul>

<p>Pjauti žolę Martynui yra išties smagu, tačiau skaičiuoti kiek žolės liks nupjauti kitomis dienomis tampa vis sunkiau ir sunkiau. Todėl Martynas prašys jūsų apskaičiuoti šį skaičių M kartų.</p>

<p>Sakykime, pievelės ilgis yra 4cm (N = 4) ir joje auga tokio aukščio žolės kuokštai:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f70f0c5e-aea0-4eca-ac7f-f9204a9da797/-/preview/" style="width: 390px; height: 179px;"></p>

<p>Martynas dirbs M = 2 dienas. Pirmąją dieną jis pievą pervažiuos su žoliapjove b<sub>1</sub> = 2 kartus, o antrąją dieną pervažiuos b<sub>2</sub> = 1 kartą.</p>

<p>Pirmosios dienos ryte pievelė paaugs per 1cm:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/58520ba5-93bf-4eee-ae40-9f7691888e97/-/preview/" style="width: 390px; height: 179px;"></p>

<p>Dieną Martynas pjaudamas pervažiuoja pievelę pirmą kartą:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d180cd86-a07c-45a7-aaaf-ec128b098787/-/preview/" style="width: 390px; height: 179px;"></p>

<p>ir antrą kartą:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/78413a9a-3390-4898-b694-9a635860ac5f/-/preview/" style="width: 390px; height: 179px;"></p>

<p>Vakare jam lieka nupjauti 0 + 1 + 0 + 2 = 3cm žolės.</p>

<p>Antros dienos rytą žolė vėl paauga (aukščiai ties centimetru 1 ir 3 nesikeičia, nes juose neauga žolė):</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e176f9d3-5264-4b8c-b8c2-56b479bc3dc3/-/preview/" style="width: 390px; height: 179px;"></p>

<p>Martynas pervažiuoja su žoliapjove vieną kartą:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c3177971-b17a-4acf-80da-ea1f8f24f704/-/preview/" style="width: 390px; height: 179px;"></p>

<p>Po to dar liks nupjauti 0 + 1 + 0 + 2 = 3cm žolės.</p>

<p>Duota pradinė pievelės būsena ir M dienų žolės pjovimo planas. Suskaičiuokite, kiek liks nenupjautos žolės kiekvienos iš M dienų vakare.</p>

### 입력 

 <ul>
	<li>Pirmoje eilutėje pateiktas sveikasis skaičius N – pievelės ilgis.</li>
	<li>Antrojoje eilutėje pateikta N tarpu atskirtų skaičių a<sub>i</sub> (1 ≤ i ≤ N) – žolės kuokštų aukščiai.</li>
	<li>Trečiojoje eilutėje pateiktas sveikasis skaičius M, rodantis kelias dienas Martynas pjaus žolę.</li>
	<li>Ketvirtojoje eilutėje, pateikta M tarpu atskirtų skaičių b<sub>j</sub> (1 ≤ j ≤ M) – šie skaičiai nurodo kiek kartų j-ąją dieną Martynas pjaus žolę.</li>
</ul>

### 출력 

 <p>Išveskite M eilučių. Eilutėje k (1 ≤ k ≤ M) turi būti pateiktas vienas sveikasis skaičius – bendras nenupjautos žolės aukštis centimetrais k-tosios dienos pabaigoje.</p>

