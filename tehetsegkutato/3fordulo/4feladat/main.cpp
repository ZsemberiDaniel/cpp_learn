#include <iostream>
#include <vector>
#define gc getchar_unlocked

void scanint(int &x)
{
    int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int N, K, circumference;

inline int toLeft(int i) {
    return i == 0 ? N - 1 : i - 1;
}

inline int toRight(int i) {
    return (i + 1) % N;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    scanint(N);
    scanint(K);
    scanint(circumference);

    std::vector<int> DSum(N + 1, 0);
    std::vector<int> D(N, 0);

    for (int i = 1; i < N; i++) {
        scanint(DSum[i]);
    }
    DSum[N] = circumference;
    D[0] = DSum[1];
    for (int i = N - 1; i > 0; i--) D[i] = DSum[i + 1] - DSum[i];

    if (N == 3) {
        printf("2 3\n3 1\n1 2\n");
        return 0;
    }

    int left = N - K, right = 0;
    int leftDist = circumference - DSum[left], rightDist = 0;

    for (int i = 0; i < N; i++) {
        // move the interval
        if (right == i - 1) {
            leftDist += -D[left] + D[i - 1];
            rightDist = 0;

            left = toLeft(left);
            right = i;
        } else {
            leftDist += D[i - 1];
            rightDist -= D[i - 1];
        }

        while (leftDist > rightDist + D[right]) {
            leftDist -= D[left];
            rightDist += D[right];

            left = toRight(left);
            right = toRight(right);
        }

        printf("%d %d\n", (left == i ? toRight(left) + 1: left + 1), (right == i ? toLeft(right) + 1 : right + 1));
    }

    return 0;
}