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

class Solution_994_RottingOranges {
public:
    void dfs(vector<vector<int> > &grid, int i, int j, int ct1) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || (grid[i][j] < ct1 && grid[i][j] > 1) || grid[i]
            [j] == 0) {
            return;
            }
        grid[i][j] = ct1;
        dfs(grid, i - 1, j, ct1 + 1);
        dfs(grid, i + 1, j, ct1 + 1);
        dfs(grid, i, j - 1, ct1 + 1);
        dfs(grid, i, j + 1, ct1 + 1);
    }

    int orangesRotting(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_n = 0;
        int ct1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j, 2);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                max_n = max(max_n, grid[i][j]);
            }
        }
        return max(0, max_n - 2);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int> > grid = {
        {2, 1, 1}, {1, 1, 0}, {0, 1, 1}
    };
    Solution_994_RottingOranges sol;
    cout << "Time: " << sol.orangesRotting(grid) << endl;
    return 0;
}
