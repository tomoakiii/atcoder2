#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto c:s) {
        mp[c]++;
    }
    map<int, int> mp2;
    for (auto m:mp) {
        mp2[m.second]++;
    }
    for (auto m2:mp2) {
        if (m2.second == 0 || m2.second == 2){
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;       
    return 0;
}