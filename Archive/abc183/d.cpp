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
    ll N, W;
    cin >> N >> W;
    ll M = 200010;
    vector<ll> Cs(M);
    rep(i,N) {
        ll s,t,p;
        cin>>s>>t>>p;
        Cs[s] += p;
        Cs[t] -= p;
    }
    rep(i, M-1) {
        Cs[i+1] += Cs[i];
        if(Cs[i] > W) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}