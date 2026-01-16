#include <iostream>

static inline bool IsDead(int weight, int daesa) {
    return (weight <= 0 || daesa <= 0);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int W0, I0, T, D, I, A;
    std::cin >> W0 >> I0 >> T >> D >> I >> A;

    int weight = W0;
    int daesa = I0;
    int gain;
    bool danger1 = false, danger2 = false;

    // 일일 기초 대사량 안 변함
    for (int i = 0; i < D; i++) {
        gain = (I - (daesa + A));
        weight += gain;
        
        if (IsDead(weight, daesa)) {
            danger1 = true;
            break;
        }
    }

    if (danger1) {
        std::cout << "Danger Diet\n";
    }
    else {
        std::cout << weight << " " << daesa << "\n";
    }

    // 일일 기초 대사량 변함
    weight = W0;
    for (int i = 0; i < D; i++) {
        gain = (I - (daesa + A));
        weight += gain;
        if (-gain > T) {
            daesa += (gain - 1) / 2; // 이렇게 하면 작은 정수로 갈 듯
        }

        if (IsDead(weight, daesa)) {
            danger2 = true;
            break;
        }
    }

    if (danger2) {
        std::cout << "Danger Diet\n";
    }
    else {
        std::cout << weight << " " << daesa;
        if (I0 - daesa > 0) {
            std::cout << " YOYO";
        }
        else {
            std::cout << " NO";
        }
    }

    return 0;
}