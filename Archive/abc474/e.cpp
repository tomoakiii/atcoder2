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

void solve(){
    ll N; cin>>N;
    deque<pair<ll, pair<ll,ll>>> P(N);
    deque<pair<ll,ll>> P2(N);

    vector<ll> A(N),B(N),C(N);
    ll mna=INF;
    rep(i,N) {
        cin>>A[i]>>B[i];
        chmin(mna, A[i]);
    }
    rep(i,N) C[i] = A[i]-B[i];
    rep(i,N){
        P[i] = {C[i],{A[i],B[i]}};
        P2[i] = {A[i], B[i]};
    }
    sort(P.rbegin(),P.rend());

    bool flg = false;
    ll cp=0;
    ll ans = 0;
    while(!P.empty() && P.back().first<=0) {
        auto [a,b] = P.back().second;
        ans += a;
        if(a == mna) flg = true;
        P.pop_back();
        cp++;
    }
    while(!P.empty() && cp > 0 && P.front().first>0) {
        auto [a,b] = P.front().second;
        P.pop_front();
        ans += b;
        cp--;
        if(a == mna) flg = true;
    }
    ll sz = P.size();
    fenwick_tree<ll> FT1(sz), FT2(sz);
    rep(i,sz) {
        FT1.add(i, P[i].second.second); // by b
        FT2.add(i, P[i].second.first); // by a
    }
    ll fans = INF;
    rep(i,sz+1) {
        ll smb = FT1.sum(0,i);
        ll sma = 0;
        if(i<sz)sma = FT2.sum(i,sz);
        ll cpt = -i;
        cpt += sz - i;
        cpt *= -1;
        chmax(cpt,0ll);
        ll t = sma + smb + (mna * cpt);
        chmin(fans, t);
    }
    cout << ans + fans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    while(N--)solve();
    return 0;
}