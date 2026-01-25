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
    bool st = false;
    int Q; cin>>Q;
    int v = 0;
    while(Q--) {
        int a; cin>>a;
        if(a==1) v++;
        if(a==2) if(v>0) v--;
        if(a==3) st = !st;
        if(st && v>=3) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}