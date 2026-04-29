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
    int h,w; cin>>h>>w;
    vector<string> S(h, string(w, '#'));
    for(int i=1; i<h-1; i++) for(int j=1; j<w-1; j++) S[i][j]='.';
    rep(i,h) cout<<S[i]<<endl;
    return 0;
}