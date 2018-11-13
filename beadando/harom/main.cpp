#include <iostream>
#include <vector>

int main()
{

    int N;
    std::cin >> N;
    std::vector<int> out;

    int amount, price;
    int highestAmountSoFar = -1;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> amount >> price;
        if (i == 0)
        {
            highestAmountSoFar = amount;
        }
        else if (amount > highestAmountSoFar)
        {
            highestAmountSoFar = amount;
            out.push_back(i + 1);
        }
    }

    std::cout << out.size();
    for (int i : out) {
        std::cout << " " << i;
    }
    std::cout << std::endl;

    return 0;
}

/*
6
500 1500
1900 2000
2000 1500
200 3800
300 1000
2100 3000

 */