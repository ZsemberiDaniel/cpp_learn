#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;

    bool isWall = false;
    bool checked = false;

    int cost = -1;
};

class PointCompare {
public:
    bool operator() (Point p1, Point p2) {
        return p1.cost < p2.cost;
    }
};

int height, width, wallTime;
Point* startTile;
Point* endTile;

Point isWall[500][500];

int main() {
    cin >> height >> width >> wallTime;

    int c;
    for (int i = 0; i < height; ++i) {
        for (int  k = 0; k < width; ++k) {
            c = getchar();

            switch (c) {
                case '*':
                    isWall[k][i] = Point {k, i, true};
                    break;
                case 'K':
                    startTile = &isWall[k][i];
                    break;
                case 'C':
                    endTile = &isWall[k][i];
                    break;
                default:
                    isWall[k][i] = Point {k, i};
                    break;
            }
        }
    }

    // start tile
    startTile->cost = 0;

    // go through every point
    priority_queue<Point*, vector<Point*>, PointCompare> tiles;
    tiles.push(startTile);

    while (!tiles.empty()) {
        Point* currTile = tiles.top();
        tiles.pop();

        // up
        if (currTile) {

        }
    }

    return 0;
}

/*
4 6 5
******
*K *
******
* C**

 */