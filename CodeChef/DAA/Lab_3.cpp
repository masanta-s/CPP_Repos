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

int partitionArray(vector<int> &v1, int lo, int hi) {
     int pivot = v1[hi];
     int i = lo - 1;
     for (int j = lo; j < hi; j++) {
          if (v1[j] < pivot) {
               i++;
               swap(v1[i], v1[j]);
          }
     }
     swap(v1[i + 1], v1[hi]);
     return i + 1;
}

void quickSort(vector<int> &v1, int lo, int hi) {
     if (lo < hi) {
          int pivotIndex = partitionArray(v1, lo, hi);
          quickSort(v1, lo, pivotIndex - 1);
          quickSort(v1, pivotIndex + 1, hi);
     }
}

int main() {
     int n;
     cout << "Enter size of vector: ";
     cin >> n;
     vector<int> v1(n);
     cout << "Enter vector elements: ";
     for (int i = 0; i < n; i++) {
          cin >> v1[i];
     }
     cout << "Original array:" << endl;
     for (int el : v1) {
          cout << el << " ";
     }
     cout << endl;
     quickSort(v1, 0, v1.size() - 1);
     cout << "Sorted array:" << endl;
     for (int el : v1) {
          cout << el << " ";
     }
     cout << endl;
     return 0;
}
