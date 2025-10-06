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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k, sum1 = 0;
    cin >> n >> k;
    string str1;
    cin >> str1;
    for (int i = 0; i < k; i++) {
        map<int, int> mp1;
        int sum2 = 0, max_n = 0;
        for (int j = i; j < n; j += k) {
            mp1[str1[j]]++;
            sum2++;
            max_n = max(max_n, mp1[str1[j]]);
        }
        sum1 += sum2 - max_n;
    }
    cout << sum1 << endl;
    return 0;
}