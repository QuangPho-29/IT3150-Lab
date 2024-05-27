#include <bits/stdc++.h>

using namespace std;

int level[] = {700, 400, 300, 200, 100, 50};
double dif[] = {-5280, -36960, -3190, -3190, -3190};
double oldV[] = {3015, 3015, 2919, 2612, 2074, 1786, 1728};
double newV[] = {3457, 3111, 2612, 2612, 2074, 1728, 2728};

int main() {
    int inp;
    cin >> inp;
    int i = 0;
    while (inp < level[i]) {
        i++;
    }
    printf ("%.2lf", (inp - level[i]) * (newV[i] - oldV[i]) * 1.1 + dif[i]);
    return 0;
}
