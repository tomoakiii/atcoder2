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
    ll mn = INF;
    rep(i,1<<(N-1)) {
        ll st = A[0];
        vector<ll> v;
        rep(k,N-1) {
            if(i&1<<k) {
                v.push_back(st);
                st = A[k+1];
            } else {
                st |= A[k+1];
            }
        }
        v.push_back(st);
        ll t = 0;
        for(auto u:v) t^=u;
        chmin(mn,t);
    }
    cout<<mn<<endl;
    return 0;
}