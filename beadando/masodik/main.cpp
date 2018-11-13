#include <iostream>
#include <vector>

int main() {
    int dayCount, curr, next;
    std::vector<int> output;

    std::cin >> dayCount;

    for (int i = 0; i < dayCount; ++i)
    {
        bool ascend = true;

        std::cin >> curr;
        for (int k = 0; k < 6; ++k)
        {
            std::cin >> next;

            if (next <= curr)
            {
                ascend = false;
            }

            curr = next;
        }

        if (ascend)
        {
            output.push_back(i + 1);
        }
    }

    std::cout << output.size() << std::endl;
    for (int i = 0; i < output.size(); ++i)
    {
        std::cout << output[i];
        if (i != output.size() - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

/*
6
5 10 15 20 25 30 35
0 2 0 0 0 0 0
0 0 0 1 0 3 0
0 1 2 3 4 5 6
5 1 0 0 2 1 0
0 0 0 0 0 0 0

*/