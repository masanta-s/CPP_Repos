/*
ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str1;
    cin >> str1;
    map<char, int> mp1, mp2, mp3;
    for (char ch1: str1) {
        mp1[ch1]++;
    }
    cin >> mp2['B'] >> mp2['S'] >> mp2['C'];
    cin >> mp3['B'] >> mp3['S'] >> mp3['C'];
    int n;
    cin >> n;
    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cst = 0;
        bool flag = true;
        for (char item: {'B', 'S', 'C'}) {
            int req = mid * mp1[item] - mp2[item];
            if (req > 0) {
                cst += req * mp3[item];
            }
            if (cst > n) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
