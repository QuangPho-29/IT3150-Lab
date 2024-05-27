#include <bits/stdc++.h>

using namespace std;

int UCLN(int a, int b)
{
    if (b==0)
       return a;
    return UCLN(b, a%b);
}

int solution (int capacityA, int capacityB, int goal) {
    int inA = capacityA, inB = 0, step = 1;
    //cout << inA << " " << inB << endl;
    while (inA != goal && inB != goal) {
        int amount = min(inA, capacityB - inB);
        inB += amount;
        inA -= amount;
        //cout << inA << " " << inB << endl;
        step++;

        if(inA == goal || inB == goal) break;
        if (inA == 0) {
            inA = capacityA;
            //cout << inA << " " << inB << endl;
            step++;
        }
        if (inB == capacityB) {
            inB = 0;
            //cout << inA << " " << inB << endl;
            step++;
        }
    }

    return step;
}

int solve (int m, int n, int goal) {
    if ((goal % UCLN(m, n) != 0) || (goal  > max(m, n))) {
        return -1;
    }

    return min(solution(m, n, goal), solution(n, m, goal));
}

int main() {
    int m, n, d;
    cin >> m >> n >> d;
    cout << solve (m, n, d);
    return 0;
}
