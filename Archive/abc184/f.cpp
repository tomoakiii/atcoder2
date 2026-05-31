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
    ll N,T;
    cin >> N >> T;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    if(N==1) {
        if(A[0] <= T) cout<<A[0]<<endl;
        else cout<<0<<endl;
        return 0;
    }
    ll N2 = N/2;
    vector<ll> S1, S2;
    S1.push_back(0);
    S2.push_back(0);
    ll ed;
    auto func = [&ed, &A](auto func, ll cur, ll sm, vector<ll> &v)->void{
        v.push_back(sm+A[cur]);
        if(cur == ed) {
            return;
        }
        func(func, cur+1, sm, v);
        func(func, cur+1, sm+A[cur], v);
    };
    ed = N2-1;
    func(func, 0, 0, S1);
    ed = N-1;
    func(func, N2, 0, S2);
    sort(S2.begin(), S2.end());
    ll sm = S2[S2.size()-1];
    ll ans = 0;
    for(auto s: S1) {
        if(s > T) continue;
        if(s + sm <= T) {
            chmax(ans, s+sm);
            continue;
        }
        ll ok = 0, ng = S2.size()-1;
        while(ng-ok > 1) {
            ll c = (ok+ng)/2;
            if(s + S2[c] <= T) ok = c;
            else ng = c;
        }
        chmax(ans, s + S2[ok]);
    }
    cout << ans << endl;
    return 0;
}