#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    int country, id, score;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    
    std::vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        std::cin >> students[i].country >> students[i].id >> students[i].score;
    }

    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a.score > b.score;
    });

    std::vector<int> medals(N);
    int cnt = 0;
    for (int i = 0; i < N && cnt < 3; i++) {
        if (medals[students[i].country] < 2) {
            medals[students[i].country]++;
            cnt++;
            std::cout << students[i].country << " " << students[i].id << "\n";
        }
    }

    return 0;
}