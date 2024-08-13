#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector A(N, vector<vector<ll>>(N, vector<ll>(N, 0)));
    rep(i,N) rep(j,N) rep(k,N) cin >> A[i][j][k];
    vector SM = A;
    rep(k,N) rep(j,N) for(int i=1; i<N; i++) SM[i][j][k] += SM[i-1][j][k];
    rep(k,N) rep(i,N) for(int j=1; j<N; j++) SM[i][j][k] += SM[i][j-1][k];
    ll Q;
    cin>>Q;
    while(Q--){
        int li, ri, lj, rj, lk, rk;
        cin >> li >> ri >> lj >> rj >> lk >> rk;
        li--, ri--, lj--, rj--, lk--, rk--;
        ll ans = 0;
        for(int k = lk; k <= rk; k++) {            
            ll sm = SM[ri][rj][k];
            if (lj > 0) sm -= SM[ri][lj-1][k];
            if (li > 0) sm -= SM[li-1][rj][k];
            if (li > 0 && lj > 0) sm += SM[li-1][lj-1][k];
            ans+=sm;
        }
        cout<<ans<<endl;
    }
    return 0;
}