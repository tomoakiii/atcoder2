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
    string S; cin>>S;
    map<char,int> mp;
    int mx=0;
    for(auto c:S) {
        mp[c]++;
        chmax(mx, mp[c]);
    }
    for(auto c:S) {
        if(mp[c] == mx) continue;
        else cout<<c;
    }
    cout<<endl;
    return 0;
}