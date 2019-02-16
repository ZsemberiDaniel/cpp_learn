#include <iostream>
#include <vector>
#include <queue>

int N;
int startX, startY;
int endX, endY;

struct Node {
    int x;
    int y;
    int g = 0;
    Node *parent = nullptr;
    bool empty = true;
    bool been = false;
};

struct op {
    bool operator()(const Node* a, const Node* b) {
        return a->g > b->g;
    }
};

int main() {
    std::cin >> N;

    std::vector<std::vector<Node*>> nodes(N, std::vector<Node*>(N, nullptr));

    getchar();
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            nodes[k][i] = (Node*) malloc(sizeof(Node));
            nodes[k][i]->x = k;
            nodes[k][i]->y = i;

            nodes[k][i]->empty = getchar() == '-';
        }
        getchar();
    }

    std::cin >> endY >> endX >> startY >> startX;
    startX--, startY--, endX--, endY--;

    std::vector<Node*> open_vector;
    open_vector.push_back((nodes[startX][startY]));

    Node* possibleSuccessors[] = {nullptr, nullptr, nullptr, nullptr};
    while (!open_vector.empty()) {
        std::pop_heap(open_vector.begin(), open_vector.end(), op());
        Node* current_node = open_vector.back();
        open_vector.pop_back();

        nodes[current_node->x][current_node->y]->been = true;

        // left
        if (current_node->x > 0) {
            // top
            if (current_node->y > 0 && nodes[current_node->x - 1][current_node->y - 1]->empty) {
                possibleSuccessors[0] = nodes[current_node->x - 1][current_node->y - 1];
            } else {
                possibleSuccessors[0] = nullptr;
            }

            // bottom
            if (current_node->y < N - 1 && nodes[current_node->x - 1][current_node->y + 1]->empty) {
                possibleSuccessors[1] = nodes[current_node->x - 1][current_node->y + 1];
            } else {
                possibleSuccessors[1] = nullptr;
            }
        }

        // right
        if (current_node->x < N - 1) {
            // top
            if (current_node->y > 0 && nodes[current_node->x + 1][current_node->y - 1]->empty) {
                possibleSuccessors[2] = nodes[current_node->x + 1][current_node->y - 1];
            } else {
                possibleSuccessors[2] = nullptr;
            }

            // bottom
            if (current_node->y < N - 1 && nodes[current_node->x + 1][current_node->y + 1]->empty) {
                possibleSuccessors[3] = nodes[current_node->x + 1][current_node->y + 1];
            } else {
                possibleSuccessors[3] = nullptr;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (possibleSuccessors[i] == nullptr || nodes[possibleSuccessors[i]->x][possibleSuccessors[i]->y]->been)
                continue;

            int k = 0;
            for (k = 0; k < open_vector.size() && open_vector[k] != possibleSuccessors[i]; k++);

            int newG;
            if (current_node->parent != nullptr) {
                int lastMoveX = current_node->parent->x - current_node->x;
                int lastMoveY = current_node->parent->y - current_node->y;

                int currMoveX = current_node->x - possibleSuccessors[i]->x;
                int currMoveY = current_node->y - possibleSuccessors[i]->y;

                if (lastMoveX == currMoveX && lastMoveY == currMoveY) {
                    newG = current_node->g;
                } else {
                    newG = current_node->g + 1;
                }
            } else {
                newG  = current_node->g;
            }

            // neighbour not in open list
            if (k == open_vector.size()) {
                possibleSuccessors[i]->g = newG;
                possibleSuccessors[i]->parent = current_node;

                open_vector.push_back(possibleSuccessors[i]);
                std::push_heap(open_vector.begin(), open_vector.end(), op());
                continue;
            }

            // found in open list with lower g
            if (open_vector[k]->g <= newG) {
                continue;
            } else {
                possibleSuccessors[i]->g = newG;
                possibleSuccessors[i]->parent = current_node;

                std::make_heap(open_vector.begin(), open_vector.end());
            }
        }
    }

    if (!nodes[endX][endY]->been) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << nodes[endX][endY]->g + 1 << std::endl;
    }

    return 0;
}