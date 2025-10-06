/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define sqrt sqrtl
#define INF 1e10
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

struct Edge {
    int u, v, w;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<vector<int> > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        edges[i] = {a, b, x};
        adj[a].push_back(b);
    }
    vector<int> score(n + 1, -INF);
    score[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto edge: edges) {
            if (score[edge.u] != -INF && score[edge.v] < score[edge.u] + edge.w) {
                score[edge.v] = score[edge.u] + edge.w;
            }
        }
    }
    vector<bool> affected(n + 1, false);
    queue<int> q;
    for (auto edge: edges) {
        if (score[edge.u] != -INF && score[edge.v] < score[edge.u] + edge.w) {
            affected[edge.v] = true;
            q.push(edge.v);
        }
    }
    vector<bool> visited(n + 1, false);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = true;
        for (int next: adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if (visited[n]) {
        cout << -1 << endl;
    } else {
        cout << score[n] << endl;
    }
    return 0;
}