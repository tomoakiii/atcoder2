#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll S,R,P;
    cin >> S >> P >> R;
    ll M; cin>>M;
    rep(i,M){
        ll e, v; cin>>e>>v;
        if(e==1){
            S+=v;
        }else{
            S-=v*P;
        }
    }
    cout<<S-R<<endl;
    return 0;
}