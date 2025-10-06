/*
     यदा यदा हि धर्मस्य ग्लानिर्भवति भारत।
     अभ्युत्थानमधर्मस्य तदात्मानं सृजाम्यहम्॥
*/
/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
*/

#include<bits/stdc++.h>
using namespace std;

int ways(int prev, int idx, vector<int> &v1, vector<pair<int, int>> &v2, vector<vector<int>> &dp) {
    if (idx == v1.size()) {
        return 0;
    }
    if (dp[prev + 1][idx] != -1) {
        return dp[prev + 1][idx];
    }
    int min_n = INT_MAX;
    if (prev != 1 && v2[v1[idx]].second == 1) {
        min_n = min(min_n, ways(1, idx + 1, v1, v2, dp));
    }
    if (prev != 0 && v2[v1[idx]].first == 1) {
        min_n = min(min_n, ways(0, idx + 1, v1, v2, dp));
    }
    return dp[prev + 1][idx] = min(min_n, 1 + ways(-1, idx + 1, v1, v2, dp));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<pair<int, int>> v2 = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<vector<int>> dp(3, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    cout << ways(-1, 0, v1, v2, dp) << endl;
    return 0;
}