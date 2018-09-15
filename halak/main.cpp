#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int fishCount, startTime, endTime;
    cin >> fishCount;

    // input
    vector< tuple<int, int> > forbidden;
    // output
    vector< tuple<int, int> > forbiddenOut;

    // read everything
    for (int i = 0; i < fishCount; ++i)
    {
        cin >> startTime >> endTime;

        forbidden.push_back(make_tuple(startTime, endTime));
    }

    sort(forbidden.begin(), forbidden.end());

    // start the forbidden time at the first tuple
    tuple<int, int> currForbidden = make_tuple(get<0>(forbidden[0]), get<1>(forbidden[0]));
    // print if at start of year it is not forbidden
    if (get<0>(currForbidden) > 1)
    {
        forbiddenOut.push_back(make_tuple(1, get<0>(currForbidden) - 1));
    }

    for (int i = 1; i < fishCount; i++)
    {
        tie(startTime, endTime) = forbidden[i];
        // if the current forbidden timespan's start is in the forbidden timespan
        if (get<0>(currForbidden) <= startTime && startTime <= get<1>(currForbidden) + 1)
        {
            // expand the end of the forbidden timespan if needed
            get<1>(currForbidden) = max(get<1>(currForbidden), endTime);
        }
        else // the current timespan's start is outside of forbidden timespan
        {
            forbiddenOut.push_back(make_tuple(get<1>(currForbidden) + 1, startTime - 1));

            currForbidden = make_tuple(startTime, endTime);
        }
    }

    // end of year
    if (get<1>(currForbidden) < 365)
    {
        forbiddenOut.push_back(make_tuple(get<1>(currForbidden) + 1, 365));
    }

    cout << forbiddenOut.size() << endl;
    for (vector< tuple<int, int>>::iterator i = forbiddenOut.begin(); i != forbiddenOut.end(); i++)
    {
        cout << get<0>(*i) << " " << get<1>(*i) << endl;
    }

    return 0;
}
