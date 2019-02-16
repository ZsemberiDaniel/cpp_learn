#include <iostream>
#include <algorithm>
#include <vector>


struct Guard{
    int from;
    int till;
};

class Node
{
public:
    Node* next;
    Node* before;
    int data;
};

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    void add(int data);
    void del(Node* node);
};

void LinkedList::del(Node* node) {
    if (node->before != NULL) {
        node->before->next = node->next;
    }
    if (node->next != NULL) {
        node->next->before = node->before;
    }
    this->length--;
}

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

void LinkedList::add(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    if (this->head != NULL)
        this->head->before = node;
    this->head = node;
    this->length++;
}

bool operator<(Guard const & one, Guard const & two) {
    if (one.from != two.from) {
        return one.from < two.from;
    } else if (one.till != two.till) {
        return one.till < two.till;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    int guardCount;
    int dayCount;

    std::cin >> guardCount >> dayCount;

    std::vector<Guard> guards(guardCount);

    int f, t;
    for (int i = 0; i < guardCount; i++) {
        std::cin >> f >> t;
        guards[i] = {f, t};
    }

    std::sort(guards.begin(), guards.end());

    // the current interval
    int currStart = guards[0].from;
    int currStartGuard = 0;
    int currEnd = guards[0].till;
    int currEndGuard = 0;

    // how long the longest interval is
    int longestInterval = 0;
    int longestStartGuard = 0;
    int longestEndGuard = 0;

    for (int i = 1; i < guardCount; i++) {
        // we have a guard that can cover after the current maximum
        if (guards[i].from <= currEnd + 1) {
            currEnd = std::max(currEnd, guards[i].till);
            currEndGuard = i;
        } else {
            // check whether the one before was the longest period
            if (currEnd - currStart + 1 > longestInterval) {
                longestInterval = currEnd - currStart + 1;
                longestStartGuard = currStartGuard;
                longestEndGuard = currEndGuard;
            }

            // assign new interval
            currStartGuard = i;
            currEndGuard = i;
            currStart = guards[i].from;
            currEnd = guards[i].till;
        }
    }

    if (longestInterval < currEnd - currStart + 1) {
        longestInterval = currEnd - currStart + 1;
        longestStartGuard = currStartGuard;
        longestEndGuard = currEndGuard;
    }

    int gcsStart = guards[longestStartGuard].from;
    std::vector<int> gcs(longestInterval, 0);
    for (int i = longestStartGuard; i <= longestEndGuard; i++) {
        for (int k = guards[i].from; k <= guards[i].till; k++) {
            gcs[k - gcsStart]++;
        }
    }

    int max = 0;
    int maxAt = -1;
    for (int i = 0; i < gcs.size(); i++) {
        if (gcs[i] > max) {
            max = gcs[i];
            maxAt = i;
        }
    }

    printf("%d\n%d\n", longestInterval, gcsStart + maxAt);
}

/*
8 100
10 20
60 70
15 18
55 65
20 30
50 60
35 45
5 15

 */

