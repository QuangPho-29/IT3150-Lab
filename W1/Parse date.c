#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.size() != 10) {
        cout << "INCORRECT";
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (s[i] != '-') {
                cout << "INCORRECT";
                return 0;
            }
        } else if (!isdigit(s[i])) {
            cout << "INCORRECT";
            return 0;
        }
    }

    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    int monthD[][] = {{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} , {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int prime;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) prime  = 0;
    else prime  = 1;

    if (month < 1 || month > 12 || day < 1 || day > monthD[year][month - 1]) {
        cout << "INCORRECT";
        return 0;
    }

    cout << year << " " << month << " " << day;
    return 0;
}
