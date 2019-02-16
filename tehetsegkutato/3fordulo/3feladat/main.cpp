#include <iostream>
#include <vector>
#include <algorithm>

struct Earthquake {
    int start;
    int end;
};

bool comp(Earthquake& e1, Earthquake& e2) {
    return (e1.start == e2.start ? e1.end < e2.end : e1.start < e2.start);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int islandCount, minCount;
    std::cin >> islandCount >> minCount;

    std::vector<Earthquake> quakes(100000);

    int qCount = 0, currQCount;
    for (int i = 0; i < islandCount; i++) {
        std::cin >> currQCount;

        for (int k = qCount; k < qCount + currQCount; k++) {
            std::cin >> quakes[k].start >> quakes[k].end;
        }

        qCount += currQCount;
    }

    std::sort(quakes.begin(), quakes.begin() + qCount, comp);

    int maxDelta = std::max(quakes[0].start - 1, minCount - quakes[qCount - 1].end);
    int eStart = quakes[0].start;
    int eEnd = quakes[0].end;
    for (int i = 1; i < qCount; i++) {
        // inside curr quake interval
        if (quakes[i].start >= eStart && quakes[i].start <= eEnd) {
            eEnd = std::max(eEnd, quakes[i].end);
        } else {
            int currDelta = quakes[i].start - eEnd - 1;

            if (currDelta > maxDelta) {
                maxDelta = currDelta;
            }

            eStart = quakes[i].start;
            eEnd = quakes[i].end;
        }
    }

    std::cout << maxDelta << std::endl;

    return 0;
}