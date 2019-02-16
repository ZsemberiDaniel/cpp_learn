#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>

// type definitions
typedef std::vector<std::vector<float>> Temperatures;
typedef std::vector<int> OutputDays;

// function definitions
void input(int *N, int *M, Temperatures *H);
void solve(int N, int M, Temperatures *H, int *K, OutputDays *T);
bool GoodDay(int N, Temperatures *H, int day);
void output(int K, std::vector<int> T);

// variables
const std::string title = "Sok telepulesen meleg napok";
const std::string cityCountInputText = "Varosok szama: ";
const std::string cityCountError = "A telepulesek szamanak egesz szamnak kell lennie es benne kell lennie az [1;1000] intervallumban.";
const std::string dayCountInputText = "Napok szama: ";
const std::string dayCountError = "A napok szamanak egesz szamnak kell lennie es benne kell lennie az [1;1000] intervallumban.";
const std::string temperatureInputText = "A(z) %d. telepulesen, a(z) %d. napon: ";
const std::string temperatureError = "A homersekletnek -50 es 50 koze eso szamnak kell lennie!";
const std::string outputText = "%d darab ilyen nap van:\n";

// input
int N, M;
Temperatures H;

// output
int K;
OutputDays T;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::clog << title << std::endl << std::endl;
    input(&N, &M, &H);
    solve(N, M, &H, &K, &T);
    output(K, T);

    return 0;
}

/**
 * Reads the input for the exercise
 * @param N How many cities there are will be stored here.
 * @param M How many days there are will be stored here.
 * @param H All the temperatures will be stored here in a vector.
 */
void input(int *N, int *M, Temperatures *H) {
    std::string line;
    bool good_input = true;

    // reading city count
    std::printf(cityCountInputText.c_str());
    std::getline(std::cin, line);
    try {
        *N = std::stoi(line);
    } catch (const std::invalid_argument&) {
        good_input = false;
    }

    while (!good_input || line.find('.') != std::string::npos || *N < 0 || *N > 1000) {
        std::clog << cityCountError << std::endl;
        std::printf(cityCountInputText.c_str());

        good_input = true;
        std::getline(std::cin, line);
        try {
            *N = std::stoi(line);
        } catch (const std::invalid_argument&) {
            good_input = false;
        }
    }

    // reading day count
    std::printf(dayCountInputText.c_str());

    good_input = true;
    std::getline(std::cin, line);
    try {
        *M = std::stoi(line);
    } catch (const std::invalid_argument&) {
        good_input = false;
    }

    while (!good_input || line.find('.') != std::string::npos || *M < 0 || *M > 1000) {
        std::clog << dayCountError << std::endl;
        std::printf(dayCountInputText.c_str());

        good_input = true;
        std::getline(std::cin, line);
        try {
            *M = std::stoi(line);
        } catch (const std::invalid_argument&) {
            good_input = false;
        }
    }

    // creating vector for the temperatures
    *H = std::vector< std::vector<float> >(*N, std::vector<float>(*M));

    // reading temperatures
    for (int i = 0; i < *N; i++) {
        for (int k = 0; k < *M; k++) {
            std::printf(temperatureInputText.c_str(), i + 1, k + 1);

            good_input = true;
            std::getline(std::cin, line);
            try {
                H->at(i).at(k) = std::stoi(line);
            } catch (const std::invalid_argument&) {
                good_input = false;
            }

            while (!good_input || H->at(i).at(k) < -50 || H->at(i).at(k) > 50) {
                std::clog << temperatureError << std::endl;
                std::printf(temperatureInputText.c_str(), i + 1, k + 1);

                good_input = true;
                std::getline(std::cin, line);
                try {
                    H->at(i).at(k) = std::stoi(line);
                } catch (const std::invalid_argument&) {
                    good_input = false;
                }
            }
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
bool GoodDay(int N, Temperatures *H, int day) {
    // count how many cities are above 30 in temperature on the given day
    int counter = 0;
    // how many cities are needed to be over 30 for this day to meet the criteria
    auto needed = (int) ceil(N / 2.0);

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
    std::printf(outputText.c_str(), K);

    for (int i : T) {
        std::cout << " " << i << ".nap" << std::endl;
    }
}
