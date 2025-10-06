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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, xk, yk, xq, yq, ct1 = 0;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        map<pair<int, int>, int> m1;
        m1[{xk + a, yk + b}] += 1;
        m1[{xk + b, yk + a}] += 1;
        m1[{xk - a, yk + b}] += 1;
        m1[{xk - b, yk + a}] += 1;
        m1[{xk + a, yk - b}] += 1;
        m1[{xk + b, yk - a}] += 1;
        m1[{xk - a, yk - b}] += 1;
        m1[{xk - b, yk - a}] += 1;

        m1[{xq + a, yq + b}] += 1;
        m1[{xq + b, yq + a}] += 1;
        m1[{xq - a, yq + b}] += 1;
        m1[{xq - b, yq + a}] += 1;
        m1[{xq + a, yq - b}] += 1;
        m1[{xq + b, yq - a}] += 1;
        m1[{xq - a, yq - b}] += 1;
        m1[{xq - b, yq - a}] += 1;
        for (auto it1: m1) {
            if (a == b && it1.second > 2) {
                ct1++;
            } else if (a != b && it1.second > 1) {
                ct1++;
            }
        }
        cout << ct1 << endl;
    }
    return 0;
}