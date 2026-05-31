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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> SM(N+1);
    rep(i,N) SM[i+1]=SM[i]+A[i];

    auto func = [&](int from, int to)->pair<ll,ll>{
        if(to-from==1){
            return {A[from],A[to]};
        }
        ll mn = INF;
        pair<ll,ll>ret;
        int l = from, r = to;
        while(r-l>1){
            ll c = (r+l)/2;
            if(c == to) {
                r=c;
                continue;
            }
            ll a = SM[c+1]-SM[from];
            ll b = SM[to+1]-SM[c+1];
            if(chmin(mn, abs(a-b))){
                ret = {a,b};
            }
            if(a<b) l=c;
            else r=c;   
        }
        ll a = SM[l+1]-SM[from];
        ll b = SM[to+1]-SM[l+1];
        if(chmin(mn, abs(a-b))){
            ret = {a,b};
        }
        return ret;
    };

    ll ans = INF;
    ll mn=INF;
    for(int i=1; i<N-2; i++) {
        auto [p,q] = func(0,i);
        auto [r,s] = func(i+1,N-1);
        vector<ll> PQ(4);
        PQ[0]=p,PQ[1]=q,PQ[2]=r,PQ[3]=s;
        sort(PQ.begin(),PQ.end());
        chmin(ans, PQ.back()-PQ[0]);
    }
    cout<<ans<<endl;
    return 0;
}