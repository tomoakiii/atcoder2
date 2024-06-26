#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector A(N, vector<ll>{});
    ll a, b;
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    vector<ll> P(N);
    ll mxP = 0, mxi;
    map<ll, vector<ll>> mp;
    rep(i, K) {
        cin >> a >> b;
        a--;
        P[a] = b;
        mp[b].push_back(a);
        mxP = max(mxP, b);
    }
    vector D(N, vector<ll>{});
    auto que = mp[mxP];
    

    auto func = [&](auto func, ll from, ll dist){

    }
    rep(i, )

    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    
    cout << sm << endl;
    return 0;
}