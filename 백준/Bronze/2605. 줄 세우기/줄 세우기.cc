#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq;
    int n;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        seq.insert(seq.begin() + (i - n), i + 1); // 전체 i명일 때 뒤에서부터 세어서 n번째 자리로 들어감
    }

    for (int i : seq) {
        std::cout << i << " ";
    }

    return 0;
}