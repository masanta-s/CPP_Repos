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
    string str1;
    cin >> str1;
    stack<int> stk1;
    stk1.push(-1);
    int max_n = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == '(') {
            stk1.push(i);
        } else {
            stk1.pop();
            if (stk1.empty()) {
                stk1.push(i);
            } else {
                max_n = max(max_n, i - stk1.top());
            }
        }
    }
    cout << max_n << endl;
    return 0;
}