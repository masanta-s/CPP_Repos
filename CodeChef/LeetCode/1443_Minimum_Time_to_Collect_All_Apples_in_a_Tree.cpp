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
#define int long long
#define endl '\n'
#define sqrt sqrtl
#define __builtin_popcount __builtin_popcountll
const int MOD = 1e9 + 7;

class Solution_1443_Minimum_Time_to_Collect_All_Apples_in_a_Tree {
public:
    vector<vector<int> > g;
    vector<int> vis;
    vector<int> level;
    int sum = 0;

    void bfs(int source, vector<bool> &hasApple) {
        queue<int> q;
        q.push(source);
        vis[source] = true;
        while (!q.empty()) {
            int curr_v = q.front();
            q.pop();
            for (int child: g[curr_v]) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                    level[child] = level[curr_v] + 1;
                    if (hasApple[child]) {
                        sum += (level[child] * 2);
                    }
                }
            }
        }
    }

    int minTime(int n, vector<vector<int> > &edges, vector<bool> &hasApple) {
        g.resize(n);
        vis.resize(n);
        level.resize(n);
        int ct1 = 0;
        for (auto it1: edges) {
            g[it1[0]].push_back(it1[1]);
            g[it1[1]].push_back(it1[0]);
        }
        // dfs(0, seats);
        bfs(0, hasApple);
        // int res = pow(2, sum);
        return sum;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int> > grid = {
        {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}}
    };
    vector<bool> hasApple = {
        false, false, true, false, true, true, false
    };
    Solution_1443_Minimum_Time_to_Collect_All_Apples_in_a_Tree sol{};
    cout << "Cost: " << sol.minTime(7, grid, hasApple) << endl;
    return 0;
}
