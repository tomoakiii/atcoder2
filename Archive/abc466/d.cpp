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

    ll N, M;
    cin >> N >> M;
    vector<set<ll>> R(N),C(N);

    rep(i,M) {
        int r,c;
        cin>>r>>c;
        r--, c--;
        R[r].clear();
        C[c].clear();
        R[r].insert(c);
        C[c].insert(r);
    }
    ll ans=0;
    rep(i,N){
        for(auto c:R[i]){
            if(C[c].contains(i)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}