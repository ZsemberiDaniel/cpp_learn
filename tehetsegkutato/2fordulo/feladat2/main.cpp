#include <iostream>
#include <vector>
#include <algorithm>

int readInt() {
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }

    result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int compCount, highestScore, groupCount, T;
    std::cin >> compCount >> highestScore >> groupCount >> T;
    // compCount = readInt();
    // highestScore = readInt();
    // groupCount = readInt();
    // T = readInt();

    std::vector<bool> score(highestScore + 1, false);
    int minScore = highestScore + 1;

    for (int i = 0; i < compCount; i++) {
        int c;
        std::cin >> c;

        score[c] = true;

        if (c < minScore)
            minScore = c;
    }

    std::vector<int> scoreDiffs(compCount - 1, 0);
    int at = 0;
    int lastScore = minScore;
    for (int i = minScore + 1; i <= highestScore; i++) {
        if (score[i]) {
            scoreDiffs[at++] = i - lastScore;
            lastScore = i;
        }
    }

    std::vector<int> solutions;
    for (int i = 0; i < scoreDiffs.size(); i++) {
        if (scoreDiffs[i] > T)
            solutions.push_back(scoreDiffs[i]);
    }

    std::sort(solutions.begin(), solutions.end());

    if (solutions.size() < groupCount - 1) {
        std::cout << -1 << std::endl;
    } else {
        int solSize = solutions.size();
        for (int i = 1; i <= groupCount; i++) {
            std::cout << solutions[solSize - i] << (i == groupCount ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}