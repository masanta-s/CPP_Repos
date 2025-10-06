#include<bits/stdc++.h>

using namespace std;

int main() {
    set<int, greater<int>> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    set<int>::iterator it;
    for(it = s1.begin(); it != s1.end(); it++) {
        cout<<*it<<endl;
    }
    cout<<s1.max_size()<<endl;
    set<int> s2(s1.begin(), s1.end());
    for(it = s2.begin(); it != s2.end(); it++) {
        cout<<*it<<endl;
    }
    s2.erase(s2.begin(), s2.find(5));
    for(it = s2.begin(); it != s2.end(); it++) {
        cout<<*it<<endl;
    }
    const set<int, greater<int>>::iterator &z = max_element(s1.begin(), s1.end());
    cout<<*z<<endl;
    return 0;
}