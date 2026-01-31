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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N,M; cin>>N>>M;
    vector<ll> coup(M);
    rep(i,M) {
        ll k = 0;
        rep(j,N) {
            ll a; cin>>a;
            k*=2;
            if(a==1) k++;
        }
        coup[i] = k;
    }
    vector<ll> sz(1<<N,INF);
    sz[0] = 0;
    int ans = INFi;
    auto func = [&](auto func, ll sm, int cur, int cnt)->void{
        // cerr << sm << " " << cur << " " << cnt << endl;
        if(sm+1 == 1<<N) {
            chmin(ans, cnt);
            return;
        }
        if(cur == M) return;
        ll sm2 = sm | coup[cur];
        func(func, sm, cur+1, cnt);
        if(sm2 != sm) if(sz[sm2] > cnt+1) {
            sz[sm2] = cnt+1;
            func(func, sm2, cur+1, cnt+1);
        }
    };
    func(func, 0, 0, 0);
    if(ans == INFi) cout<<-1<<endl;
    else cout << ans << endl;
    return 0;
}