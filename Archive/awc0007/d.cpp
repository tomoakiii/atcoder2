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
    ll N,A,B; cin>>N>>A>>B;
    vector G1(N+1, vector<ll>(N+1));
    auto G2=G1;
    rep(kkk,2) {
        rep(i,A) {
            ll a,b,c,d; cin>>a>>b>>c>>d;
            a--,b--;
            G1[a][b]++; G1[c][d]++;
            G1[a][d]--; G1[c][b]--;
        }
        rep(i,N+1) {
            rep(j,N) G1[i][j+1] += G1[i][j];
        }
        rep(j,N+1) {
            rep(i,N) G1[i+1][j] += G1[i][j];
        }
        swap(A,B); swap(G1,G2);
    }
    ll ans = 0;
    rep(i,N) rep(j,N) if(G1[i][j]>0 && G2[i][j]>0) ans++;
    cout<<ans<<endl;
    return 0;
}