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
    int R,C,K; cin>>R>>C>>K;
    vector<string> S(R);
    rep(i,R) cin>>S[i];
    vector T(R, vector<ll>(C+1));
    rep(i,R) rep(j,C) {
        if(S[i][j] == 'o') continue;
        for(int di = -(K-1); di <= K-1; di++) {
            int ny = i+di;
            if(ny<0 || ny>=R) continue;
            int dj = K-1-abs(di);
            int xl = j-dj, xr=j+dj;
            chmax(xl,0);
            chmin(xr,C-1);
            T[ny][xl]++;
            T[ny][xr+1]--;
        }
    }
    rep(i,R) rep(j,C) {
        T[i][j+1] += T[i][j];
    }
    ll ans = 0;
    for(int i=K-1; i<=R-K; i++) {
        for(int j=K-1; j<=C-K; j++) {
            cerr<<T[i][j] << " ";
            if(T[i][j]==0) ans++;
        }
        cerr<<endl;
    }
    cout << ans << endl;
    return 0;
}