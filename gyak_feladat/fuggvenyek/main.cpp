#include <iostream>
#include <string>

using namespace std;

struct MyLinkedList {
    struct MyLinkedListElem {
        MyLinkedListElem *lastElem;
        MyLinkedListElem *nextElem;
        int value;
    };

private:
    MyLinkedListElem *start;

public:
    int length = 0;

    void add(int i) {
        if (start == nullptr) {
            start = new MyLinkedListElem {nullptr, nullptr, i};
        } else {
            MyLinkedListElem *curr = start;

            while (curr->nextElem != nullptr) {
                curr = curr->nextElem;
            }

            curr->nextElem = new MyLinkedListElem {curr, nullptr, i};
        }

        ++length;
    }

    void removeAt(int at) {
        if (at >= length || at < 0) {
            throw invalid_argument("Index provided was either too low or too high.");
        } else if (at == 0) {
            start = start->nextElem;
        } else {
            int i;
            MyLinkedListElem *curr;
            for (i = 0, curr = start; i < at; ++i, curr = curr->nextElem);

            curr->lastElem->nextElem = curr->nextElem;
        }
    }

    void removeElem(int elem) {
        
    }

    void print() {
        MyLinkedListElem *curr = start;

        cout << curr->value;
        while (curr->nextElem != nullptr) {
            curr = curr->nextElem;

            cout << " " << curr->value;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList list = MyLinkedList {};
    list.add(4);
    list.add(5);
    list.add(9);

    list.removeAt(1);

    list.print();

    return 0;
}