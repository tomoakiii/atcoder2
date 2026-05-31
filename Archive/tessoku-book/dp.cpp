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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N,M; cin>>N>>M;
    vector<ll> score(N,M);
    rep(i,M) {
        int a; cin>>a; a--;
        score[a]--;
    }
    rep(i,N) cout<<score[i]<<endl;
    return 0;
}