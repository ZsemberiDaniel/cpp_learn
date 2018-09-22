#include <iostream>
#include <vector>

using namespace std;

int animalCount, pathCount;

struct Animal {
    int id;
    int pathCounter = 0;
};

int main() {
    // input
    cin >> animalCount >> pathCount;

    // create animals
    vector<Animal> animals;
    //animals.reserve(animalCount);
    for (int i = 0; i <= animalCount; i++)
    {
        Animal a;
        a.id = i;
        animals.push_back(a);
    }

    // paths
    int a, b;
    for (int i = 0; i < pathCount; ++i)
    {
        cin >> a >> b;

        animals[a].pathCounter++;
        animals[b].pathCounter++;
    }

    // 1st and 2nd
    int atPathEndCount = 0;
    int maxPathCount = animals[0].pathCounter;
    int maxPathAt = 1;
    for (int i = 0; i <= animalCount; ++i)
    {
        int pathCount = animals[i].pathCounter;

        if (pathCount == 1)
        {
            ++atPathEndCount;
        }

        if (pathCount > maxPathCount)
        {
            maxPathCount = pathCount;
            maxPathAt = i;
        }
    }

    cout << atPathEndCount << " " << maxPathAt << endl;

    return 0;
}