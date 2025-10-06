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

int binarySearch(vector<int> &v1, int lo, int hi, int target) {
    if (lo > hi) {
        return -1;
    }
    int mid = lo + ((hi - lo) >> 1);
    if (v1[mid] == target) {
        return mid;
    }
    if (v1[mid] > target) {
        return binarySearch(v1, lo, mid - 1, target);
    }
    return binarySearch(v1, mid + 1, hi, target);
}

int32_t main() {
    int n, tar;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> v1(n);
    cout << "Enter elements in the Vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    cout << "Enter element to search: ";
    cin >> tar;
    int res = binarySearch(v1, 0, n - 1, tar);
    if (res != -1) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
