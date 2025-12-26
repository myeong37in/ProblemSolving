/*
역전(aux pile에서 original pile)은 일어나지 않는다.

역전으로 짝이 맞으려면 이전에 이미 맞았을 것

하나씩 옮겨 보면 되겠군
*/

#include <iostream>
#include <deque>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int moves = 0;

    std::deque<int> original, aux;
    int a;
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a;
        original.push_back(a);
    }

    bool okay = false;
    while (true) {
        if (original.empty()) {
            if (aux.empty()) {
                okay = true;
                break;
            }
            else {
                break;
            }
        }

        if (aux.empty() || original.front() != aux.front()) {
            aux.push_front(original.front());
            original.pop_front();

            moves++;
            continue;
        }

        if (!aux.empty() && original.front() == aux.front()) {
            aux.pop_front();
            original.pop_front();

            moves++;
        }
    }

    if (okay) {
        std::cout << moves;
    }
    else {
        std::cout << "impossible";
    }

    return 0;
}