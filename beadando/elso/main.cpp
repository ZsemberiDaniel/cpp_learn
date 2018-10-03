#include <iostream>

using namespace std;

int main() {
    int N, curr, out = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> curr;

        if (curr > 0)
        {
            ++out;
        }
    }

    cout << out << endl;

    return 0;
}