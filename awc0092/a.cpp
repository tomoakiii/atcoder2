//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> S(N),C(N);
    rep(i,N)cin>>S[i];
    rep(i,N)cin>>C[i];
    while(Q--){
        ll id;
        cin>>id;
        if(id==1){
            ll l,r,v;
            cin>>l>>r>>v;
            l--,r--;
            for(int i=l;i<=r;i++){
                C[i]+=v;
            }
        } else if(id==2){
            ll x; cin>>x;
            x--;
            C[x]=INF;
        } else {
            ll l,r; cin>>l>>r; l--,r--;
            ll ans=0;
            for(int i=l;i<=r;i++){
                if(C[i]<=0) ans+=S[i];
            }
            cout<<ans<<endl;
        }
    }
    ll ans=0;
    cout<<ans<<endl;
    return 0;
}