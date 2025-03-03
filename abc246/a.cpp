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
    map<int,int> cx, cy;
    rep(i,3) {
        int x,y;
        cin>>x>>y;
        cx[x]++;
        cy[y]++;
    }
    
    int ax, ay;
    for(auto m: cx) {
        if(m.second == 1) {
            ax = m.first;
        }
    }
    for(auto m: cy) {
        if(m.second == 1) {
            ay = m.first;
        }
    }
    cout << ax << " " << ay << endl;
    return 0;
}
