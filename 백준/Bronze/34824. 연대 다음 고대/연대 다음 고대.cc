#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string str;
    for (int i = 0; i < N; i++) {
        std::cin >> str;

        if (str == "yonsei") {
            std::cout << "Yonsei Won!";
            return 0;
        }
        else if (str == "korea") {
            std::cout << "Yonsei Lost...";
            return 0;
        }
    }

    return 0;
}