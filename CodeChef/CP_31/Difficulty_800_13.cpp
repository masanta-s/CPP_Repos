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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, max_n = INT_MIN;
        cin >> n;
        map<int, int> mp1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp1[x]++;
            max_n = max(max_n, x);
        }
        if (mp1.size() == 1) {
            cout << -1 << endl;
        } else {
            cout << n - mp1[max_n] << " " << mp1[max_n] << endl;
            for (auto it1: mp1) {
                if (it1.first == max_n) {
                    break;
                }
                for (int i = 0; i < it1.second; i++) {
                    cout << it1.first << " ";
                }
            }
            cout << endl;
            for (int i = 0; i < mp1[max_n]; i++) {
                cout << max_n << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
