using System;
using System.Collections.Generic;

class Program {
    static int guardCount;
    static int dayCount;

    static Guard[] guards;

    static void Main(string[] args) {
        String[] line = Console.ReadLine().Split(" ");
        guardCount = int.Parse(line[0]);
        dayCount = int.Parse(line[1]);

        guards = new Guard[guardCount];

        for (int i = 0; i < guardCount; i++) {
            line = Console.ReadLine().Split(" ");
            guards[i] = new Guard(int.Parse(line[0]), int.Parse(line[1]));
        }

        Array.Sort(guards);

        // we store till when the guards in the current interval can guard
        List<int> guarding = new List<int>();
        guarding.Add(0);

        // the current interval
        int currStart = guards[0].from;
        int currEnd = guards[0].till;

        // how long the longrst inerval is
        int longestInterval = 0;
        int mostGuardDayCountSol = 1;
        int mostGuardDaySol = guards[0].from;

        int mostGuardDayCount = 1;
        int mostGuardDay = 0;
        for (int i = 1; i < guardCount; i++) {
            // we have a guard that can cover after the current maximum
            if (guards[i].from <= currEnd + 1) {
                currEnd = Math.Max(currEnd, guards[i].till);

                for (int k = guarding.Count - 1; k >= 0; k--) {
                    // all the guards in guarding start sooner, so we only need to check
                    // whether the start of current is sooner then the end of them
                    if (guards[i].from > guards[guarding[k]].till) {
                        guarding.RemoveAt(k);
                    }
                }
                guarding.Add(i);

                if (guarding.Count > mostGuardDayCount) {
                    mostGuardDayCount = guarding.Count;
                    mostGuardDay = guards[i].from;
                }
            } else {
                // check whether the one before was the longest period
                if (currEnd - currStart + 1 > longestInterval) {
                    longestInterval = currEnd - currStart + 1;
                }

                if (mostGuardDayCount > mostGuardDayCountSol) {
                    mostGuardDayCountSol = mostGuardDayCount;
                    mostGuardDaySol = mostGuardDay;
                }

                // assign new interval
                currStart = guards[i].from;
                currEnd = guards[i].till;
                
                guarding.Clear();
                guarding.Add(i);
                mostGuardDay = currStart;
                mostGuardDayCount = 1;
            }
        }

        Console.WriteLine(Math.Max(longestInterval, currEnd - currStart + 1));
        if (mostGuardDayCount > mostGuardDayCountSol) {
            Console.WriteLine(mostGuardDay);
        } else {
            Console.WriteLine(mostGuardDaySol);
        }
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

class Guard : IComparable<Guard> {
    public int from;
    public int till;

    public Guard(int from, int till) {
        this.from = from;
        this.till = till;
    }

    public int CompareTo(Guard other) {
        if (this.from != other.from) {
            return this.from.CompareTo(other.from);
        } else if (this.till != other.till) {
            return this.till.CompareTo(other.till);
        }

        return 0;
    }
}

