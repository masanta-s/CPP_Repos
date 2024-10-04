#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1="We think in generalities, but we live in details.";
    string str2 = str1.substr (3,8);
    string str3 = "aba";
    string str4 = "abc";
    cout<<str2<<endl;
    cout<<str3.compare(str4)<<endl;
    return 0;
}