/*
     यदा यदा हि धर्मस्य ग्लानिर्भवति भारत।
     अभ्युत्थानमधर्मस्य तदात्मानं सृजाम्यहम्॥
*/
/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्||
*/

#include <bits/stdc++.h>
using namespace std;

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k, max_n = INT_MIN, sum = 0;
    cin >> n >> k;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        sum += v1[i];
        max_n = max(max_n, v1[i]);
    }
    int lo = max_n - 1, hi = sum;
    while (hi - lo > 1) {
        int mid = lo + ((hi - lo) >> 1);
        if (isposs(v1, mid, k)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
    return 0;
}
