#include<bits/stdc++.h>

using namespace std;

int main() {
    // Create a map of strings to integers
    map<string, int> mp;

    // Insert some values into the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    // Get an iterator pointing to the first element in the
    // map
    map<string, int>::iterator it = mp.begin();
    cout<<mp["three"]<<endl;
    // Iterate through the map and print the elements
/*    while (it != mp.end()) {
        cout << "Key: " << (*it).first;
        cout     << ", Value: " << it->second << endl;
        ++it;
    }*/
    mp.insert(pair<string, int>("Four", 4));
    mp.insert(pair<string, int>("Five", 5));
    for (it = mp.begin(); it != mp.end(); it++) {
        cout << "Key: " << (*it).first;
        cout     << ", Value: " << it->second << endl;
    }
    cout<<endl;
    map<string, int>::iterator itlow, itup;
    itlow = mp.lower_bound("five");
    itup = mp.upper_bound("two");
    mp.erase(itlow, itup);
    for(it = mp.begin(); it != mp.end(); it++) {
        cout << "Key: " << (*it).first;
        cout     << ", Value: " << it->second << endl;
    }
    return 0;
}