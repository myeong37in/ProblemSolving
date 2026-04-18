/*
A, B 벡터와 C, D 벡터의 합을 미리 계산하여 저장. 중복이 있을 수 있으니 map을 도입하여 key: 합, value: 그 값이 나온 횟수로 저장. 각각 A_B_sum, C_D_sum
모든 A_B_sum의 key에 대해, 이를 target으로 설정. C_D_sum에서 -target을 key로 하는 요소의 value와 target을 key로 하는 A_B_sum 요소의 value 더하기?
같은 속편한 풀이가 될 리가 없지.
벡터로 저장 후 정렬, 투 포인터로 개수를 세되 같은 요소가 여럿 연달아서 나오는 구간은 그 개수를 계산해서 쌍의 개수를 계산(곱셈), 전체 답에 더하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> A(n);
    std::vector<int> B(n);
    std::vector<int> C(n);
    std::vector<int> D(n);


    for (int i = 0; i < n; i++) {
        std::cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    std::vector<int> A_B_sum;
    std::vector<int> C_D_sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A_B_sum.emplace_back(A[i] + B[j]);
            C_D_sum.emplace_back(C[i] + D[j]);
        }
    }

    std::sort(A_B_sum.begin(), A_B_sum.end());
    std::sort(C_D_sum.begin(), C_D_sum.end());

    long long answer = 0;
    int left = 0;
    int right = C_D_sum.size() - 1;
    int sum;
    while (left <= A_B_sum.size() - 1 && right >= 0) {
        sum = A_B_sum[left] + C_D_sum[right];
        if (sum > 0) {
            right--;
        }
        else if (sum < 0) {
            left++;
        }
        else {
            int AB_value = A_B_sum[left];
            int CD_value = C_D_sum[right];

            long long AB_count = std::upper_bound(A_B_sum.begin() + left, A_B_sum.end(), AB_value) - A_B_sum.begin() - left; // AB_value의 개수
            left += AB_count;
            
            long long CD_count = right - (std::lower_bound(C_D_sum.begin(), C_D_sum.begin() + right + 1, CD_value) - C_D_sum.begin()) + 1; // CD_value의 개수
            right -= CD_count;

            answer += AB_count * CD_count; // 쌍의 개수는 곱한 값
        }
    }

    std::cout << answer;

    return 0;
}