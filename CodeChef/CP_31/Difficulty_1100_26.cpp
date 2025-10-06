/*
     यदा यदा हि धर्मस्य ग्लानिर्भवति भारत।
     अभ्युत्थानमधर्मस्य तदात्मानं सृजाम्यहम्॥
*/
/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
*/

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

int binExpo(int x, int n) {
    int ans = 1;
    while (n) {
        if ((n & 1)) {
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}

vector<bool> primeNumbers(int N) {
    vector<bool> isPrime(N + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}

int nCr(int n, int r) {
    int p = 1, k = 1;
    if (n - r < r) {
        r = n - r;
    }
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            int m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }
    return p;
}

int longestCommonSubstring(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    int mx_l = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                mx_l = max(mx_l, dp[i][j]);
            }
        }
    }
    return mx_l;
}

int computeXOR(int n) {
    if (n % 4 == 0) {
        return n;
    }
    if (n % 4 == 1) {
        return 1;
    }
    if (n % 4 == 2) {
        return n + 1;
    }
    return 0;
}

vector<int> positions_0_1(string str1) {
    vector<int> pos_0;
    vector<int> pos_1;
    for (int i = str1.size() - 1; i >= 0; i--) {
        if (str1[i] == '0') {
            pos_0.push_back(i);
        } else {
            pos_1.push_back(i);
        }
    }
    return (pos_1.size() <= pos_0.size() ? pos_1 : pos_0);
}

pair<int, pair<int, int> > subsequence_10_01_calculate(string str1) {
    int sum1 = 0;
    int lstIdx = str1.size() - 1;
    vector<int> pos = positions_0_1(str1);
    for (int i = 0; i < pos.size(); i++) {
        sum1 += (lstIdx - pos[i] - i);
    }
    return {sum1, {pos.size(), str1[pos[0]] - '0'}};
}

pair<int, int> nos_01_10(string str1) {
    pair<int, pair<int, int> > p1 = subsequence_10_01_calculate(str1);
    if (p1.second.second) {
        return {p1.first, ((str1.size() - p1.second.first) * p1.second.first) - p1.first};
    }
    return {((str1.size() - p1.second.first) * p1.second.first) - p1.first, p1.first};
}

// const int N = 1e5 + 10;
// vector<int> g[N];
// bool vis[N];
//
// void dfs(int vertex) {
//     // Take action on vertex after entering the vertex
//     vis[vertex] = true;
//     for (int child: g[vertex]) {
//         if (vis[child]) {
//             continue;
//         }
//         // Take action on child before entering the child node
//         dfs(child);
//         // Take action on child after exiting the child node
//     }
//     // Take action on vertex before exiting the vertex
// }
//
// int level[N];
//
// void bfs(int source) {
//     queue<int> q;
//     q.push(source);
//     vis[source] = true;
//     while (!q.empty()) {
//         int curr_v = q.front();
//         q.pop();
//         for (int child: g[curr_v]) {
//             if (!vis[child]) {
//                 q.push(child);
//                 vis[child] = true;
//                 level[child] = level[curr_v] + 1;
//             }
//         }
//     }
// }

// vector<pair<int, int>> g[N];
//
// void dijkstra(int source) {
//     vector<bool> vis(N, false);
//     vector<int> dist(N, INT_MAX);
//     set<pair<int, int>> s1;
//     s1.insert({0, source});
//     dist[source] = 0;
//     while (!s1.empty()) {
//         auto it1 = *s1.begin();
//         int v = it1.second;
//         int v_dist = it1.first;
//         s1.erase(s1.begin());
//         if (vis[v]) {
//             continue;
//         }
//         vis[v] = true;
//         for (auto child: g[v]) {
//             int child_v = child.first;
//             int wt = child.second;
//             if (dist[v] + wt < dist[child_v]) {
//                 dist[child_v] = dist[v] + wt;
//                 s1.insert({dist[child_v], child_v});
//             }
//         }
//     }
// }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, max_n = 0;
        cin >> n;
        vector<int> v1(n), v2(n), v3(n);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        inclusive_scan(execution::par_unseq, v1.begin(), v1.end(), v2.begin());
        inclusive_scan(execution::par_unseq, v1.rbegin(), v1.rend(), v3.rbegin());
        for (int i = 0; i < n - 1; i++) {
            auto it1 = lower_bound(v3.begin() + i + 1, v3.end(), v2[i], greater<int>());
            if (it1 != v3.end() && *it1 == v2[i]) {
                max_n = max(max_n, n - distance(v3.begin(), it1) + i + 1);
            }
        }
        cout << max_n << endl;
    }
    return 0;
}
