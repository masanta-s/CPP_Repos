#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr1[n];
    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    int count = 0;
    bool flag;
    for(int i = 0; i < n; ){
        flag = false;
        for(int j = count; j <= i; j++){
            cout<<arr1[j]<<" ";
        }
        cout<<endl;
        if(i == (n - 1)){
            i = ++count;
            flag = true;
        }
        if(!flag){
            i++;
        }
    }
    return 0;
}