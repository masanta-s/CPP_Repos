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
    int n, tar, ct1 = 0;
    cout << "Enter the size of the Vector: " << endl;
    cin >> n;
    cout << "Enter the Target Value: " << endl;
    cin >> tar;
    vector<int> v1(n);
    cout << "Enter the Vector elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end(), greater<int>());
    while (tar) {
        for (int el: v1) {
            if (el > tar) {
                continue;
            }
            while (tar >= el) {
                tar -= el;
                ct1++;
            }
        }
    }
    cout << "Minimum No of Coins required to reach Target: " << ct1 << endl;
    return 0;
}