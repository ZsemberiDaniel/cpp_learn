#include <iostream>
#include <vector>
#include <cmath>

int N, M;

int minPoint = 9999999999;

struct Team{
    std::vector<bool> defeated;
    int point;

    int with;
};

void solve(std::vector<Team>& teams, std::vector<int>& been, int pointSum = 0, int nextTeam = 0) {
    if (nextTeam == N) {
        if (pointSum < minPoint) {
            for (int i = 0; i < N; i++) {
                teams[i].with = been[i];
            }

            minPoint = pointSum;
        }

        return;
    }

    if (been[nextTeam] != -1) {
        solve(teams, been, pointSum, nextTeam + 1);
    } else {
        for (int i = 0; i < N; i++) {
            // already assigned or has already played
            if (i == nextTeam || been[i] != -1 || teams[nextTeam].defeated[i] || teams[i].defeated[nextTeam]) continue;

            been[i] = nextTeam;
            been[nextTeam] = i;

            pointSum += std::abs(teams[i].point - teams[nextTeam].point);

            solve(teams, been, pointSum, nextTeam + 1);

            been[i] = -1;
            been[nextTeam] = -1;

            pointSum -= std::abs(teams[i].point - teams[nextTeam].point);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    std::vector<Team> teams(N, { std::vector<bool>(N, false), 0, -1 });
    int temp;

    for (int i = 0; i < N; i++) {
        std::cin >> teams[i].point;

        for (int k = 0; k < teams[i].point; k++) {
            std::cin >> temp;

            teams[i].defeated[temp - 1] = true;
        }
    }

    std::vector<int> been(N, -1);
    solve(teams, been);

    //std::cout << minPoint << std::endl;
    for (int i = 0; i < N; i++) {
        if (teams[i].with > i) {
            std::cout << (i + 1) << " " << (teams[i].with + 1) << std::endl;
        }
    }

    return 0;
}