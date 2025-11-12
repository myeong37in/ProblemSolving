/*
N = 2일 때 kang이 잇고 끝

잘 모르겠음. 근데 후공 chan이 항상 우선권을 쥠
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        
        if (N == 2) {
            std::cout << "kang\n";
        }
        else {
            std::cout << "chan\n";
        }
    }

    return 0;
}