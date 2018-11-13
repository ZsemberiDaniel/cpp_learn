#include <iostream>
#include <cstdlib>
#include <string>

struct Point {
    int x, y;
    double weight;
    std::string name;
};

int* dividers(int x) {
    int count = 0;
    for (int i = 1; i <= x; ++i)
        count += x % i == 0;

    int* o = (int*) malloc(sizeof(int) * (count + 1));
    o[0] = count;
    count = 1;
    for (int i = 1; i <= x; ++i)
        if (x % i == 0)
            o[count++] = i;

    return o;
}

int* subtract(int *a, int N, int *b, int M) {
    int atA = 0, atB = 0, atC = 1;
    int *c = new int[std::max(N, M)];

    while (atA < N && atB < M) {
        if (a[atA] == b[atB]) {
            atA++, atB++;
        } else if (a[atA] < b[atB]) {
            c[atC++] = a[atA++];
        } else {
            atB++;
        }
    }

    while (atA < N) {
        c[atC++] = a[atA++];
    }

    c[0] = atC;
    return c;
}

int* section(int* a, int N, int* b, int M) {
    int atA = 0, atB = 0, atC = 1;
    int *c = new int[std::max(N, M)];

    while (atA < N && atB < M) {
        if (a[atA] == b[atB]) {
            c[atC++] = a[atA];
            atA++, atB++;
        } else if (a[atA] < b[atB]) {
            atA++;
        } else {
            atB++;
        }
    }

    c[0] = atC;
    return c;
}

int* unio(int* a, int N, int* b, int M) {
    int atA = 0, atB = 0, atC = 1;
    int *c = new int[N + M + 1];

    while (atA < N && atB < M) {
        if (a[atA] < b[atB]) {
            c[atC++] = a[atA++];
        } else {
            c[atC++] = b[atB++];
        }
    }

    while (atA < N) {
        c[atC++] = a[atA++];
    }
    while (atB < M) {
        c[atC++] = b[atB++];
    }

    c[0] = atC;
    return c;
}

int main() {
    int *x  = (int*) malloc(128);

    // *(x + 1) == x[1] == 1[x]
    std::cout << (long) x << ": " << *x << std::endl;

    free(x);

    // dividers function
    int* o = dividers(60);
    for (int i = 1; i <= o[0]; ++i) {
        std::cout << o[i] << std::endl;
    }

    free(o);

    // point
    auto t = (Point*) malloc(sizeof(Point) * 100);
    t[2].name = "alma";
    free(t);

    // p = new T  ==  p = (T*) malloc(sizeof(T))      delete(p) == free(p)
    auto p = new Point;

    // union
    int A[] = {1,1,3,7};
    int B[] = {2,3,4};
    int aSize = sizeof(A) / sizeof(int);
    int bSize = sizeof(B) / sizeof(int);
    std::cout << "Union: ";
    int* result = unio(A, aSize, B, bSize);
    for (int i = 1; i < result[0]; ++i) {
        std::cout << result[i] << " ";
    }
    delete result;
    std::cout << std::endl;

    result = section(A, aSize, B, bSize);
    std::cout << "Section: ";
    for (int i = 1; i < result[0]; ++i) {
        std::cout << result[i] << " ";
    }
    delete result;
    std::cout << std::endl;

    result = subtract(A, aSize, B, bSize);
    std::cout << "Difference: ";
    for (int i = 1; i < result[0]; ++i) {
        std::cout << result[i] << " ";
    }
    delete result;
    std::cout << std::endl;

    return 0;
}
