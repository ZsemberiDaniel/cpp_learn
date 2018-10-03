#include <iostream>
#include <vector>

using namespace std;

int pathLength, lampAt, carCount, greenFor, redFor;
int currTime = 1;

struct Car {
    int startTime;
    int pathAt = -1;

    int endAt = -1;

    bool isDone() {
        return pathAt >= pathLength;
    }

    void advance() {
        ++pathAt;

        // get car out of the paths of others if done
        if (pathAt == pathLength - 1) {
            endAt = currTime + 1;
            pathAt = pathLength + 5;
        }
    }
};

bool isRedAtTime(int at) {
    return (at - 1) % (greenFor + redFor) >= greenFor;
}

int main() {
    // input
    int startTime;
    cin >> lampAt >> carCount;
    pathLength = lampAt * 2 + 1;
    vector<Car> cars;

    for (int i = 0; i < carCount; ++i) {
        cin >> startTime;

        Car c;
        c.startTime = startTime;
        cars.push_back(c);
    }

    cin >> greenFor >> redFor;
    greenFor -= redFor;

    // simulate
    // while last car is not done
    currTime = cars[0].startTime;
    while (!cars[carCount - 1].isDone()) {
        for (int i = 0; i < carCount; i++) {
                // car started           and  is not done
            if (cars[i].startTime <= currTime && !cars[i].isDone() &&
                // car can advance to the next tile
                ((i == 0) || (cars[i - 1].pathAt - cars[i].pathAt > 2)) &&
                // the next tile is not a red lamp
                !(cars[i].pathAt == lampAt - 1 && isRedAtTime(currTime))) {
                cars[i].advance();
            }
        }

        currTime++;
    }

    for (int i = 0; i < carCount; ++i) {
        cout << cars[i].endAt << endl;
    }

    return 0;
}

/*
4 3
3 6 9
7 3

 */