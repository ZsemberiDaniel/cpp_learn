#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Person {
    int age;
    int salary;
};

int main() {
    set<int> ages;

    int N;
    cin >> N;

    Person people[100];

    int oldest = -1;
    int oldestAge = -200;

    int bCount = 0;

    vector<int> d;

    for (int i = 0; i < N; ++i)
    {
        cin >> people[i].age >> people[i].salary;

        ages.insert(people[i].age);

        if (people[i].age > oldestAge)
        {
            oldest = i + 1;
            oldestAge = people[i].age;
        }

        if (people[i].age > 40 && people[i].salary < 200000)
        {
            ++bCount;
        }

        if (people[i].age < 30)
        {
            d.push_back(i + 1);
        }
    }

    cout << oldest << endl;
    cout << bCount << endl;
    cout << ages.size() << endl;
    cout << d.size();
    for (int i = 0; i < d.size(); ++i)
    {
        cout << " " << d[i];
    }
    cout << endl;


    return 0;
}

/*
6
42 150000
33 100000
25 600000
66 80000
25 200000
42 800000

 */