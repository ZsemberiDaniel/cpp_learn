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
    int islandCount = 0;

    int left = -1;

    int answer = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (!island && heights[i] > 0 && heights[i - 1] == 0) {
            island = true;

            left = heights[i];
        }

        if (island) {
            if (heights[i] > 0 && heights[i + 1] == 0) {
                island = false;
                ++islandCount;

                if (left > heights[i]) {
                    ++answer;
                }
            }
        }


    }

    if (islandCount == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << (answer > islandCount - answer ? "1" : "0") << std::endl;
    }

    return 0;
}

/**
12
3 2 0 3 4 4 0 2 1 3 0 1

 */