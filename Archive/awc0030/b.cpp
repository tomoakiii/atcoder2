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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,int>> P(N);
    rep(i,N) cin>>P[i].first>>P[i].second;
    rep(i,M) {
        ll K; cin>>K;
        set<ll> v, m;
        rep(j,K) {
            int s; cin>>s; s--;
            if(P[s].second==0) v.insert(P[s].first);
            else m.insert(P[s].first);
        }
        if(v.empty() || m.empty()) cout<<-1<<endl;
        else cout<<(*v.begin()) + (*m.begin()) << endl;
    }
    return 0;
}