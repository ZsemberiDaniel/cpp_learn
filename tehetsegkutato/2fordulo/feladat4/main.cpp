#include <iostream>
#include <vector>
#include <string>

int maxHeight, resultCount, questionCount;

struct Question {
    int A = 0;
    int B = 0;
    int solution = 0;

    Question() : A(0), B(0), solution(0) {}
};

int* getInts(std::string line, int count) {
    int* ou = new int[count];

    int at = 0;
    for (int i = 0; i < count; i++) {
        int result = 0;
        char ch;
        ch = line[at++];
        while (true) {
            if (ch >= '0' && ch <= '9') break;
            ch = line[at++];
        }
        result = ch-'0';
        while (true) {
            ch = line[at++];
            if (ch < '0' || ch > '9') break;
            result = result*10 + (ch - '0');
        }

        ou[i] = result;
    }

    return ou;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::string line;

    getline(std::cin, line);
    int* a = getInts(line, 3);

    resultCount = a[0];
    maxHeight = a[1];
    questionCount = a[2];
    
    std::vector<Question> qs(questionCount, Question{});

    std::vector<int> firstAt(maxHeight + 1, -1);
    std::vector<int> lastAt(maxHeight + 1, -1);

    getline(std::cin, line);
    int* results = getInts(line, resultCount);

    for (int i = 0; i < resultCount; i++) {
        if (firstAt[results[i]] == -1) {
            firstAt[results[i]] = i;
        }
        lastAt[results[i]] = i;
    }
    for (int i = 0; i < questionCount; i++) {
        getline(std::cin, line);
        a = getInts(line, 2);

        qs[i].A = a[0];
        qs[i].B = a[1];

        if (firstAt[qs[i].A] == lastAt[qs[i].A]) {
            qs[i].solution = -1;
            continue;
        }

        int currc = 0;
        for (int k = firstAt[qs[i].A] + 1; k <= lastAt[qs[i].A]; k++) {
            if (results[k] == qs[i].A) {
                if (qs[i].solution < currc)
                    qs[i].solution = currc;

                currc = 0;
                continue;
            }

            if (results[k] <= qs[i].B)
                currc++;
        }
    }

    for (int i = 0; i < questionCount; i++) {
        std::cout << qs[i].solution << std::endl;
    }

    return 0;
}