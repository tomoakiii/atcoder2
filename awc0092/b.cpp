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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,L,T;
    cin >> N >> L >> T;
    rep(i,N){
        ll x,v; cin>>x>>v;
        ll y=v*T;
        y%=(2*L);
        if(v>0){
            ll r=L-x;
            if(y<=r){
                cout<<x+y<<endl;
                continue;
            }
            y-=r;
            if(y<=L){
                cout<<L-y<<endl;
                continue;
            }
            y-=L;
            cout<<y<<endl;
            continue;
        } else {
            if(y<=x){
                cout<<x-y<<endl;
                continue;
            }
            y-=x;
            if(y<=L){
                cout<<y<<endl;
                continue;
            }
            y-=L;
            cout<<L-y<<endl;
            continue;
        }
    }
    return 0;
}