// https://www.acmicpc.net/problem/12850
// 본대 산책2
// 플래티넘 5

/*
상식적인 입력을 가진 난이도 실버 1 '본대 산책'은 DP로 손쉽게 클리어

i는 0번부터 7번까지 각각 '정보과학관', '전산관', '미래관', '신양관', '환경직기념관', '진리관', '학생회관', '형남공학관'으로 정함
K분일 때 0번 건물에 도달하는 경로의 수는 K-1분일 때 0번과 연결된 1, 2번 건물에 도달하는 경로의 수와 같다.
K분일 때 1번 건물에 도달하는 경로의 수는 K-1분일 때 1번과 연결된 0, 2, 3번 건물에 도달하는 경로의 수와 같다.
나머지 건물에 대해서도 일반화를 하면, K분일 때 모든 건물로 가는 경로의 수를와 K-1분일 때의 경로의 수를 8x1 matrix로 나타내면

[K_0]   [0 1 1 0 0 0 0 0]   [(K-1)_0]
[K_1]   [1 0 1 1 0 0 0 0]   [(K-1)_1]
[K_2]   [1 1 0 1 1 0 0 0]   [(K-1)_2]
[K_3] = [0 1 1 0 1 1 0 0] x [(K-1)_3]
[K_4]   [0 0 1 1 0 1 0 1]   [(K-1)_4]
[K_5]   [0 0 0 1 1 0 1 0]   [(K-1)_5]
[K_6]   [0 0 0 0 0 1 0 1]   [(K-1)_6]
[K_7]   [0 0 0 0 1 0 1 0]   [(K-1)_7]

이 성립한다. 이를 일반화하여

[K_0]   [0 1 1 0 0 0 0 0]^(K-1)   [1_0]   [0 1 1 0 0 0 0 0]^(K-1)   [0]
[K_1]   [1 0 1 1 0 0 0 0]         [1_1]   [1 0 1 1 0 0 0 0]         [1]
[K_2]   [1 1 0 1 1 0 0 0]         [1_2]   [1 1 0 1 1 0 0 0]         [1]
[K_3] = [0 1 1 0 1 1 0 0] x       [1_3] = [0 1 1 0 1 1 0 0] x       [0]
[K_4]   [0 0 1 1 0 1 0 1]         [1_4]   [0 0 1 1 0 1 0 1]         [0]
[K_5]   [0 0 0 1 1 0 1 0]         [1_5]   [0 0 0 1 1 0 1 0]         [0]
[K_6]   [0 0 0 0 0 1 0 1]         [1_6]   [0 0 0 0 0 1 0 1]         [0]
[K_7]   [0 0 0 0 1 0 1 0]         [1_7]   [0 0 0 0 1 0 1 0]         [0]

이때 [1_i]: 1분에 i번 건물에 도달하는 경로의 수

기본적으로 분할 정복으로 피보나치 수를 구하는 문제와 동일한 논리 구조
*/

#define MOD 1000000007

#include <iostream>
#include <vector>

std::vector<std::vector<long long>> M = {{0, 1, 1, 0, 0, 0, 0, 0},
                                         {1, 0, 1, 1, 0, 0, 0, 0},
                                         {1, 1, 0, 1, 1, 0, 0, 0},
                                         {0, 1, 1, 0, 1, 1, 0, 0},
                                         {0, 0, 1, 1, 0, 1, 0, 1},
                                         {0, 0, 0, 1, 1, 0, 1, 0},
                                         {0, 0, 0, 0, 0, 1, 0, 1},
                                         {0, 0, 0, 0, 1, 0, 1, 0}};

std::vector<std::vector<long long>> N = {{0}, 
                                         {1},
                                         {1},
                                         {0},
                                         {0},
                                         {0},
                                         {0},
                                         {0}};

// 8x8 행렬에 8x8 행렬을 곱해 8x8 행렬을 반환하는 함수
std::vector<std::vector<long long>> MatMul88x88(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
    std::vector<std::vector<long long>> result(8, std::vector<long long> (8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }

    return result;
}

// 8x8 행렬에 8x1 행렬을 곱해 8x1 행렬을 반환하는 함수
std::vector<std::vector<long long>> MatMul88x81(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
    std::vector<std::vector<long long>> result(8, std::vector<long long> (1));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            result[i][0] = (result[i][0] + (A[i][j] * B[j][0]) % MOD) % MOD;
        }
    }
    return result;
}

std::vector<std::vector<long long>> DivideAndConquer(int K) {
    if (K == 1) {
        return M;
    }

    std::vector<std::vector<long long>> half = DivideAndConquer(K / 2);
    if (K % 2 == 0) {
        return MatMul88x88(half, half);
    }
    else {
        return MatMul88x88(MatMul88x88(half, half), M);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int D;
    std::cin >> D;

    // i번 건물에 도달하는 경로 수는 [i][0]
    std::cout << MatMul88x81(DivideAndConquer(D - 1), N)[0][0];

    return 0;
}
