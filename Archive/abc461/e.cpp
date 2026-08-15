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
    struct node{
        ll r, c, s;
    };
    ll N, Q;
    cin >> N >> Q;
    vector<int> lastr(N,0);
    vector<int> lastc(N,1);
    ll ans = 0;
    fenwick_tree<ll> FTr(Q+4), FTc(Q+4);
    FTr.add(0, N);
    FTc.add(1, N);
    int offs=2;
    rep(q,Q){
        int qn = offs + q;
        int type; ll x; cin>>type>>x; x--;
        if(type==1){
            ll sm = FTc.sum(lastr[x], qn);
            ans += sm;
            FTr.add(lastr[x], -1);
            FTr.add(qn, 1);
            lastr[x] = qn;
        } else {
            ll sm = FTr.sum(lastc[x], qn);
            ans -= sm;
            FTc.add(lastc[x], -1);
            FTc.add(qn, 1);
            lastc[x] = qn;
        }
        cout<<ans<<endl;
    }
    return 0;
}