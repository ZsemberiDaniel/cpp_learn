#include <iostream>
#include <vector>

int main() {
    int N;
    std :: cin >> N;

    std::vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> heights[i];
    }

    bool island = false;
    int lastIslandHighest = -1;
    int currHighest = -1;
    int islandCount = 0;

    bool answer = true;
    for (int i = 1; i < N - 1 && answer; ++i) {
        if (!island && heights[i] > 0 && heights[i - 1] == 0) {
            island = true;
            currHighest = -1;
        }

        if (island && heights[i] > currHighest) {
            currHighest = heights[i];
        }

        if (island && heights[i] > 0 && heights[i + 1] == 0) {
            island = false;
            ++islandCount;

            if (lastIslandHighest >= currHighest) {
                answer = false;
            }
            lastIslandHighest = currHighest;
        }
    }

    if (islandCount == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << (answer ? "1" : "0") << std::endl;
    }

    return 0;
}

/**
12
3 2 0 3 4 4 0 2 1 3 0 1

 */