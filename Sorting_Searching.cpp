#include<iostream>

using namespace std;
void sort_Linear(int*, int);
void search_binary(int*, int, int);
int main() {
    cout<<"Enter no of elements: ";
    int n;
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr1[i];
    }
    cout<<"Sorted array :"<<endl;
    sort_Linear(arr1, n);
    for(int i = 0; i < n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter element to be searched: ";
    int a;
    cin>>a;
    search_binary(arr1, n, a);
    return 0;
}
void sort_Linear(int* ptr, int n){
    int temp, idx;
    for(int i = 0; i < (n - 1); i++){
        int count = 0;
        for(int j = (i + 1); j < n; j++){
            if(*(ptr + j) < *(ptr + i)){
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + i);
                *(ptr + i) = temp;
            }
        }
    }
}
void search_binary(int* ptr, int n, int a){
    for(int i = 0; i <= n; ){
        int mid = (i + n) / 2;
        if(a == *(ptr + mid)){
            cout<<"Element found - Idx No: "<<mid<<endl;
            return;
        }else if(a > *(ptr + mid)){
            i = mid + 1;
        }else{
            n = mid - 1;
        }
    }
    cout<<"Element not found"<<endl;
}