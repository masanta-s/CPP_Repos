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

class Solution_2101_DetonateTheMaximumBombs {
public:
    vector<bool> vis;
    int dfs(vector<vector<int> > &grid, int i) {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        int ct1 = 1;
        for (int j = 0; j < grid.size(); j++) {
            long long dist1 = abs(grid[j][0] - grid[i][0]);
            long long dist2 = abs(grid[j][1] - grid[i][1]);
            long long dist = (dist1 * dist1) + (dist2 * dist2);
            long long radius = grid[i][2];
            if (dist <= radius * radius) {
                ct1 += dfs(grid, j);
            }
        }
        return ct1;
    }

    int maximumDetonation(vector<vector<int> > &bombs) {
        int n = bombs.size(), max_n = 0;
        vis.resize(n);
        for (int i = 0; i < n; i++) {
            fill(vis.begin(), vis.end(), false);
            max_n = max(max_n, dfs(bombs, i));
        }
        return max_n;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int> > grid = {
        {2, 1, 3}, {6, 1, 4}
    };
    Solution_2101_DetonateTheMaximumBombs sol{};
    cout << "Bombs: " << sol.maximumDetonation(grid) << endl;
    return 0;
}
