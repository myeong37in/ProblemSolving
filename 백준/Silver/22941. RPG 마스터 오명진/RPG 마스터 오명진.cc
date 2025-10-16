/*
0.3 초 (추가 시간 없음) -> 무슨 뜻인지 뻔하죠?
*/

#include <iostream>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 힐하면 체력이 int를 넘을 수 있지
    long long hero_hp, hero_atk, mawang_hp, mawang_atk, skill_hp, heal;
    std::cin >> hero_hp >> hero_atk >> mawang_hp >> mawang_atk >> skill_hp >> heal;

    long long hero_die_turn = (hero_hp + mawang_atk - 1) / mawang_atk;
    long long mawang_die_turn = (mawang_hp + hero_atk - 1) / hero_atk;
    if (mawang_hp - (mawang_die_turn - 1) * hero_atk <= skill_hp) { // 죽기 전에 피가 P 이하로 떨어지는 일이 있으면 힐
        mawang_die_turn = (mawang_hp + heal + hero_atk - 1) / hero_atk;
    }

    if (hero_die_turn >= mawang_die_turn) { // 용사 먼저 공격
        std::cout << "Victory!";
    }
    else {
        std::cout << "gg";
    }

    return 0;
}