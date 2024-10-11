#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    map<string, ll> mp;
    vector<string> C(N);
    rep(i, N) cin >> C[i];
    vector<string> D(M);
    vector<ll> P(M);
    ll P0;
    rep(i, M) cin >> D[i];
    cin >> P0;
    rep(i, M) cin >> P[i];
    rep(i, M) mp[D[i]] = P[i];

    ll sm = 0;
    rep(i, N){
        if (mp.find(C[i]) == mp.end()){
            sm += P0;
        } else {
            sm += mp[C[i]];
        }
    }
    
    cout << sm << endl;
    return 0;
}