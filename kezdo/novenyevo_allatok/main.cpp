#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


struct Creature {
    string name;

    vector<Creature*> eats;

public:
    bool isPlant() {
        return eats.empty();
    }

    bool eatsOnlyPlants() {
        if (isPlant()) return false;

        for (int i = 0; i < eats.size(); ++i) {
            if (!eats[i]->isPlant()) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int N;
    cin >> N;

    unordered_map<string, Creature*> animals;

    string eater, food;
    Creature* eaterCreature;
    Creature* foodCreature;
    for (int i = 0; i < N; ++i) {
        cin >> eater >> food;

        auto search = animals.find(eater);
        if (search == animals.end()) { // NOT found animal
            // make new one for map
            eaterCreature = new Creature();
            eaterCreature->name = eater;

            animals.insert(make_pair(eater, eaterCreature));
        } else { // if there is one in the map then get that one
            eaterCreature = search->second;
        }

        search = animals.find(food);
        if (search == animals.end()) { // NOT found animal
            // make new one for map
            foodCreature = new Creature();
            foodCreature->name = food;

            animals.insert(make_pair(food, foodCreature));
        } else { // if there is one in the map then get that one
            foodCreature = search->second;
        }

        eaterCreature->eats.push_back(foodCreature);
    }

    vector<string> onlyPlants;
    for (auto &crea: animals) {
        if (crea.second->eatsOnlyPlants()) {
            onlyPlants.push_back(crea.second->name);
        }
    }

    cout << onlyPlants.size() << endl;
    for (int i = 0; i < onlyPlants.size(); ++i) {
        cout << onlyPlants[i] << endl;
    }

    return 0;
}

/*
7
roka fogoly
roka feketerigo
fogoly foldigiliszta
csiga fu
feketerigo csiga
foldigiliszta avar
feketerigo gabonamag

 */