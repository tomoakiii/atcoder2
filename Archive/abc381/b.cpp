#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){    
    string S;
    cin >> S;
    if(S.size()%2!=0) {
        cout<<"No"<<endl;
        return 0;
    }
    map<char, int> mp;
    bool cont = false;
    char last = 0;
    for(auto c:S){
        if(cont) {
            if (last != c) {
                cout<<"No"<<endl;
                return 0;    
            }
        }
        last = c;
        cont = !cont;
        mp[c]++;
    }
    for(auto m:mp) {
        if (m.second != 2) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}