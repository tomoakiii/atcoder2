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
    ll N,K;
    cin >> N >> K;
    int N1 = N/2;
    int N2 = N-N1;
    unordered_set<ll> v1, v2;
    rep(kkk,2) {
        vector<pair<ll,ll>> A1(N);
        rep(i,N1) cin>>A1[i].first>>A1[i].second;
        ll full = 1;
        rep(i,N1) full *= 3;
        rep(S, full) {
            ll s = S;
            ll sm = 0;
            rep(i,N1) {
                if(s%3 == 2) sm += A1[i].second;
                else if (s%3 == 1) sm+=A1[i].first;
                s/=3;
            }
            v1.insert(sm);
        }
        swap(N1,N2);
        swap(v1,v2);
    }
    for(auto v:v1) {
        ll tgt = K-v;
        if(v2.contains(tgt)) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}