#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> nums(4);
    int zero_cnt = 0;
    for (int i = 0; i < 4; i++) {
        std::cin >> nums[i];
        
        if (nums[i] == 0) {
            zero_cnt++;
        }
    }

    if (zero_cnt == 1) {
        int sum = nums[0] + nums[1] + nums[2] + nums[3];
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0) {
                std::cout << i + 1 << " " << 10 - sum;
                break;
            }
        }
    }
    else if (zero_cnt == 2) {
        for (int num = 1; num <= 4; num++) {
            bool found = false;
            for (int i = 0; i < 4; i++) {
                if (nums[i] == num) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << num << " ";
            }
        }
    }
    else if (zero_cnt == 0) {
        std::cout << nums[0] << " " << nums[1];
    }

    return 0;
}