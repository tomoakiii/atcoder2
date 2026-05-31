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
    ll N, M;
    cin >> N >> M;
    vector<ll> F(N),D(N);
    priority_queue<pair<ll,int>> que;
    rep(i,N) {
        cin>>F[i]>>D[i];
        que.push({F[i], i});
    }
    vector<ll> cnt(N);
    ll ans = 0;
    rep(k,M) {
        auto [q,i] = que.top();
        que.pop();
        ans+=q;
        cnt[i]++;
        ll nx = F[i]-cnt[i]*D[i];
        if(nx<0) nx=0;
        que.push({nx,i});
        //cerr<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}