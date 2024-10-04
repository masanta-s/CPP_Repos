#include<iostream>
using namespace std;

int main() {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            b[j][i] = a[i][j];
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}