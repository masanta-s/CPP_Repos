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
    void dfs(int n, int m, vector<vector<char>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        if(n < 0 || m < 0){
            return;
        } else if(n >= i || m >= j) {
            return;
        } else if(grid[n][m] != '1'){
            return;
        }
        
        grid[n][m] = '0';

        dfs(n + 1, m, grid);
        dfs(n - 1, m, grid);
        dfs(n, m + 1, grid);
        dfs(n, m - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ct1 = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ct1++;
                }
            }
        }
        return ct1;
    }
};