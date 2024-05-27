#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <int> fi;

int fibonancci (int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    fi.push_back(fibonancci(n - 2));

    return (fibonancci(n - 1) + fi.back());
}

int main() {
    int n;
    cin >> n;

    cout << fibonancci(n - 1);
    return 0;
}
