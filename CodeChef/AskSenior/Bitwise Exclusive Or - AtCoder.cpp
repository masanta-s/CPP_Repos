/*
     यदा यदा हि धर्मस्य ग्लानिर्भवति भारत।
     अभ्युत्थानमधर्मस्य तदात्मानं सृजाम्यहम्॥
*/
/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
*/


//(nCr(n, r) & 1) is same as ((n & i) == i)
#include<bits/stdc++.h>
// #include <execution>
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
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // for integral types (int, long long, etc.)
    template<typename T>
    typename enable_if<is_integral<T>::value, size_t>::type
    operator()(T x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(uint64_t(x) + FIXED_RANDOM);
    }

    // for pairs of integrals
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = operator()(p.first);
        uint64_t h2 = operator()(p.second);
        // hash combine
        return h1 ^ (h2 + 0x9e3779b97f4a7c15 + (h1 << 6) + (h1 >> 2));
    }
};

template<typename K, typename V>
using fast_map = gp_hash_table<K, V, custom_hash>;

template<typename T>
using fast_set = unordered_set<T, custom_hash>;

map<u64, vector<u64> > dp_factors;

struct Node {
    unique_ptr<Node> left; // Represents path for bit 0
    unique_ptr<Node> right; // Represents path for bit 1
};

class Trie {
private:
    unique_ptr<Node> root;

public:
    Trie() {
        root = make_unique<Node>();
    }

    void insert(int num) {
        Node *node = root.get();
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit) {
                if (node->right == nullptr) {
                    node->right = make_unique<Node>();
                }
                node = node->right.get();
            } else {
                if (node->left == nullptr) {
                    node->left = make_unique<Node>();
                }
                node = node->left.get();
            }
        }
    }

    int getMaxXOR(int num) {
        Node *node = root.get();
        int max_n = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit) {
                if (node->left != nullptr) {
                    max_n |= (1 << i);
                    node = node->left.get();
                } else {
                    node = node->right.get();
                }
            } else {
                if (node->right != nullptr) {
                    max_n |= (1 << i);
                    node = node->right.get();
                } else {
                    node = node->left.get();
                }
            }
        }
        return max_n;
    }
};

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

vector<int> fact, invFact;

void precompute(int N) {
    fact.assign(N + 1, 1);
    invFact.assign(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[N] = binExpo(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute nCr in O(1)
int precompute_nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    if (r > n - r) {
        r = n - r;
    }
    int numerator = 1;
    for (int i = 0; i < r; i++) {
        numerator = (numerator * (n - i)) % MOD;
    }
    int denominator = 1;
    for (int i = 1; i <= r; i++) {
        denominator = (denominator * i) % MOD;
    }
    return (numerator * binExpo(denominator, MOD - 2)) % MOD;
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

int max_xor(vector<int> v1) {
    int mask = 0, ans = 0, n = v1.size();
    for (int i = 32; i >= 0; i--) {
        mask |= (1LL << i);
        fast_set<int> s1;
        for (int j = 0; j < n; j++) {
            s1.insert((v1[j] & mask));
        }
        int candidate = ans | (1LL << i);
        for (int prefix: s1) {
            if (s1.find(prefix ^ candidate) != s1.end()) {
                ans = candidate;
                break;
            }
        }
    }
    return ans;
}

vector<int> xorAnalysis(const vector<int> &arr, int queryK = -1, int kth = -1) {
    const int LOG = 60;
    int basis[LOG] = {};
    int sz = 0, total = 0;
    auto insertVector = [&](int x) {
        total++;
        for (int i = LOG - 1; i >= 0; i--) {
            if (!(x >> i & 1)) {
                continue;
            }
            if (!basis[i]) {
                basis[i] = x;
                sz++;
                return;
            }
            x ^= basis[i];
        }
    };
    for (auto x: arr) {
        insertVector(x);
    }
    int maxXor = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        maxXor = max(maxXor, maxXor ^ basis[i]);
    }
    int minXor = 0;
    for (int i = 0; i < LOG; i++)
        if (basis[i]) {
            minXor = basis[i];
            break;
        }
    auto canMake = [&](int k) {
        for (int i = LOG - 1; i >= 0; i--)
            if (k >> i & 1) {
                if (!basis[i]) return false;
                k ^= basis[i];
            }
        return true;
    };
    bool possible = (queryK == -1 ? false : canMake(queryK));
    int ways = 0;
    if (queryK != -1 && possible) {
        ways = 1LL << (total - sz);
    }
    int distinctCnt = 1LL << sz;
    int kthXor = -1;
    if (kth != -1 && kth < distinctCnt) {
        vector<int> vals;
        for (int i = 0; i < LOG; i++) {
            if (basis[i]) {
                vals.push_back(basis[i]);
            }
        }
        for (int i = 0; i < vals.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((vals[i] ^ vals[j]) < vals[i]) {
                    vals[i] ^= vals[j];
                }
            }
        }
        sort(vals.begin(), vals.end());
        int res = 0;
        for (int i = 0; i < vals.size(); i++)
            if (kth >> i & 1) {
                res ^= vals[i];
            }
        kthXor = res;
    }
    return {
        maxXor, // [0] Max XOR
        minXor, // [1] Min non-zero XOR
        possible, // [2] Can make queryK? (1/0)
        ways, // [3] Number of subsets making queryK
        distinctCnt, // [4] Number of distinct XORs
        kthXor // [5] k-th smallest XOR
    };
}

int countSetBits(int n) {
    int ans = 0;
    for (int i = 0; (1LL << i) <= n; i++) {
        int cycle = 1LL << (i + 1); // length of full cycle
        int full_cycles = (n + 1) / cycle;
        ans += full_cycles * (1LL << i); // contribution of complete cycles
        int remainder = (n + 1) % cycle;
        ans += max(0LL, remainder - (1LL << i)); // partial cycle contribution
    }
    return ans;
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
            if (i != n / i) {
                large.push_back(n / i);
            }
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

vector<u64> all_factors(u64 n) {
    vector<u64> pf;
    factor(n, pf); // uses your Pollard’s Rho + memo
    sort(pf.begin(), pf.end());
    // Count multiplicities
    vector<pair<u64,int> > primes;
    for (size_t i = 0; i < pf.size();) {
        size_t j = i;
        while (j < pf.size() && pf[j] == pf[i]) j++;
        primes.emplace_back(pf[i], (int) (j - i));
        i = j;
    }
    // Generate factors
    vector<u64> factors = {1};
    for (auto [p, cnt]: primes) {
        size_t sz = factors.size();
        u64 mul = 1;
        for (int c = 1; c <= cnt; ++c) {
            mul *= p;
            for (size_t k = 0; k < sz; ++k)
                factors.push_back(factors[k] * mul);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

void dfs(int vertex, vector<int> &vis, vector<vector<int> > &g) {
    // Take action on vertex after entering the vertex
    vis[vertex] = true;
    for (int child: g[vertex]) {
        if (vis[child]) {
            continue;
        }
        // Take action on child before entering the child node
        dfs(child, vis, g);
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}

void bfs(int source, vector<bool> &vis, vector<int> &level, vector<vector<int> > &g) {
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
            }
        }
    }
}

bool detectCycleBFS(int source, vector<bool> &vis, vector<int> &level, vector<vector<int> > &g) {
    queue<pair<int,int> > q; // {node, parent}
    q.emplace(source, -1);
    vis[source] = true;
    while (!q.empty()) {
        auto [curr_v, parent] = q.front();
        q.pop();
        for (int child: g[curr_v]) {
            if (!vis[child]) {
                q.emplace(child, curr_v);
                vis[child] = true;
                level[child] = level[curr_v] + 1;
            } else if (child != parent) {
                // ✅ Found a back edge → cycle exists
                return true;
            }
        }
    }
    return false; // no cycle found in this BFS
}

void dijkstra(int source, int n, vector<int> &dist, vector<int> &parent, vector<vector<pair<int, int> > > g) {
    int INF = 1e18;
    dist.assign(n + 1, INF);
    parent.assign(n + 1, 0);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.emplace(0, source);
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (d > dist[v]) {
            continue;
        }
        for (auto &edge: g[v]) {
            int child_v = edge.first;
            int wt = edge.second;
            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                parent[child_v] = v;
                pq.emplace(dist[child_v], child_v);
            }
        }
    }
}

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

int ways(vector<int> &v1, map<vector<int>, int> &dp) {
    if (v1.size() == 1) {
        return v1.front();
    }
    if (dp.find(v1) != dp.end()) {
        return dp[v1];
    }
    vector<int> v2;
    for (int i = 0; i < v1.size() - 1; i++) {
        v2.push_back(v1[i] ^ v1[i + 1]);
    }
    return dp[v1] = ways(v2, dp);
}

bool isposs(vector<int> &v1, int tar, int k) {
    int sub_sum = 0, sum = 0, n = v1.size();
    for (int i = 0; i < n; i++) {
        if (sum + v1[i] <= tar) {
            sum += v1[i];
        } else {
            sub_sum++;
            sum = v1[i];
        }
    }
    return sub_sum <= k;
}

int recursive_BS(vector<int> &v1, int lo, int hi, int tar, int &ct1) {
    ct1++;
    if (lo > hi) {
        return -1;
    }
    int mid = lo + ((hi - lo) >> 1);
    if (v1[mid] == tar) {
        return mid;
    }
    if (v1[mid] > tar) {
        return recursive_BS(v1, lo, mid - 1, tar, ct1);
    }
    return recursive_BS(v1, mid + 1, hi, tar, ct1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(istream::failbit);
    int a, b;
    cin >> a >> b;
    cout << (a ^ b) << endl;
    return 0;
}