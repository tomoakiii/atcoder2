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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> H(N),B(M);
    rep(i,N) cin>>H[i];
    rep(i,M) cin>>B[i];
    sort(H.begin(),H.end());
    sort(B.begin(),B.end());
    int k = 0;
    int r = 0;
    rep(i,N) {
        while(r < M && B[r] < H[i]) r++;
        if(r == M) break;
        if(B[r] >= H[i]) {
            k++;
            r++;
        }
    }
    if(k >= K) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}