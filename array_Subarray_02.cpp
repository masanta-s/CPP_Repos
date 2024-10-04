#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr1[n];
    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i; k <= j; k++){
                cout<<arr1[k]<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}