#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string name;
    int age, weight;
    while (true) {
        std::cin >> name >> age >> weight;

        if (name == "#") {
            break;
        }

        std::cout << name << " ";

        if (age > 17 || weight >= 80) {
            std::cout << "Senior\n";
        }
        else {
            std::cout << "Junior\n";
        }
    }

    return 0;
}