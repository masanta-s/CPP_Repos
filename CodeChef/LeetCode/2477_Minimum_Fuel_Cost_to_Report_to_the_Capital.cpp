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

class Solution_2477_Minimum_Fuel_Cost_to_Report_to_the_Capital {
public:
    vector<vector<int> > g;
    vector<int> vis;
    int sum = 0;
    int dfs(int curr, int seats) {
        int ct1 = 1;
        vis[curr] = true;
        for (auto it1: g[curr]) {
            if (!vis[it1]) {
                ct1 += dfs(it1, seats);
            }
        }
        if (curr) {
            sum += ceil((double) ct1 / seats);
        }
        return ct1;
    }

    int minimumFuelCost(vector<vector<int> > &roads, int seats) {
        g.resize(roads.size() + 1);
        vis.resize(roads.size() + 1);
        sum = 0;
        for (auto it1: roads) {
            g[it1[0]].push_back(it1[1]);
            g[it1[1]].push_back(it1[0]);
        }
        dfs(0, seats);
        return sum;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int> > grid = {
        {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}}
    };
    Solution_2477_Minimum_Fuel_Cost_to_Report_to_the_Capital sol{};
    cout << "Cost: " << sol.minimumFuelCost(grid, 2) << endl;
    return 0;
}
