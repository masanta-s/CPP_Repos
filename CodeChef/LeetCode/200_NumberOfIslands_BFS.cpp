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

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        grid[i][j] = '0';
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        while (!q.empty()) {
            int row1 = q.front().first;
            int col1 = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row2 = row1 + drow[i];
                int col2 = col1 + dcol[i];
                if (row2 >= 0 && col2 >= 0 && row2 < grid.size() && col2 < grid[0].size() && grid[row2][col2] == '1') {
                    q.emplace(row2, col2);
                    grid[row2][col2] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ct1 = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    ct1++;
                }
            }
        }
        return ct1;
    }
};