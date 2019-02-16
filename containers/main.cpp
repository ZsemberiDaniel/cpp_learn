#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int max_rec(const std::vector<int>& vec, int n) {
    if (n == 1)
        return vec[0];
    else
        return std::max(vec[n - 1], max_rec(vec, n - 1));
}

template<typename Iter>
auto max(Iter e, Iter u) {
    auto ans = *e;

    for (auto it = e + 1; it != u; it++) {
        ans = max(*it, ans);
    }

    return ans;
}

template<int X>
struct Fact {
    static constexpr int result = Fact<X - 1>::result * X;
};

template<>
struct Fact<0> {
    static constexpr int result = 1;
};

int main() {
    std::list<int> linked_list;

    for (auto it = linked_list.begin(); it != linked_list.end(); it++);

    std::cout << Fact<15>::result << std::endl;

    return 0;
}