#include <iostream>
#include <vector>

struct Person {
    unsigned long long int holidays = 0;

    std::vector<int> days;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    std::vector<Person> people(N);
    int count, nmb;
    for (int i = 0; i < N; i++) {
        std::cin >> count;

        people[i].days = std::vector<int>(count);
        for (int k = 0; k < count; k++) {
            std::cin >> nmb;
            unsigned long long int asd = 1UL << (nmb - 1UL);
            people[i].days[k] = nmb - 1;
            people[i].holidays += asd;
        }
    }

    count = 0;
    for (int i = 0; i < N; i++) {
        bool differs = true;
        for (int k = 0; k < N && differs; k++) {
            if (i != k) {
                if (people[i].holidays == people[k].holidays) {
                    differs = false;
                }
                // if the ith number is bigger it will surely differ
                else if (people[i].holidays < people[k].holidays) {
                    unsigned long long int c = people[i].holidays ^ people[k].holidays;
                    bool d = false;

                    for (int j = 0; j < people[i].days.size() && !d; j++) {
                        if (((c >> people[i].days[j]) & 1U) == 1) {
                            d = true;
                        }
                    }

                    differs = d;
                }
            }
        }

        if (differs) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}