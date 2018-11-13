#include <iostream>
#include <vector>

using namespace std;

bool isPossible(long balloonCount, vector<long>* balloonWorth, vector<long>* balloonNeeded, long candyPerDay)
{
    long sum = 0;
    for (int i = 0; i < balloonWorth->size(); ++i)
    {
        // we calculate how many balloons we need to give her each day
        // if we give her candyPerDay candy each day
        sum += max(balloonNeeded->at(i) - (candyPerDay / balloonWorth->at(i)), 0L);
    }

    return balloonCount >= sum;
}

int main() {
    ios::sync_with_stdio(false);

    long dayCount, balloonCount;

    cin >> dayCount >> balloonCount;
    vector<long> balloonWant(dayCount);
    vector<long> balloonWorth(dayCount);
    for (int i = 0; i < dayCount; ++i)
    {
        cin >> balloonWant[i];
    }
    for (int i = 0; i < dayCount; ++i)
    {
        cin >> balloonWorth[i];
    }

    long min = 0, max = 1000000000000000000;

    // subtracting 2 because the intervals are open and not closed
    // at the end of the search it looks like
    // 13 16 20
    // 13 14 16
    // 14 15 16 // this way it stops here
    // 14 14 15 // otherwise it would get stuck
    while (min < max - 2)
    {
        long mid = (min + max) / 2;
        // cout << min << " " << mid << " " << max << endl;

        if (isPossible(balloonCount, &balloonWorth, &balloonWant, mid))
        {
            max = mid;
        }
        else
        {
            min = mid;
        }
    }

    cout << (min + max) / 2 << endl;

    return 0;
}