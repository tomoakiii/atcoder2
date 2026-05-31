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
    ll N,K;
    cin>>N>>K;
    vector<ll> sc(N);
    rep(i,N) {
        rep(j,3) {
            ll p; cin>>p;
            sc[i]+=p;
        }
    }
    vector st = sc;
    sort(st.rbegin(), st.rend());
    int rk = 0, tie = 1;
    ll lst = INF, tgt;
    rep(i,N) {
        if(st[i] < lst) {
            rk+=tie;
            tie = 1;
        } else {
            tie++;
        }
        if(rk == K){
            tgt = st[i]; break;
        } else if (rk > K) {
            tgt = st[i]+1; break;
        }
        lst = st[i];
    }
    rep(i,N) {
        if(sc[i]+300 >= tgt) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}