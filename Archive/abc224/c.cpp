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
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    
    auto comb = [&](ll a, ll b) ->ll{
        if(b==3) return a*(a-1)*(a-2)/6;
        else return a*(a-1)/2;
    };
    ll ans = comb(N, 3);
    rep(i,N){
        map<pair<ll,ll>, ll> mp;
        for(int j=i+1;j<N;j++) {
            ll dx = X[j]-X[i];
            ll dy = Y[j]-Y[i];
            if(dx==0) {
                mp[{0, 1}]++;
            } else if(dy==0){
                mp[{1, 0}]++;
            } else {
                ll g = gcd(dx,dy);
                if(dx<0) {
                    dx*=-1;
                    dy*=-1;
                }
                mp[{dx/g, dy/g}]++;
            }
        }
        for(auto m: mp) {
            if(m.second > 1) {
                ans -= comb(m.second, 2);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}