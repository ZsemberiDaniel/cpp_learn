#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> costs(N);

    for (int i = 0; i < N; i++) {
        std::cin >> costs[i];
    }

    std::vector<int> solution1(N, 0);
    std::vector<int> solution2(N, 0);

    std::vector<int> countsBegin(101, 0);
    std::vector<int> countsEnd(101, 0);

    for (int i = 0, endI = N - 1; i < N; i++, endI--) {
        // _____ FROM BEGINNING _______
        countsBegin[costs[i]]++;

        // _____ FROM END _____
        countsEnd[costs[endI]]++;

        int countBegin = 0;
        int countEnd = 0;
        for (int k = 1; k <= 100; k++) {
            if (k < costs[i]) {
                countBegin += countsBegin[k];
            }

            if (k > costs[endI]) {
                countEnd += countsEnd[k];
            }
        }

        solution1[i] = countBegin;
        solution2[endI] = countEnd;
    }

    for (int i = 0; i < N; i++) {
        std::cout << solution1[i] << " " << solution2[i] << std::endl;
    }

    return 0;
}
