#include <iostream>
#include <vector>
#include <algorithm>

// let me find what all now reflects 

int main() {
    // Read input
    int N;
    std::cin >> N;

    std::vector<int> ramuArrangement(N);
    std::vector<int> sonuArrangement(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> ramuArrangement[i];
    }

    for (int i = 0; i < N; ++i) {
        std::cin >> sonuArrangement[i];
    }

    // Mimic Ramu's arrangement
    std::sort(ramuArrangement.begin(), ramuArrangement.end());

    // Maximize overall niceness
    int niceness = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            niceness += std::abs(sonuArrangement[i] - ramuArrangement.back());
            ramuArrangement.pop_back();
        } else {
            niceness += std::abs(sonuArrangement[i] - ramuArrangement.front());
            ramuArrangement.erase(ramuArrangement.begin());
        }
    }

    // Print the maximum achievable niceness
    std::cout << niceness;

    return 0;
}
