#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Day {
    int coldest, warmest;

    int difference() {
        return warmest - coldest;
    }
};

int main()
{
    // variables
    int dayCount;
    vector<Day> days;

    // input
    cin >> dayCount;

    days.reserve(dayCount);

    for (int i = 0; i < dayCount; ++i)
    {
        int coldest, warmest;
        cin >> coldest >> warmest;

        days.push_back(Day{coldest, warmest});
    }

    // 1st
    int freezeCount = 0;
    for (int i = 0; i < dayCount; ++i)
    {
        if (days[i].coldest <= 0)
        {
            ++freezeCount;
        }
    }

    cout << "#" << endl << freezeCount << endl;

    // 2nd
    int highestDiff = days[0].difference();
    int highestDiffAt = 0;
    int diff;
    for (int i = 1; i < dayCount; ++i)
    {
        diff = days[i].difference();

        if (diff > highestDiff)
        {
            highestDiff = diff;
            highestDiffAt = i;
        }
    }

    cout << "#" << endl << highestDiffAt + 1 << endl;

    // 3rd
    int higherThanLastAt = -1;
    for (int i = 1; i < dayCount && higherThanLastAt == -1; i++)
    {
        if (days[i].warmest < days[i - 1].coldest)
        {
            higherThanLastAt = i + 1;
        }
    }

    cout << "#" << endl << higherThanLastAt << endl;

    // 4th
    string freezeAndMelt;
    int freezeAndMeltCount = 0;
    for (int i = 0; i < dayCount; i++)
    {
        if (days[i].coldest <= 0 && days[i].warmest > 0)
        {
            ++freezeAndMeltCount;
            freezeAndMelt += " " + to_string(i + 1);
        }
    }

    cout << "#" << endl << freezeAndMeltCount << freezeAndMelt;

    return 0;
}