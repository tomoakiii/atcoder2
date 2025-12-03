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
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    ll M = 2E5+10;
    vector P(M, vector<pair<ll,ll>>{});
    rep(i,N) {
        P[A[i]].push_back({i, N-i-1});
    }
    ll ans = 0;
    rep(i,N){
        ans += (N-i)*((i+1)/2);
    }
    rep(i,M) {
        ll l = 0, r = P[i].size()-1;
        while(r>l) {
            if(P[i][l].first > P[i][r].second) {
                ans -= (P[i][r].second+1) * (r-l);
                r--;
            } else {
                ans -= (P[i][l].first+1) * (r-l);
                l++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}