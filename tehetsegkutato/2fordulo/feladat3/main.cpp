#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    std::vector<bool> swapped(N + 1, false);
    std::vector<bool> next(N + 1, false);
    std::vector<bool> prev(N + 1, false);
    int first1 = -1;
    int last1 = -1;

    int curr;
    int index = 0;
    for (index = 1; index <= N; index++) {
        std::cin >> curr;

        if (curr != index) {
            if (first1 == -1) first1 = index;
            last1 = index;

            std::cin >> curr;

            swapped[index] = true;
            next[index] = true;
            prev[index] = true;
            index++;
        }
    }

    // the first element of order
    if (first1 == -1) {
        for (int i = 1; i < N; i += 2) {
            prev[i] = true;
        }
        next[N - 1] = true;

        for (int i = 1; i <= N; i++) {
            if (prev[i]) {
                std::cout << i + 1 << " " << i << (i + 1 == N ? "" : " ");
                i++;
            } else {
                std::cout << i << (i == N ? "" : " ");
            }
        }
        std::cout << std::endl;

        for (int i = 1; i <= N; i++) {
            if (next[i]) {
                std::cout << i + 1 << " " << i << (i + 1 == N ? "" : " ");
                i++;
            } else {
                std::cout << i << (i == N ? "" : " ");
            }
        }
        std::cout << std::endl;

        return 0;
    }

    int kindex;
    for (kindex = N - 1; kindex > 1; kindex--) {
        if (kindex == first1) {
            // we have a block that spans from the end -> we need to move the first 1 left
            if (swapped[N - 1]) {
                next[kindex - 1] = true;

                for (int i = kindex; i <= N; i++)
                    next[i] = false;
            } else {
                // we need to introduce a new 1
                next[N - 1] = true;
                break;
            }
            break;
        }

        if (swapped[kindex] && !swapped[kindex - 2]) {
            next[kindex - 1] = true;

            for (int i = kindex; i <= N; i++)
                next[i] = false;

            break;
        }
    }

    // the last element of order
    if (kindex == 1) {
        if (prev[N-1]) prev[N - 1] = false;
        else {
            prev[N - 2] = false;
            prev[N - 1] = true;
        }

        for (int i = 1; i <= N; i++) {
            if (prev[i]) {
                std::cout << i + 1 << " " << i << (i + 1 == N ? "" : " ");
                i++;
            } else {
                std::cout << i << (i == N ? "" : " ");
            }
        }
        std::cout << std::endl;

        for (int i = 1; i <= N; i++) {
            std::cout << i << (i == N ? "" : " ");
        }
        std::cout << std::endl;

        return 0;
    }

    for (int i = N - 1; i > 1; i--) {
        if (i == N - 1 && swapped[i]) {
            prev[i] = false;
            break;
        }

        if (swapped[i] && !swapped[i + 2]) {
            swapped[i] = false;

            for (int k = i + 1; k < N; k += 2) {
                swapped[k] = true;
                swapped[k + 1] = false;
            }
        }
    }


    for (int i = 1; i <= N; i++) {
        if (prev[i]) {
            std::cout << i + 1 << " " << i << (i + 1 == N ? "" : " ");
            i++;
        } else {
            std::cout << i << (i == N ? "" : " ");
        }
    }
    std::cout << std::endl;

    for (int i = 1; i <= N; i++) {
        if (next[i]) {
            std::cout << i + 1 << " " << i << (i + 1 == N ? "" : " ");
            i++;
        } else {
            std::cout << i << (i == N ? "" : " ");
        }
    }
    std::cout << std::endl;

    return 0;
}