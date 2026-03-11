/*
6 10 8은 10이 빗변인 직각삼각형으로 r = 5

10 10 10은 정삼각형 아닌가..? 근데 이렇게 되면 r cos (pi/6) = 5에서 r = 5 * sqrt(2)인데

답은 10 * sqrt(3) / 3이네

진짜 레전드다 중학교 수학도 못하네;; cos (pi/6)은 sqrt(3)/2지...

아무튼 세 점을 모두 포함하는 원이 최소 원임.

삼각형의 세 변의 길이가 주어졌을 때 외접원의 반지름 길이? 고등학교 다닐 때는 공식을 외웠지만.. 까먹었으니 유도해 봅시다.

대충 삼각형 모양 

    A

B               C

|AB| = a, |BC| = b, |CA| = c, 가장 긴 변이 b 가정

원의 중심 O에서 세 꼭짓점으로 향하는 선을 그으면 다른 한 변의 길이가 각각 a, b, c이고 길이가 같은 변의 길이가 r인 이등변 삼각형이 나옴

변의 길이가 a, r, r인 이등변 삼각형을 반 쪼개서 직각삼각형으로 만들면

r * sin(∠AOB/2) = a/2

2r = a / sin(∠AOB/2)

다른 이등변 삼각형에서도 동일하게

2r = a / sin(∠AOB/2) = b / sin(∠BOC/2) = c / sin(∠COA/2)

삼각형 ABC와 AOB를 보면, 둘은 같은 호 AB에 대응되므로 ∠AOB/2 = ∠ACB임. 원주각과 중심각의 관계까지 증명하기에는 너무 귀찮으니 패스

삼각형 ABC의 넓이는 1/2 * b * c * sin(∠ACB)이므로 (밑변: b, 높이 h = c * sin(∠ACB))

2r = a / sin(∠AOB/2) = a / sin(∠ACB)

sin(∠ACB) = a/2r

따라서 삼각형 ABC의 넓이 = abc / 4r

r = abc / 4 * (삼각형 ABC의 넓이)

이제 넓이만 구하면 되는데, 넓이 어떻게 구함?

수선의 발 내려서 전개를 해봅시다.

점 C에서 AB로 내린 수선의 발을 H라고 하면 밑변 AB = a, 높이 CH = h(= c * sin(∠ACB)), AH = x, BH = a - x

h^2 = c^2 - x^2 = b^2 - (a - x)^2

c^2 - x^2 = b^2 - a^2 + 2ax - x^2

x = (c^2 - b^2 + a^2) / 2a

따라서 h^2 = c^2 - x^2 = c^2 - ((c^2 - b^2 + a^2) / 2a)^2
= (c - (c^2 - b^2 + a^2) / 2a))(c + (c^2 - b^2 + a^2) / 2a))

= (c+a+b)(c+a-b)(b-a+c)(b+a-c) / 4a^2

h = sqrt((c+a+b)(c+a-b)(b-a+c)(b+a-c)) / 2a

삼각형 ABC의 넓이 = ah/2 = sqrt((c+a+b)(c+a-b)(b-a+c)(b+a-c)) / 4

r = abc / sqrt((c+a+b)(c+a-b)(b-a+c)(b+a-c))

..인데 이건 예각 삼각형일 때의 이야기고

삼각형을 이루지 못하거나(a <= b <= c일 때 a + b <= c) 직각, 둔각 삼각형이면 외접원보다 가장 긴 변이 원의 지름이 되게 만드는 것이 이득

직각이면 자동으로 빗변이 지름이 되기도 함
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<long double> seq(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    long double a, b, c;
    a = seq[0];
    b = seq[1];
    c = seq[2];

    if (a * a + b * b > c * c) {
        std::cout << std::fixed << std::setprecision(10) << (a * b * c) / std::sqrt((c + a + b) * (c+ a - b) * (b - a + c) * (b + a - c));
        return 0;
    }

    std::cout << std::fixed << std::setprecision(10) << c / 2.0;    
    
    return 0;
}