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
        ll y=abs(v)*T;
        y%=(2*L);
        bool flg = (v>0)? true : false;
        while(true){
            if(flg){
                ll r=L-x;
                if(y<=r){
                    cout<<x+y<<endl;
                    break;
                }
                y-=r;
                x = L;
                flg = false;
            } else {
                if(y<=x){
                    cout<<x-y<<endl;
                    break;
                }
                y-=x;
                x = 0;
                flg = true;
            }
        }
    }
    return 0;
}