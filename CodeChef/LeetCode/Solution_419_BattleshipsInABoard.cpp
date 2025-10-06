#include<bits/stdc++.h>
#include <execution>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt,abm,fma")
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define int long long
#define endl '\n'
#define sqrt sqrtl
#define __builtin_popcount __builtin_popcountll
const int MOD = 1e9 + 7;

class Solution_419_BattleshipsInABoard {
public:

    void dfs(vector<vector<char> > &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '.') {
            return;
        }
        grid[i][j] = '.';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int countBattleships(vector<vector<char> > &board) {
        int n = board.size();
        int m = board[0].size();
        int ct1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    dfs(board, i, j);
                    ct1++;
                }
            }
        }
        return ct1;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<char> > grid = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };
    Solution_419_BattleshipsInABoard sol;
    cout << "No of Components: " << sol.countBattleships(grid) << endl;
    return 0;
}
