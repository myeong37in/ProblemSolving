// https://www.acmicpc.net/problem/33952
// PPC와 CPP
// 플래티넘 2

/*
대회에서 못 풀었던 그 문제

P의 개수가 C의 개수의 2배가 아니면 지울 수 없다. "NO"
문자열의 길이가 3의 배수가 아니어도 물론 "NO"

Claim 1. (문자열의 P의 개수 x 2 = C의 개수)이고 시작과 끝 중 하나 이상이 'C'라면 '좋은 문자열' 좋은 문자열은 "YES"
문자열의 시작이 C일 때, 문자열의 길이가 3N(N은 자연수)이라면
str[1] = 'C' (1-based indexing)
str[2] ~ str[3N]에는 C가 N - 1개, P가 2N개 있다.
이 문자열은 C에 의해 N개의 구간으로 나누어지고 비둘기 집의 원리에 의해 2N > (N-1) * 2이므로
C로 나누어지는 구간 중 최소 한 구간은 P가 2개 이상 있다. 이 구간에 대해 CPP, 또는 PPC를 제거할 수 있다.
이후로도 N-1개의 구간에 대해 2N - 2 > (N-2) * 2이므로 CPP, 또는 PPC를 제거할 수 있다.
결과적으로 마지막에 이 구간에 2개의 P만 남는다. 첫 문자인 C와 결합하여 CPP를 제거하여 빈 문자열이 된다.
문자열의 끝이 C일 때도 마찬가지. str[0] ~ str[3N - 2]의 구간에서 동일한 논리를 적용 가능하다. 마지막에 PPC를 제거하여 빈 문자열이 된다.

Claim 2. 어떤 문자열이 PPC 문자열이라는 것과 그 문자열이 좋은 문자열들로 쪼개진다는 것은 동치이다.
어떤 문자열이 좋은 문자열로 쪼개진다면 Claim 1에 의해 이 문자열은 PCC 문자열이다.
어떤 문자열이 PCC 문자열인데 좋은 문자열로 쪼개지지 않는다고 가정, 그 문자열 중 길이가 가장 짧은 문자열을 A라고 하면
A는 PPC 문자열이므로 제일 마지막으로 지워진 PPC에 대해 A에서 P, P, C의 위치를 각각 a, b, c라고 정의한다.
그러면 구간 [1, a - 1]의 문자열은 빈 문자열로 바꿀 수 있어야 하므로 PPC 문자열이다.
    A가 쪼개지지 않는 문자열 중 가장 길이가 짧으므로 A[1, a - 1]은 좋은 문자열로 쪼개진다.
구간 A[a, N]은 Claim 1을 만족하므로 좋은 문자열이다.
따라서 A는 좋은 문자열로 쪼개진다. 이는 가정에 모순이므로 모든 PPC 문자열은 좋은 문자열로 쪼개진다.

Claim 3. 어떤 문자열 str[1, ..., N]이 좋은 문자열로 쪼개진다는 것은 다음의 3가지 중 한 가지를 만족한다는 것과 동치이다.
1) str[1] = 'C'
2) str[N] = 'C'
3) 1 <= i < N에 대해, 다음을 만족하는 i가 존재한다.
    - 구간 [1, i], [i + 1, N] 각각에서 C의 개수 x 2 = P의 개수
    - str[i] = str[i + 1] = C

Claim 3을 만족하는 문자열 str은 Claim 2에 의해 PPC 문자열이다.
*/

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string str;
    std::cin >> str;

    if (N % 3 != 0) {
        std::cout << "NO";
        return 0;
    }

    std::vector<int> p_count(N);
    std::vector<int> c_count(N);
    int total_p = 0;
    int total_c = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == 'P') {
            total_p++;
        }
        else {
            total_c++;
        }

        p_count[i] = total_p;
        c_count[i] = total_c;
    }

    if (p_count[N - 1] != 2 * c_count[N - 1]) { // 개수가 안 맞으면 바로 NO
        std::cout << "NO";
        return 0;
    }

    if (str.front() == 'C' || str.back() == 'C') { // Claim 1에 의해 PPC 문자열
        std::cout << "YES";
        return 0;
    }

    // Claim 3에 의한 문자열 판별 O(N)
    bool both_satisfied = false;
    for (int i = 0; i < N - 1; i++) {
        if (str[i] != 'C' || str[i + 1] != 'C') {
            continue;
        }

        bool left_satisfied = false;
        bool right_satisfied = false;
        if (p_count[i] == 2 * c_count[i]) {
            left_satisfied = true;
        }
        else {
            continue;
        }

        if ((p_count[N - 1] - p_count[i]) == 2 * (c_count[N - 1] - c_count[i])) {
            right_satisfied = true;
        }

        if (right_satisfied && left_satisfied) {
            both_satisfied = true;
            break;
        }
    }

    if (both_satisfied) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    return 0;
}
