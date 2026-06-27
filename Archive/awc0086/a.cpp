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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,X,Y,R;
    cin >> N >> X >> Y >> R;
    ll ans=0;
    rep(i,N){
        ll x,y,p; cin>>x>>y>>p;
        ll dx=x-X;
        ll dy=y-Y;
        if(dx*dx+dy*dy<=R*R) ans+=p;
    }
    cout<<ans<<endl;
    return 0;
}