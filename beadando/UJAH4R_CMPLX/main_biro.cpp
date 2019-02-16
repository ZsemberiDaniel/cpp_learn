#include <iostream>
#include <cmath>
#include <vector>
#include <string>

// type definitions
typedef std::vector<std::vector<float>> Temperatures;
typedef std::vector<int> OutputDays;

// function definitions
void input(int *N, int *M, Temperatures *H);
void solve(int N, int M, Temperatures *H, int *K, OutputDays *T);
bool GoodDay(const int N, Temperatures *H, const int day);
void output(int K, std::vector<int> T);

// input
int N, M;
Temperatures H;

// output
int K;
OutputDays T;

int main() {
    std::ios_base::sync_with_stdio(false);
    input(&N, &M, &H);
    solve(N, M, &H, &K, &T);
    output(K, T);

    return 0;
}

/**
 * Reads the input for the exercise
 * @param N How many cities there are will be stored here.
 * @param M How many days there are will be stored here.
 * @param H All the temeperatures will be stored here in a vector.
 */
void input(int *N, int *M, Temperatures *H) {
    // reading city count
    std::cin >> *N;

    // reading day count
    std::cin >> *M;

    // creating vector for the temperatures
    *H = std::vector< std::vector<float> >(*N, std::vector<float>(*M));

    // reading temperatures
    for (int i = 0; i < *N; i++) {
        for (int k = 0; k < *M; k++) {
            std::cin >> H->at(i).at(k);
        }
    }
}

/**
 * Solves the exercise.
 * @param N Input. How many cities there are.
 * @param M Input. How many days there are.
 * @param H Input. The temperatures of the cities over the days.
 * @param K Output. How many days meet the criteria.
 * @param T Output. Which days meet the criteria
 */
void solve(const int N, const int M, Temperatures *H, int *K, OutputDays *T) {
    // counting how many days meet the given criteria and storing the output
    *K = 0;
    *T = std::vector<int>();

    for (int i = 0; i < M; i++) {
        if (GoodDay(N, H, i)) {
            (*K)++;
            T->push_back(i + 1);
        }
    }
}

/**
 * Calculates whether a day meets the criteria given in the exercise.
 * @param N How many cities there are.
 * @param H The temperatures of all the cities.
 * @param day On which day we want to check the criteria.
 * @return Returns whether at least half the cities meet the criteria.
 */
bool GoodDay(const int N, Temperatures *H, const int day) {
    // count how many cities are above 30 in temperature on the given day
    int counter = 0;
    // how many cities are needed to be over 30 for this day to meet the criteria
    int needed = (int) ceil(N / 2.0);

    for (int i = 0; i < N && counter < needed; i++) {
        counter += H->at(i).at(day) >= 30;
    }

    return counter >= needed;
}

/**
 * Prints the output for the exercise.
 * @param K How many days met the criteria.
 * @param T Which days met the criteria.
 */
void output(int K, std::vector<int> T) {
    std::cout << K;

    for (int i = 0; i < T.size(); i++) {
        std::cout << " " << T[i];
    }
}
