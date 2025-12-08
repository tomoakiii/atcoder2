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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector d2(N, vector<ll>(21));
    rep(i,N) {
        ll a = A[i];
        rep(j, 21) {
            d2[i][j] = a%2;
            a/=2;
        }
    }
    vector<ll> visit(21);
    ll ans = 0;
    auto add = [&](int i)->bool{
        bool flg = true;
        rep(j,21) {
            if(visit[j] && d2[i][j]) flg = false;
        }
        if(!flg) return false;
        rep(j,21) {
            if(d2[i][j]) visit[j] = true;
        }
        return true;
    };
    auto remv = [&](int i)->void{
        rep(j,21) {
            if(d2[i][j]) visit[j] = false;
        }
    };
    ll r = -1;
    rep(l,N) {
        if(l > 0) remv(l-1);
        if(l > r) {
            visit = d2[l];
            r = l;
        }
        while(r<N-1) {
            if(add(r+1)) r++;
            else break;
        }
        ans += r-l+1;
    }
    cout << ans << endl;
    return 0;
}