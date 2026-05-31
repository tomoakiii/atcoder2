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
    string X, Y; cin>>X>>Y;
    int xi, yi;
    map<char, int> mp;
    mp['O'] = 0;
    mp['S'] = 1;
    mp['L'] = 2;

    xi = mp[X[0]];
    yi = mp[Y[0]];
    if(xi>=yi) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}