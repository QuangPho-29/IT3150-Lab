#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> board(9, vector<int>(9));
vector <vector <bool>> isSafeR (9, vector <bool> (9, true));
vector <vector <bool>> isSafeC (9, vector <bool> (9, true));
vector <vector <bool>> isSafeB (9, vector <bool> (9, true));

int Count = 0;

bool checking(int row, int col, int x) {
    x--;
    if (isSafeR[row][x] && isSafeC[col][x] && isSafeB[(row / 3) * 3 + col / 3][x]) {
        return true;
    }
    return false;
}

void addNum(int row, int col, int x) {
    board[row][col] = x;
    x--;
    isSafeR[row][x] = false;
    isSafeC[col][x] = false;
    isSafeB[(row / 3) * 3 + col / 3][x] = false;
    return;
}

void removeNum(int row, int col, int x) {
    board[row][col] = 0;
    x--;
    isSafeR[row][x] = true;
    isSafeC[col][x] = true;
    isSafeB[(row / 3) * 3 + col / 3][x] = true;
    return;
}

int countSolution (int k) {
    if (k == 81) {
        Count++;
        return Count;
    }

    int row = k / 9, col = k % 9;

    if (board[row][col] != 0) {
        return countSolution(k + 1);
    }

    for (int i = 1; i <= 9; i++) {
        if (checking(row, col, i)) {
            addNum(row, col, i);
            countSolution(k + 1);
            removeNum(row, col, i);
        }
    }

    return Count;
}

int main() {
    int tmp;
    for (int i  = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> tmp;
            if (tmp != 0) {
                addNum(i, j, tmp);
            }
        }
    }
    cout << countSolution(0);
    return 0;
}
