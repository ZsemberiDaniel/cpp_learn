#include <iostream>

using namespace std;

int main() {
    int N, last = 0, curr, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> curr;

        if (curr > last)
        {
            count++;
        }

        last = curr;
    }

    cout << count;

    return 0;
}