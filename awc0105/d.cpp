<<<<<<< HEAD
//https://atcoder.jp/contests/awc0105/tasks/awc0105_d

=======
>>>>>>> 762c96cd907c5c0e9074087b1e61f9c27f58aeb4
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
    ll N;
    cin >> N;
<<<<<<< HEAD
    vector<pair<ll,ll>> PS(N);
    ll smr = 0;
    rep(i,N) {
        cin>>PS[i].second>>PS[i].first;
        smr += PS[i].second;
    }
    sort(PS.begin(),PS.end());
    auto get = [&](ll c)->ll{
        ll ret = 0;
        rep(i,N) {
            ret += PS[i].second * abs(PS[i].first-c);
        }
        return ret;
    };
    ll st = PS[0].first;
    ll ans = get(st);
    ll l = 0, r = ans;
    ll sm = 0;
    rep(i,N){
        ll d =  PS[i].first - st;
        l += d*sm;
        r -= d*smr;
        chmin(ans, l+r);
        sm += PS[i].second;
        smr -= PS[i].second;
        st = PS[i].first;
    }
    cout<<ans<<endl;
=======
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
>>>>>>> 762c96cd907c5c0e9074087b1e61f9c27f58aeb4
    return 0;
}