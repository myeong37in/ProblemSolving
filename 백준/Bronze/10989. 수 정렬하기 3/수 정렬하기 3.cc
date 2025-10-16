/*
핵심: 수의 개수는 1000만 개까지 가능하지만 수 자체는 10,000보다 작거나 같다.
크기가 10,001인 vector를 만들어 index마다 해당 하는 수의 개수를 저장하면 메모리 초과를 방지할 수 있을 것으로 보임
그런데 이게 왜 브론즈 1인가요 실버 5인 옆동네 2751번은 std::sort 딸깍인데
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> vec(10001);
    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        vec[num]++;
    }

    for (int i = 1; i < 10001; i++) {
        if (vec[i]) {
            for (int j = 0; j < vec[i]; j++) {
                std::cout << i << "\n";
            }
        }
    }

    return 0;
}