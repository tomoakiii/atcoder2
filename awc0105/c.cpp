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
<<<<<<< HEAD
    ll N; string S;
    cin >> N >> S;
    ll ans=0;
    auto getXOR = [](string S)->ll{
        ll p1=0;
        for(auto c:S){
            p1 = p1 ^ c;
        }
        return p1;
    };
    for(int k=1;k<=N-1;k++){
        string S1 = S.substr(0,k);
        string S2 = S.substr(k,N-k);
        ll p1 = getXOR(S1);
        ll p2 = getXOR(S2);
        ll D = INF;
        bool flg=true;
        rep(i,N){
            ll a = S[i];
            if(i<k) a^=p2;
            else a^=p1;
            ll dl = 97-a;
            ll dr = 122-a;
            if(dr < 0) {
                flg = false;
                break;
            }
            if(D<dl) {
                flg=false;
                break;
            }
            chmin(D,dr);
        }
        if(flg) {
            // cerr << S1 << " " << S2 << endl;
            ans++;
        }
    }
    cout<<ans<<endl;
=======
    ll N;
    cin >> N;
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