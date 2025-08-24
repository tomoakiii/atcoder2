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
    ll N,M;
    cin >> N >> M;

    vector<string> S(N);    
    rep(i,N) cin>>S[i];
    vector<int> get1(M);
    rep(i,N) rep(j,M) {
        if(S[i][j] == '1') get1[j]++;
    }
    vector<ll> P(N);
    rep(i,N) rep(j,M) {
        if(S[i][j] == '1' && get1[j] <= N/2 ) P[i]++;
        else if (S[i][j] == '0' && get1[j] > N/2) P[i]++;
    }
    ll mx = 0;
    rep(i,N) chmax(mx, P[i]);
    rep(i,N) if(mx == P[i]) cout<<i+1<<endl;
    return 0;
}