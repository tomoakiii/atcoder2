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
    ll M = 100001;
    vector<ll> A(M);
    rep(i,N) {
        ll a; cin>>a;
        A[a]++;
    }

    ll ans = 0;
    rep(i,M){
        ans += A[i] * i;
    }

    int Q; cin>>Q;
    while(Q--){
        ll b,c; cin>>b>>c;
        ans -= A[b] * b;
        ans += A[b] * c;
        A[c] += A[b];
        A[b] = 0;
        cout<<ans<<endl;
    }

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
>>>>>>> 48f498569788a15edf75f47ebe405de0ad692429
    return 0;
}