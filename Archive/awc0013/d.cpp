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
typedef pair<int,int> pii;
typedef pair<ll, pii> pll;
int main(){
    ll N, M;
    cin >> N >> M;
    vector A(M, vector<ll>(N));
    rep(i,N) rep(j,M) cin>>A[j][i];
    ll ans = 0;
    for(auto aa: A) {
        sort(aa.begin(),aa.end());
        auto B=aa, C=aa;
        rep(i,N-1) B[i+1]+=B[i];
        for(int i=N-1;i>0;i--) C[i-1]+=C[i];
        rep(i,N) {
            if(i>0) ans+=i*aa[i] - B[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}