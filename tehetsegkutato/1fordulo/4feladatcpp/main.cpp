#include <iostream>
#include <vector>

struct sol {
    int luckyCount = 0;
    int intervalCount = 0;
};

int main() {
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    if (N == 1) {
        std::cin >> N;
        printf("0\n");
        return 0;
    }

    std::vector<int> money(N);
    std::vector<int> lucky(N);

    for (int i = 0; i < N; i++) {
        std::cin >> money[i];

        if (i == 0 || i == N - 1) {
            lucky[i] = 0;
        } else if (i >= 2) {
            // lucky
            if (money[i - 2] < money[i - 1] && money[i - 1] > money[i]) {
                lucky[i - 1] = 1;
            } else if (money[i - 2] > money[i - 1] && money[i - 1] < money[i]) {
                lucky[i - 1] = -1;
            } else {
                lucky[i - 1] = 0;
            }
        }
    }
    // lucky
    if (money[N - 3] < money[N - 2] && money[N - 2] > money[N - 1]) {
        lucky[N - 2] = 1;
    } else if (money[N - 3] > money[N - 2] && money[N - 2] < money[N - 1]) {
        lucky[N - 2] = -1;
    } else {
        lucky[N - 2] = 0;
    }

    int intervalCount = 0;
    for (int i = 0; i < N; i++) {
        int lastLucky = 0;
        for (int k = i; k < N; k++) {
            lastLucky += lucky[k];

            if (lucky[i] == 1) {
                if (i == k) {
                    intervalCount++;
                } else if (lucky[k] == 1 && lastLucky > 0) {
                    intervalCount++;
                }
            }
        }
    }
    std::cout << intervalCount << std::endl;

    /*std::vector<std::vector<sol>> table(N, std::vector<sol>(N));

    // fill diagonal
    for (int i = 1; i < N - 1; i++) {
        if (lucky[i] == 1) {
            table[i][i].luckyCount = 1;
            table[i][i].intervalCount = 1;
        } else if (lucky[i] == -1) {
            table[i][i].luckyCount = -1;
        }
    }

    // fill other
    int colAt;
    for (int i = 1; i < N; i++) {
        for (int k = 0; k < N - i; k++) {
            // row at = k
            // col at = k + i
            colAt = k + i;

            // we calculate the lucky and unlucky count
            table[k][colAt].luckyCount = table[k][colAt - 1].luckyCount + table[colAt][colAt].luckyCount;
            table[k][colAt].intervalCount = table[k][colAt - 1].intervalCount + table[k + 1][colAt].intervalCount
                    - table[k + 1][colAt - 1].intervalCount;

            // we increase the interval count here
            if (lucky[k] == 1 && lucky[colAt] == 1 && table[k][colAt].luckyCount > 0) {
                table[k][colAt].intervalCount++;
            }
        }
    }
    printf("%d\n", table[0][N - 1].intervalCount);*/

    return 0;
}