using System;
using System.Collections.Generic;

class Program {
    struct sol {
        public int luckyCount;
        public int intervalCount;
    }

    static void Main(string[] args) {
        //std::ios::sync_with_stdio(false);

        int N = int.Parse(Console.ReadLine());

        if (N == 1) {
            Console.ReadLine();
            Console.WriteLine("0");
            return;
        }

        int[] money = new int[N];
        int[] lucky = new int[N]; 

        for (int i = 0; i < N; i++) {
            money[i] = int.Parse(Console.ReadLine());

            if (i == 0 || i == N - 1) {
                lucky[i] = 0;
            } else if (i >= 2) {
                // lucky
                if (money[i - 2] < money[i - 1] && money[i - 1] > money[i]) {
                    lucky[i - 1] = 1;
                } else if (money[i - 2] > money[i - 1] && money[i - 1] < money[i]) {
                    lucky[i - 1] = -1;
                } else {
                    lucky[i - 1] = 0;
                }
            }
        }
        // lucky
        if (money[N - 3] < money[N - 2] && money[N - 2] > money[N - 1]) {
            lucky[N - 2] = 1;
        } else if (money[N - 3] > money[N - 2] && money[N - 2] < money[N - 1]) {
            lucky[N - 2] = -1;
        } else {
            lucky[N - 2] = 0;
        }

        sol[,] table = new sol[N, N];

        // fill diagonal
        for (int i = 1; i < N - 1; i++) {
            if (lucky[i] == 1) {
                table[i, i].luckyCount = 1;
                table[i, i].intervalCount = 1;
            } else if (lucky[i] == -1) {
                table[i, i].luckyCount = -1;
            }
        }

        // fill other
        int colAt;
        for (int i = 1; i < N; i++) {
            for (int k = 0; k < N - i; k++) {
                // row at = k
                // col at = k + i
                colAt = k + i;

                // we calculate the lucky and unlucky count
                table[k, colAt].luckyCount = table[k, colAt - 1].luckyCount + table[colAt, colAt].luckyCount;
                table[k, colAt].intervalCount = table[k, colAt - 1].intervalCount + table[k + 1, colAt].intervalCount
                        - table[k + 1, colAt - 1].intervalCount;

                // we increase the interval count here
                if (lucky[k] == 1 && lucky[colAt] == 1 && table[k, colAt].luckyCount > 0) {
                    table[k, colAt].intervalCount++;
                }
            }
        }
        Console.WriteLine(table[0, N-1].intervalCount);
    }
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

