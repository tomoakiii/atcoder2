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
    string S; cin>>S;
    int N = S.size();
    vector<int> nx(N);
    rep(i,N) {
        nx[i] = (S[i]=='R')?i+1:i-1;
    }
    rep(i,32) {
        vector<int> nnx(N);
        rep(i,N) {
            nnx[i] = nx[nx[i]];
        }
        swap(nx,nnx);
    }
    vector<ll> ans(N);
    rep(i,N) ans[nx[i]]++;
    rep(i,N) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}