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
    int n, target;
    cin >> n >> target;
    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int lo = 0, hi = n - 1;
    while(hi >= lo){
        int mid = lo + ((hi - lo) >> 1);
        if(v1[mid] == target){
            cout << mid << endl;
            return 0;
        }
        if(v1[lo] <= v1[mid]){
            if(target >= v1[lo] && target <= v1[mid]){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if(target >= v1[mid] && target <= v1[hi]){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}