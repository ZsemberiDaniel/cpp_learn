#include <iostream>
#include <vector>

struct Out {
    int max;
    int at;
    int count;
};

int main() {
    int N, M, K, curr;
    std::cin >> N >> M >> K;

    std::vector<Out> maxPerDay(M, {-1, -1, 0});
    for (int i = 0; i < N; ++i) { // go through cities
        for (int k = 0; k < M; ++k) { // go through days
            std::cin >> curr;

            // found new max
            if (maxPerDay[k].max < curr) {
                maxPerDay[k] = {curr, i, 1};
            } else if (maxPerDay[k].max == curr) { // max found again
                ++maxPerDay[k].count;
            }
        }
    }

    // add up where the maxes are
    std::vector<int> perCityCount(N, 0);
    for (int i = 0; i < M; ++i) {
        if (maxPerDay[i].count == 1) {
            ++perCityCount[maxPerDay[i].at];
        }
    }

    // which is the highest among maxes
    int max = -1;
    int sol = -1;
    for (int i = 0; i < N; ++i) {
        if (perCityCount[i] != 0 && perCityCount[i] > max) {
            max = perCityCount[i];
            sol = i;
        }
    }

    if (sol != -1) {
        std::cout << sol + 1 << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}

// amikor nincs olyan nap amin van legmelegebb varos akkor mi tortenik?
// azaz egyik varosnal sincs olyan, hogy valamelyik napon az osszes tobbinel melegebb

/*
5 6 30
20 22 22 24 26 21
31 31 31 29 31 20
20 30 35 30 30 21
32 29 34 32 29 30
33 20 20 33 33 30

 */