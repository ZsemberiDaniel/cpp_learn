#include <iostream>

using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;

    int O, P, T, m;
    for (int i = 0 ; i< N; ++i) {
        cin >> O >> P >> T >> m;

        if (T == -2) {
            sum += m;
        }
    }

    cout << sum << endl;

    return 0;
}

/*
7
11 10 1 12345
11 50 -2 10000
12 10 -1 12345
23 10 1 24680
23 11 -2 5000
23 15 1 13579
23 20 1 98765

 */