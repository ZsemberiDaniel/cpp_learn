#include <vector>
#include <stdlib.h>
#include <random>
#include <cstdio>
#include <iostream>

int arraySize = 2000;

int compareCount = 0;
int moveCount = 0;

void beszuroRendezes(std::vector<int> *vec) {
    for (int i = 1; i < vec->size(); i++) {
        int elemAtI = (*vec)[i];

        int k;
        for (k = i - 1; k >= 0 && (compareCount++, (*vec)[k] > elemAtI); k--) {
            (*vec)[k + 1] = (*vec)[k];
            moveCount++;
        }

        int h = (*vec)[k + 1];
        (*vec)[k + 1] = (*vec)[i];
        (*vec)[i] = h;
        moveCount++;
    }
}

void javitottBuborekRendezes(std::vector<int> *vec) {
    int lastSwapped = vec->size();

    for (int i = 0; i < lastSwapped; i++) {
        for (int k = 1; k < vec->size() - i; k++) {
            compareCount++;
            if ((*vec)[k] < (*vec)[k - 1]) {
                lastSwapped = k;

                int h = (*vec)[k];
                (*vec)[k] = (*vec)[k - 1];
                (*vec)[k - 1] = h;
                moveCount += 3;
            }
        }
    }
}

void buborekRendezes(std::vector<int> *vec) {
    for (int i = 0; i < vec->size(); i++) {
        for (int k = 0; k < vec->size() - i; k++) {
            compareCount++;

            if ((*vec)[k] < (*vec)[k - 1]) {
                int h = (*vec)[k];
                (*vec)[k] = (*vec)[k - 1];
                (*vec)[k - 1] = h;
                moveCount += 3;
            }
        }
    }
}

void minimumKivalasztos(std::vector<int> *vec) {
    for (int i = 0; i < vec->size(); i++) {
        int smallestAt = i + 1;
        moveCount += 1;

        for (int k = i + 2; k < vec->size(); k++) {
            compareCount++;
            if ((*vec)[k] < (*vec)[smallestAt]) {
                smallestAt = k;
                moveCount += 2;
            }
        }

        int h = (*vec)[smallestAt];
        (*vec)[smallestAt] = (*vec)[i];
        (*vec)[i] = h;
        moveCount += 3;
    }
}

void cseresRendezes(std::vector<int> *vec) {
    for (int i = 0; i < vec->size(); i++) {
        for (int k = i + 1; k < vec->size(); k++) {
            compareCount++;

            if ((*vec)[i] > (*vec)[k]) {
                int h = (*vec)[k];
                (*vec)[k] = (*vec)[i];
                (*vec)[i] = h;

                moveCount += 3;
            }
        }
    }
}

void reset() {
    compareCount = 0;
    moveCount = 0;
}

void printResult(std::vector<int> *vec) {
    for (int i = 0; i < vec->size(); i++) {
        std::cout << i << ": " << (*vec)[i] << " | ";
    }
    std::cout << std::endl;

    std::cout << "Compare count " << compareCount << std::endl;
    std::cout << "Move count " << moveCount << std::endl;
}

void fillVector(std::vector<int> *vec) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 300);

    for (int i = 0; i < arraySize; i++) {
        (*vec)[i] = distribution(generator);
    }
}

int main() {
    std::vector<int> vec(arraySize);

    std::cout << "Minimum kivalasztas:" << std::endl;
    fillVector(&vec);
    minimumKivalasztos(&vec);
    printResult(&vec);

    reset();
    std::cout << std::endl << "Cseres:" << std::endl;
    fillVector(&vec);
    cseresRendezes(&vec);
    printResult(&vec);

    reset();
    std::cout << std::endl << "Buborek:" << std::endl;
    fillVector(&vec);
    buborekRendezes(&vec);
    printResult(&vec);

    reset();
    std::cout << std::endl << "Javitott buborek:" << std::endl;
    fillVector(&vec);
    javitottBuborekRendezes(&vec);
    printResult(&vec);

    reset();
    std::cout << std::endl << "Beszuro:" << std::endl;
    fillVector(&vec);
    beszuroRendezes(&vec);
    printResult(&vec);

    return 0;
}
