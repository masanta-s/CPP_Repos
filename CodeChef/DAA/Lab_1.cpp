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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(istream::failbit);
    cout << "Enter the No of Test Cases: " << endl;
    int t;
    cin >> t;
    while(t--) {
        cout << "Enter the No of elements of the Vector: " << endl;
        int n;
        cin >> n;
        cout << "Enter the elements of the Vector: " << endl;
        vector<int> v1(n);
        for(int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        cout << "Enter the Target Value: " << endl;
        int tar, idx = -1;
        cin >> tar;
        for(int i = 0; i < n; i++) {
            if(v1[i] == tar) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            cout << "Target Value found at index: " << idx << endl;
        } else {
            cout << "Value not found" << endl;
        }
    }
    return 0;
}
