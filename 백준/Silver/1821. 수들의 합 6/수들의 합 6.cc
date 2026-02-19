/*
편한 길을 갑시다.

N = 1일 때 답: 1

a + b + e + ...라고 할 때

N = 2일 때 a + b -> 1, 1 조합
N = 3일 때 a + 2b + c -> 1, 2, 1 조합
N = 4일 때 a + 3b + 3c + d -> 1, 3, 3, 1 조합
N = 5일 때 1, 4, 6, 4, 1 조합
N = 6일 때 1, 5, 10, 10, 5, 1 조합
N = 7일 때 1, 6, 15, 20, 15, 6, 1 조합
N = 8일 때 1, 7, 21, 35, 35, 21, 7, 1 조합
N = 9일 때 1, 8, 28, 56, 70, 56, 28, 8, 1 조합
N = 10일 때 1, 9, 36, 84, 126, 126, 84, 36, 9, 1 조합

그리고 next_permutation
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, F;
    std::cin >> N >> F;

    std::vector<std::vector<int>> seq = {{},
                                         {},
                                         {1, 1},
                                         {1, 2, 1},
                                         {1, 3, 3, 1},
                                         {1, 4, 6, 4, 1},
                                         {1, 5, 10, 10, 5, 1},
                                         {1, 6, 15, 20, 15, 6, 1},
                                         {1, 7, 21, 35, 35, 21, 7, 1},
                                         {1, 8, 28, 56, 70, 56, 28, 8, 1},
                                         {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}};
    
    if (N == 1) {
        std::cout << 1;
        return 0;
    }

    std::vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        nums[i] = i + 1;
    }

    do {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i] * seq[N][i];
        }

        if (sum == F) {
            for (int n : nums) {
                std::cout << n << " ";
            }
            break;
        }
    } while (std::next_permutation(nums.begin(), nums.end()));

    return 0;
}