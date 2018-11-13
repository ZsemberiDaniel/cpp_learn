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
    int islandStart = -1;
    int currHighest = -1;
    int currLowest = 10000;
    int levelDifference = 10000;
    int islandCount = 0;

    int solutionStart, solutionEnd;
    for (int i = 1; i < N - 1; ++i) {
        if (!island && heights[i] > 0 && heights[i - 1] == 0) {
            island = true;
            islandStart = i;
            currHighest = -1;
            currLowest = 10000;
        }

        if (island) {
            if (heights[i] > currHighest) {
                currHighest = heights[i];
            }

            if (heights[i] < currLowest) {
                currLowest = heights[i];
            }

            if (heights[i] > 0 && heights[i + 1] == 0) {
                island = false;
                ++islandCount;

                if (levelDifference > currHighest - currLowest) {
                    levelDifference = currHighest - currLowest;
                    solutionStart = islandStart + 1;
                    solutionEnd = i + 1;
                }
            }
        }


    }

    if (islandCount == 0) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << solutionStart << " " << solutionEnd << std::endl;
    }

    return 0;
}

/**
12
3 2 0 3 4 4 0 2 1 3 0 1

 */