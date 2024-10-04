#include<iostream>
#include<vector>
#include<algorithm>
#include<array>

using namespace std;
bool myCompare(pair <int, int> p1, pair <int, int> p2){
    return (p1.first < p2.first);
}
void pairSort();
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<endl;
    }
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout<<*it<<endl;
    }
    for(auto element: v){
        cout<<element<<endl;
    }
    vector<int> v2 (3, 50); //v2[0] = 50; v2[1] = 50; v2[2] = 50; v2[3] = 50;
    swap(v, v2);
    for(int i = 0; i < v.size(); i++){
        cout<<"v "<<i<<": "<<v[i]<<""<<" v2 "<<i<<": "<<v2[i]<<endl;
    }
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v.size(); i++){
        cout<<v2[i]<<endl;
    }
    pair <int, char> p;
    p.first = 5;
    p.second = 'A';
    pairSort();
    return 0;
}
void pairSort(){
    int arr1[] = {4, 5, 6, 3, 2, 1};
    vector < pair <int, int> > v1;
    for(int i = 0; i < (sizeof (arr1) / sizeof (arr1[0])); i++){
        v1.push_back(make_pair(arr1[i], i));
    }
    sort(v1.begin(), v1.end(), myCompare);
    for(int i = 0; i < (sizeof (arr1) / sizeof (arr1[0])); i++){
        arr1[v1[i].second] = i;
    }
    for(auto i: arr1) {
        cout<<i<<"\t";
    }
}