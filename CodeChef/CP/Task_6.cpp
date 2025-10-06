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
    string str1, str2, str3;
    cin >> str1;
    bool flag = false;
    if (str1[0] == '-') {
        flag = true;
        str1 = str1.substr(1);
    }
    size_t sz = str1.find('.');
    if (sz == string::npos) {
        str2 = str1;
        str3 = "";
    } else {
        str2 = str1.substr(0, sz);
        str3 = str1.substr(sz + 1);
    }
    str3.resize(2, '0');
    if (flag) {
        cout << "($";
    } else {
        cout << "$";
    }
    int len = str2.size();
    int temp = (len - 1) % 3 + 1;
    cout << str2.substr(0, temp);
    for (int i = temp; i < len; i += 3) {
        cout << "," << str2.substr(i, 3);
    }
    cout << "." << str3;
    if (flag) {
        cout << ")";
    }
    cout << endl;
    return 0;
}
