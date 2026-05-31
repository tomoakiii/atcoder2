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
    ll N,M,S,T;
    cin >> N >> M >> S >> T;
    S--, T--;
    vector<ll> C(N);
    vector<int> ord(N);
    rep(i,N) ord[i]=i;
    swap(ord[0],ord[S]);
    swap(ord[N-1],ord[T]);
    rep(i,N) cin>>C[ord[i]];
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        u=ord[u]; v=ord[v];
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    ll sm=0, cnt=0;
    ll ful=1ll<<N;
    vector dp(ful, vector<ll>(N));
    vector dp2(ful, vector<ll>(N));
    vector visit(ful, vector<bool>(N));
    dp[1][0]=C[0];
    dp2[1][0]=1;
    visit[1][0]=true;
    rep(F,ful){
        rep(from,N) {
            if(!visit[F][from]) continue;
            for(auto to:uv[from]) {
                if(F>>to & 1) continue;
                ll S2=F|(1ll<<to);
                dp[S2][to] += dp[F][from] + dp2[F][from] * C[to];
                dp2[S2][to] += dp2[F][from];
                visit[S2][to]=true;
            }
        }
        if(F>>(N-1) & 1) {
            if(!visit[F][N-1]) continue;
            sm+=dp[F][N-1];
            cnt+=dp2[F][N-1];
        }
    }
    double ans = (double)sm / (double)cnt;
    cerr << sm << " " << cnt << endl;
    printf("%.20f\n", ans);
    return 0;
}