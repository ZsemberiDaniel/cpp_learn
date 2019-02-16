#include <iostream>
#include <vector>

struct Person {
    int month;
    int day;
    int dayAt;
};

int main() {
    std::ios::sync_with_stdio(false);
    // std::cin.tie(NULL);
    //                31  28  31  30   31   30   31   31   30   31   30   31
    int days[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int N;
    scanf("%d", &N);

    // this is where the sorting will happen. We put each birthday into this array, in the dayCountth index
    // where dayCount is on which day the birthday is
    std::vector<int> sorted(366, -1);
    // how many birthdays on this day
    std::vector<int> sortedCount(366, 0);

    std::vector<Person> d(N);

    int month, day;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &month, &day);
        //      month  day   dayCount
        d[i] = {month, day, days[month] + day};

        // counting and sorting
        sortedCount[d[i].dayAt]++;
        if (sorted[d[i].dayAt] == -1) {
            sorted[d[i].dayAt] = i;
        }
    }

    // we calculate the middle one by adding up the counts from sortedCount
    int middle = N / 2;
    int countSoFar = 0;
    for (int i = 0; i < 366; ++i) {
        if (sorted[i] != -1) {
            countSoFar += sortedCount[i];

            if (countSoFar > middle) {
                printf("%d %d\n%d\n", d[sorted[i]].month, d[sorted[i]].day, sorted[i] + 1);
                break;
            }
        }
    }

    return 0;
}