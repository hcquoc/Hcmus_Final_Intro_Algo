#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<string>> ans;
vector<string> board;

bool col[10];
bool diag1[20];
bool diag2[20];

void backtrack(int row) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
            board[row][c] = 'Q';
            col[c] = diag1[row - c + n] = diag2[row + c] = 1;
            backtrack(row + 1);
            board[row][c] = '.';
            col[c] = diag1[row - c + n] = diag2[row + c] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif    
    
    cin >> n;
    board.assign(n, string(n, '.'));
    backtrack(0);
    cout << ans.size() << '\n';
    for (auto &b : ans) {
        for (auto &row : b) {
            cout << row << '\n';
        }
        cout << '\n';
    }

    return 0;
}