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
typedef  pair<int, int> pii;
int main(){
    ll N, Q;
    cin >> N;
    vector<ll> A(N);
    vector Apos(N+1, vector<int>{});
    rep(i,N) {
        cin>>A[i];
        Apos[A[i]].emplace_back(i);
    }
    cin >> Q;
    struct lrq{
        int l;
        int r;
        int q;
    };
    unordered_map<ll, vector<lrq>> Qr;
    rep(i,Q) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        lrq tmp;
        tmp.l = l;
        tmp.r = r;
        tmp.q = i;
        Qr[x].emplace_back(tmp);
    }
    vector<int> ans(Q);
    for(auto qr: Qr) {
        vector<int> sm(N, 0);
        int q = qr.first;
        for(auto a: Apos[q]) {
            sm[a] = 1;
        }
        rep(i, N-1) {
            sm[i+1] += sm[i];
        }
        for(auto tl : qr.second){
            if(tl.l > 0) ans[tl.q] = sm[tl.r] - sm[tl.l-1];
            else ans[tl.q] = sm[tl.r];
        }
    }
    rep(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}