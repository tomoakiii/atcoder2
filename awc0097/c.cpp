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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> ans(N,-1);
    vector<bool> ping(N,false);
    ping[0] = true;
    ans[0] = 0;
    rep(i,N-1) {
        if(A[i+1] < A[i]) {
            ans[i+1]=i;
        } else {
            ans[i+1]=i+1;
            ping[i+1]=true;
        }
    }
    rep(i,N) {
        if(ping[i]) cout<<0<<" \n"[i==N-1];
        else cout<<ans[i]+1<<" \n"[i==N-1];
    }
    return 0;
}