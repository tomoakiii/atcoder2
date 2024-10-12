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
    vector<string> G(N);
    rep(i,N) cin>>G[i];
    
    rep(i, N/2) {
        vector<char> tmp(N*N);
        int ind = 0;
        for(int j = i; j < N-i; j++) for(int k = i; k < N-i; k++) {
            tmp[ind++] = G[j][k];
        }
        ind = 0;
        for(int j = i; j < N-i; j++) for(int k = i; k < N-i; k++) {
            G[k][N-1-j] = tmp[ind++];
        }
    }

    rep(i,N) cout<<G[i]<<endl;
    return 0;
}