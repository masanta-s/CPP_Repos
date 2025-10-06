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
#define _builtin_popcount __builtin_popcountll
const int MOD = 998244353;
using u64 = uint64_t;
using u128 = __uint128_t;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<int, int> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(p.first + FIXED_RANDOM) ^ splitmix64(p.second + FIXED_RANDOM + 424242);
    }
};

struct pair_hash {
    size_t operator()(const std::pair<int, std::vector<int> > &p) const {
        size_t h = std::hash<int>()(p.first);
        for (auto x: p.second) {
            h ^= std::hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};


map<u64, vector<u64> > dp_factors;


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

// Calculate the n-th root of value 'a' with given precision (epsilon)
double nthRoot(double a, int n, double epsilon = 1e-9) {
    double x_prev = a > 1 ? a : 1.0; // Good initial guess
    while (true) {
        double x_next = ((n - 1) * x_prev + a / pow(x_prev, n - 1)) / n;
        if (fabs(x_next - x_prev) < epsilon) {
            break;
        }
        x_prev = x_next;
    }
    return x_prev;
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

int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= end) {
        temp.push_back(arr[j++]);
    }
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid + 1, end);
        int invCount = merge(arr, st, mid, end);
        return leftInvCount + rightInvCount + invCount;
    }
    return 0;
}

vector<int> factors(int n) {
    vector<int> small, large;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            small.push_back(i);
            if (i != n / i) large.push_back(n / i);
        }
    }
    reverse(large.begin(), large.end()); // Make the second half sorted
    small.insert(small.end(), large.begin(), large.end()); // Combine both
    return small;
}

// ---------------------------------------Prime Factors Start---------------------------------------
u64 mul(u64 a, u64 b, u64 mod) {
    return (u128) a * b % mod;
}

u64 binpow(u64 a, u64 b, u64 mod) {
    u64 res = 1;
    while (b) {
        if (b & 1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool is_prime(u64 n) {
    if (n < 2) return false;
    for (u64 p: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n % p == 0) return n == p;
        u64 d = n - 1, s = 0;
        while ((d & 1) == 0) d >>= 1, ++s;
        u64 x = binpow(p, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (u64 r = 1; r < s; ++r) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

u64 pollard(u64 n) {
    if (n % 2 == 0) return 2;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        u64 c = rng() % (n - 1) + 1;
        u64 x = rng() % (n - 1) + 1;
        u64 y = x;
        u64 d = 1;
        while (d == 1) {
            x = (mul(x, x, n) + c) % n;
            y = (mul(y, y, n) + c) % n;
            y = (mul(y, y, n) + c) % n;
            d = gcd((u64) abs((int64_t) x - (int64_t) y), n);
        }
        if (d != n) return d;
    }
}

void factor(u64 n, vector<u64> &res) {
    if (n == 1) return;
    if (dp_factors.count(n)) {
        res.insert(res.end(), dp_factors[n].begin(), dp_factors[n].end());
        return;
    }
    if (is_prime(n)) {
        res.push_back(n);
        dp_factors[n] = {n};
        return;
    }
    u64 d = pollard(n);
    vector<u64> res1, res2;
    factor(d, res1);
    factor(n / d, res2);
    res.insert(res.end(), res1.begin(), res1.end());
    res.insert(res.end(), res2.begin(), res2.end());
    dp_factors[n] = res;
}

vector<int> prime_factors(u64 n) {
    vector<u64> temp;
    factor(n, temp);
    sort(temp.begin(), temp.end()); // If you want to get the Factors in Sorted Manner
    vector<int> result;
    for (u64 x: temp) result.push_back((int) x);
    return result;
}

// ---------------------------------------Prime Factors End---------------------------------------

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
// void bfs(int source, vector<bool> &vis, vector<int> &level, vector<vector<int>> &g) {
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

int knapsack(vector<int> &v1, vector<int> &v2, int wt, int n, vector<vector<int> > &dp) {
    if (wt == 0 || n == 0) {
        return 0;
    }
    if (dp[n][wt] != -1) {
        return dp[n][wt];
    }
    if (v1[n - 1] <= wt) {
        return dp[n][wt] = max(v2[n - 1] + knapsack(v1, v2, wt - v1[n - 1], n - 1, dp),
                               knapsack(v1, v2, wt, n - 1, dp));
    }
    return dp[n][wt] = knapsack(v1, v2, wt, n - 1, dp);
}

int ways(int idx, int n, vector<int> &v1, vector<int> v2, vector<int> &v3,
         map<tuple<int, vector<int>, vector<int> >, int> &dp) {
    auto key = make_tuple(idx, v2, v3);
    if (dp.count(key)) {
        return dp[key];
    }
    if (idx == n) {
        int sum = 0;
        for (int i = 0; i < v2.size() - 1; i++) {
            if (v2[i] < v2[i + 1]) {
                sum++;
            }
        }
        for (int i = 0; i < v3.size() - 1; i++) {
            if (v3[i] < v3[i + 1]) {
                sum++;
            }
        }
        return dp[key] = sum;
    }
    int min_n = INT_MAX;
    v2.push_back(v1[idx]);
    min_n = min(min_n, ways(idx + 1, n, v1, v2, v3, dp));
    v2.pop_back();
    v3.push_back(v1[idx]);
    min_n = min(min_n, ways(idx + 1, n, v1, v2, v3, dp));
    v3.pop_back();
    return dp[key] = min_n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, m, sum = 0, lb = 0;
        cin >> n >> m;
        if (!m) {
            cout << ((n * (n + 1)) >> 1) << endl;
            continue;
        }
        vector<int> v1(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            v1[b] = max(v1[b], a);
        }
        sum = ((n * (n + 1)) >> 1);
        for (int r = 1; r <= n; r++) {
            lb = max(lb, v1[r]);
            sum -= lb;
        }
        cout << sum << endl;
    }
    return 0;
}
